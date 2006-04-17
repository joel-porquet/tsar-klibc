#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <alloca.h>
#include <inttypes.h>

#include "do_mounts.h"
#include "kinit.h"
#include "fstype.h"
#include "zlib.h"

#define BUF_SZ		65536

/* Find dev_t for e.g. "hda,NULL" or "hdb,2" */
static dev_t
try_name(char *name, int part)
{
	char path[BUF_SZ];
	char buf[BUF_SZ];
	int range;
	unsigned int major, minor;
	dev_t res;
	char *s;
	int len;
	int fd;

	/* read device number from /sys/block/.../dev */
	snprintf(path, sizeof(path), "/sys/block/%s/dev", name);
	fd = open(path, 0, 0);
	if (fd < 0)
		goto fail;
	len = read(fd, buf, BUF_SZ);
	close(fd);

	if (len <= 0 || len == BUF_SZ || buf[len - 1] != '\n')
		goto fail;
	buf[len - 1] = '\0';
	major = strtoul(buf, &s, 10);
	if (*s != ':')
		goto fail;
	minor = strtoul(s+1, &s, 10);
	if (*s)
		goto fail;
	res = makedev(major, minor);

	/* if it's there and we are not looking for a partition - that's it */
	if (!part)
		return res;

	/* otherwise read range from .../range */
	snprintf(path, sizeof(path), "/sys/block/%s/range", name);
	fd = open(path, 0, 0);
	if (fd < 0)
		goto fail;
	len = read(fd, buf, 32);
	close(fd);
	if (len <= 0 || len == 32 || buf[len - 1] != '\n')
		goto fail;
	buf[len - 1] = '\0';
	range = strtoul(buf, &s, 10);
	if (*s)
		goto fail;

	/* if partition is within range - we got it */
	if (part < range) {
		DEBUG(("kinit: try_name %s,%d = %s\n", name, part,
		       bdevname(res+part)));
		return res + part;
	}

fail:
	return (dev_t) 0;
}

/*
 *	Convert a name into device number.  We accept the following variants:
 *
 *	1) device number in hexadecimal	represents itself
 *	2) /dev/nfs represents Root_NFS
 *	3) /dev/<disk_name> represents the device number of disk
 *	4) /dev/<disk_name><decimal> represents the device number
 *         of partition - device number of disk plus the partition number
 *	5) /dev/<disk_name>p<decimal> - same as the above, that form is
 *	   used when disk name of partitioned disk ends on a digit.
 *	6) an actual block device node in the initramfs filesystem
 *
 *	If name doesn't have fall into the categories above, we return 0.
 *	Driverfs is used to check if something is a disk name - it has
 *	all known disks under bus/block/devices.  If the disk name
 *	contains slashes, name of driverfs node has them replaced with
 *	dots.  try_name() does the actual checks, assuming that driverfs
 *	is mounted on rootfs /sys.
 */

static inline dev_t
name_to_dev_t_real(const char *name)
{
	char *p;
	dev_t res = 0;
	char *s;
	int part;
	struct stat st;
	int len;
	const char *devname;

	if ( name[0] == '/' )
		devname = name;
	else {
		char *dname = alloca(strlen(name) + 6);
		sprintf(dname, "/dev/%s", name);
		devname = dname;
	}

	if (!stat(devname, &st) && S_ISBLK(st.st_mode))
		return st.st_rdev;

	if (strncmp(name, "/dev/", 5)) {
		res = (dev_t) strtoul(name, &p, 16);
		if (!*p)
			return res;
	} else {
		name += 5;
	}

	if (!strcmp(name, "nfs"))
		return Root_NFS;

	if (!strncmp(name, "mtd", 3))
		return Root_MTD;

	len = strlen(name);
	s = alloca(len+1);
	memcpy(s, name, len+1);

	for (p = s; *p; p++)
		if (*p == '/')
			*p = '.';
	res = try_name(s, 0);
	if (res)
		return res;

	while (p > s && isdigit(p[-1]))
		p--;
	if (p == s || !*p || *p == '0')
		goto fail;
	part = strtoul(p, NULL, 10);
	*p = '\0';
	res = try_name(s, part);
	if (res)
		return res;

	if (p < s + 2 || !isdigit(p[-2]) || p[-1] != 'p')
		goto fail;
	p[-1] = '\0';
	res = try_name(s, part);
	return res;

 fail:
	return (dev_t)0;
}

dev_t
name_to_dev_t(const char *name)
{
	dev_t dev = name_to_dev_t_real(name);

	DEBUG(("kinit: name_to_dev_t(%s) = %s\n", name, bdevname(dev)));
	return dev;
}

/* Create the device node "name" */
int
create_dev(const char *name, dev_t dev)
{
	unlink(name);
	return mknod(name, S_IFBLK|0600, dev);
}

/* mount a filesystem, possibly trying a set of different types */
const char *
mount_block(const char *source, const char *target,
	    const char *type, unsigned long flags,
	    const void *data)
{
	char *fslist, *p, *ep;
	const char *rp;
	ssize_t fsbytes;

	if ( type ) {
		DEBUG(("kinit: trying to mount %s on %s with type %s\n",
		       source, target, type));
		int rv = mount(source, target, type, flags, data);
		/* Mount readonly if necessary */
		if ( rv == -1 && errno == EACCES && !(flags & MS_RDONLY) )
			rv = mount(source, target, type, flags|MS_RDONLY, data);
		return rv ? NULL : type;
	}

	fsbytes = readfile("/proc/filesystems", &fslist);

	errno = EINVAL;
	if ( fsbytes < 0 )
		return NULL;

	p = fslist;
	ep = fslist+fsbytes;

	rp = NULL;

	while ( p < ep ) {
		type = p;
		p = strchr(p, '\n');
		if (!p)
			break;
		*p++ = '\0';
		if (*type != '\t')/* We can't mount a block device as a "nodev" fs */
			continue;

		type++;
		rp = mount_block(source, target, type, flags, data);
		if ( rp )
			break;
		if ( errno != EINVAL )
			break;
	}

	free(fslist);
	return rp;
}

/* mount the root filesystem from a block device */
static int
mount_block_root(int argc, char *argv[], dev_t root_dev,
		 const char *type, unsigned long flags)
{
	const char *data, *rp;

	data = get_arg(argc, argv, "rootflags=");
	create_dev("/dev/root", root_dev);

	errno = 0;

	if ( type ) {
		if ( (rp = mount_block("/dev/root", "/root", type, flags, data)) )
			goto ok;
		if ( errno != EINVAL )
			goto bad;
	}

	if ( !errno && (rp = mount_block("/dev/root", "/root", NULL, flags, data)) )
		goto ok;

 bad:
	if ( errno != EINVAL ) {
	        /*
		 * Allow the user to distinguish between failed open
		 * and bad superblock on root device.
		 */
		fprintf(stderr, "%s: Cannot open root device %s\n",
			progname, bdevname(root_dev));
		return -errno;
	} else {
		fprintf(stderr, "%s: Unable to mount root fs on device %s\n",
			progname, bdevname(root_dev));
		return -ESRCH;
	}

ok:
	printf("%s: Mounted root (%s filesystem)%s.\n",
	       progname, rp, (flags & MS_RDONLY) ? " readonly" : "");
	return 0;
}

int
mount_root(int argc, char *argv[], dev_t root_dev, const char *root_dev_name)
{
	unsigned long flags = MS_RDONLY|MS_VERBOSE;
	int ret;
	const char *type = get_arg(argc, argv, "rootfstype=");

	if (get_flag(argc, argv, "rw")) {
		DEBUG(("kinit: rw flag specified\n"));
		flags &= ~MS_RDONLY;
	}

	if (type) {
		if (!strcmp(type, "nfs"))
			root_dev = Root_NFS;
		else if (!strcmp(type, "jffs2") && !major(root_dev))
			root_dev = Root_MTD;
	}

	switch (root_dev) {
	case Root_NFS:
		ret = mount_nfs_root(argc, argv, flags);
		break;
	case Root_MTD:
		ret = mount_mtd_root(argc, argv, root_dev_name, type, flags);
		break;
	default:
		ret = mount_block_root(argc, argv, root_dev, type, flags);
		break;
	}

	if (!ret)
		chdir("/root");

	return ret;
}

int do_mounts(int argc, char *argv[])
{
	const char *root_dev_name = get_arg(argc, argv, "root=");
	const char *root_delay = get_arg(argc, argv, "rootdelay=");
	const char *load_ramdisk = get_arg(argc, argv, "load_ramdisk=");
	dev_t root_dev = 0;

	DEBUG(("kinit: do_mounts\n"));

	if (root_delay) {
		int delay = atoi(root_delay);
		fprintf(stderr, "Waiting %d s before mounting root device...\n", delay);
		sleep(delay);
	}

	md_run(argc, argv);

	if (root_dev_name) {
		root_dev = name_to_dev_t(root_dev_name);
	} else if (get_arg(argc, argv, "nfsroot=") ||
		   get_arg(argc, argv, "nfsaddrs=")) {
		root_dev = Root_NFS;
	}

	DEBUG(("kinit: root_dev = %s\n", bdevname(root_dev)));

	if ( initrd_load(argc, argv, root_dev) ) {
		DEBUG(("initrd loaded\n"));
		return 0;
	}

	if ( load_ramdisk && atoi(load_ramdisk) ) {
		if (ramdisk_load(argc, argv, root_dev))
			root_dev = Root_RAM0;
	}

	return mount_root(argc, argv, root_dev, root_dev_name);
}
