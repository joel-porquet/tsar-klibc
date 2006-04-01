/*
 * fstype.c, by rmk
 *
 * Detect filesystem type (on stdin) and output strings for two
 * environment variables:
 *  FSTYPE - filesystem type
 *  FSSIZE - filesystem size (if known)
 *
 * We currently detect (in order):
 *  gzip, cramfs, romfs, xfs, luks, lvm2, minix, ext3, ext2, reiserfs, jfs, swap
 *
 * MINIX, ext3 and Reiserfs bits are currently untested.
 */

#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <endian.h>
#include <netinet/in.h>
#include <sys/vfs.h>

#define cpu_to_be32(x) __cpu_to_be32(x)	/* Needed by romfs_fs.h */

#include "romfs_fs.h"
#include "cramfs_fs.h"
#include "minix_fs.h"
#include "ext2_fs.h"
#include "ext3_fs.h"
#include "xfs_sb.h"
#include "luks_fs.h"
#include "lvm2_sb.h"

/*
 * Slightly cleaned up version of jfs_superblock to
 * avoid pulling in other kernel header files.
 */
#include "jfs_superblock.h"

/*
 * reiserfs_fs.h is too sick to include directly.
 * Use a cleaned up version.
 */
#include "reiserfs_fs.h"

#include "fstype.h"

#define ARRAY_SIZE(x)	(sizeof(x) / sizeof(x[0]))

#define BLOCK_SIZE 1024

/* Swap needs the definition of block size */
#include "swap_fs.h"

static int gzip_image(const void *buf, unsigned long long *bytes)
{
	const unsigned char *p = buf;

	if (p[0] == 037 && (p[1] == 0213 || p[1] == 0236)) {
		/* The length of a gzip stream can only be determined
		   by processing the whole stream */
		*bytes = 0ULL;
		return 1;
	}
	return 0;
}

static int cramfs_image(const void *buf, unsigned long long *bytes)
{
	const struct cramfs_super *sb =
		(const struct cramfs_super *)buf;

	if (sb->magic == CRAMFS_MAGIC) {
		if (sb->flags & CRAMFS_FLAG_FSID_VERSION_2)
			*bytes = (unsigned long long)sb->fsid.blocks << 10;
		else
			*bytes = 0;
		return 1;
	}
	return 0;
}

static int romfs_image(const void *buf, unsigned long long *bytes)
{
        const struct romfs_super_block *sb =
		(const struct romfs_super_block *)buf;

	if (sb->word0 == ROMSB_WORD0 && sb->word1 == ROMSB_WORD1) {
		*bytes = __be32_to_cpu(sb->size);
		return 1;
	}
	return 0;
}

static int minix_image(const void *buf, unsigned long long *bytes)
{
	const struct minix_super_block *sb =
		(const struct minix_super_block *)buf;

	if (sb->s_magic == MINIX_SUPER_MAGIC ||
	    sb->s_magic == MINIX_SUPER_MAGIC2) {
		*bytes = (unsigned long long)sb->s_nzones
			<< (sb->s_log_zone_size+10);
		return 1;
	}
	return 0;
}

static int ext3_image(const void *buf, unsigned long long *bytes)
{
	const struct ext3_super_block *sb =
		(const struct ext3_super_block *)buf;

	if (sb->s_magic == __cpu_to_le16(EXT2_SUPER_MAGIC) &&
	    sb->s_feature_compat & __cpu_to_le32(EXT3_FEATURE_COMPAT_HAS_JOURNAL)) {
		*bytes = (unsigned long long)__le32_to_cpu(sb->s_blocks_count)
			<< (10+sb->s_log_block_size);
		return 1;
	}
	return 0;
}

static int ext2_image(const void *buf, unsigned long long *bytes)
{
	const struct ext2_super_block *sb =
		(const struct ext2_super_block *)buf;

	if (sb->s_magic == __cpu_to_le16(EXT2_SUPER_MAGIC)) {
		*bytes = (unsigned long long)__le32_to_cpu(sb->s_blocks_count)
			<< (10+sb->s_log_block_size);
		return 1;
	}
	return 0;
}

static int reiserfs_image(const void *buf, unsigned long long *bytes)
{
	const struct reiserfs_super_block *sb =
		(const struct reiserfs_super_block *)buf;

	if (memcmp(REISERFS_MAGIC(sb), REISERFS_SUPER_MAGIC_STRING,
		   sizeof(REISERFS_SUPER_MAGIC_STRING) - 1) == 0 ||
	    memcmp(REISERFS_MAGIC(sb), REISER2FS_SUPER_MAGIC_STRING,
		   sizeof(REISER2FS_SUPER_MAGIC_STRING) - 1) == 0 ||
	    memcmp(REISERFS_MAGIC(sb), REISER2FS_JR_SUPER_MAGIC_STRING,
		   sizeof(REISER2FS_JR_SUPER_MAGIC_STRING) - 1) == 0) {
		*bytes = (unsigned long long)REISERFS_BLOCK_COUNT(sb) *
			REISERFS_BLOCKSIZE(sb);
		return 1;
	}
	return 0;
}

static int xfs_image(const void *buf, unsigned long long *bytes)
{
	const struct xfs_sb *sb =
		(const struct xfs_sb *)buf;

	if (__be32_to_cpu(sb->sb_magicnum) == XFS_SB_MAGIC) {
		*bytes = __be64_to_cpu(sb->sb_dblocks) *
			__be32_to_cpu(sb->sb_blocksize);
		return 1;
	}
	return 0;
}

static int jfs_image(const void *buf, unsigned long long *bytes)
{
	const struct jfs_superblock *sb =
		(const struct jfs_superblock *)buf;

	if (!memcmp(sb->s_magic, JFS_MAGIC, 4)) {
		*bytes = __le32_to_cpu(sb->s_size);
		return 1;
	}
	return 0;
}

static int luks_image(const void *buf, unsigned long long *blocks)
{
	const struct luks_partition_header *lph =
		(const struct luks_partition_header *)buf;

	if (!memcmp(lph->magic, LUKS_MAGIC, LUKS_MAGIC_L)) {
		/* FSSIZE is dictated by the underlying fs, not by LUKS */
		*blocks = 0;
		return 1;
	}
	return 0;
}

static int swap_image(const void *buf, unsigned long long *blocks)
{
	const struct swap_super_block *ssb =
		(const struct swap_super_block *)buf;

	if (!memcmp(ssb->magic, SWAP_MAGIC_1, SWAP_MAGIC_L) ||
	    !memcmp(ssb->magic, SWAP_MAGIC_2, SWAP_MAGIC_L)) {
		*blocks = 0;
		return 1;
	}
	return 0;
}

static int lvm2_image(const void *buf, unsigned long long *blocks)
{
	const struct lvm2_super_block *lsb;
	int i;

	/* We must check every 512 byte sector */
	for (i = 0; i < BLOCK_SIZE; i += 0x200) {
		lsb = (const struct lvm2_super_block *)(buf + i);

		if (!memcmp(lsb->magic, LVM2_MAGIC, LVM2_MAGIC_L) &&
		    !memcmp(lsb->type,  LVM2_TYPE,  LVM2_TYPE_L)) {
			/* This is just one of possibly many PV's */
			*blocks = 0;
			return 1;
		}
	}

	return 0;
}

struct imagetype {
	off_t		block;
	const char	name[12];
	int		(*identify)(const void *, unsigned long long *);
};

/*
 * Note:
 * Minix test needs to come after ext3/ext2, since it's possible for
 * ext3/ext2 to look like minix by pure random chance.
 */
static struct imagetype images[] = {
	{ 0,		"gzip",		gzip_image	},
	{ 0,		"cramfs",	cramfs_image	},
	{ 0,		"romfs",	romfs_image	},
	{ 0,		"xfs",		xfs_image	},
	{ 0,		"luks",		luks_image	},
	{ 0,		"lvm2",		lvm2_image	},
	{ 1,		"lvm2",		lvm2_image	},
	{ 1,		"ext3",		ext3_image	},
	{ 1,		"ext2",		ext2_image	},
	{ 1,		"minix",	minix_image	},
	{ 8,		"reiserfs",	reiserfs_image	},
	{ 64,		"reiserfs",	reiserfs_image	},
	{ 32,		"jfs",		jfs_image	},
	{ -1,		"swap",		swap_image	},
	{ 0,		"",		NULL 		}
};

int identify_fs(int fd, const char **fstype,
		unsigned long long *bytes, off_t offset)
{
	uint64_t buf[BLOCK_SIZE>>3]; /* 64-bit worst case alignment */
	off_t cur_block = (off_t)-1;
	struct imagetype *ip;
	int ret;

	*fstype = NULL;
	*bytes = 0;

	for (ip = images; ip->identify; ip++) {
		/* Hack for swap, which apparently is dependent on page size */
		if (ip->block == -1)
			ip->block = SWAP_OFFSET();

		if (cur_block != ip->block) {
			/*
			 * Read block.
			 */
			cur_block = ip->block;
			ret = pread(fd, buf, BLOCK_SIZE,
				    offset+cur_block*BLOCK_SIZE);
			if (ret != BLOCK_SIZE)
				return -1; /* error */
		}

		if (ip->identify(buf, bytes)) {
			*fstype = ip->name;
			return 0;
		}
	}

	return 1;		/* Unknown filesystem */
}
