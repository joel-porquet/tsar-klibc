/*
 * kinit/kinit.h
 */

#ifndef KINIT_H
#define KINIT_H

#include <stddef.h>

void dump_args(int argc, char *argv[]);
int do_mounts(int argc, char *argv[]);
int mount_nfs_root(int argc, char *argv[], int flags);
char *get_arg(int argc, char *argv[], const char *name);
int ramdisk_load(int argc, char *argv[], dev_t root_dev);
void md_run(int argc, char *argv[]);

extern int mnt_procfs;
extern int mnt_sysfs;

extern int init_argc;
extern char **init_argv;
extern const char *progname;

int open_cloexec(const char *path, int flags, mode_t mode);
int getintfile(const char *path, long *val);
ssize_t readfile(const char *path, char **pptr);
ssize_t freadfile(FILE *f, char **pptr);

/*
 * min()/max() macros that also do
 * strict type-checking.. See the
 * "unnecessary" pointer comparison.
 * From the Linux kernel.
 */
#define min(x,y) ({ \
        typeof(x) _x = (x);     \
        typeof(y) _y = (y);     \
        (void) (&_x == &_y);            \
        _x < _y ? _x : _y; })

#define max(x,y) ({ \
        typeof(x) _x = (x);     \
        typeof(y) _y = (y);     \
        (void) (&_x == &_y);            \
        _x > _y ? _x : _y; })

#undef INI_DEBUG

#undef DEBUG
#ifdef INI_DEBUG
#define DEBUG(x) printf x
#else
#define DEBUG(x) do { } while (0)
#endif

#endif /* KINIT_H */
