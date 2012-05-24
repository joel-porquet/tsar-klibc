/*
 * sys/sysmacros.h
 *
 * Constructs to create and pick apart dev_t.  The double-underscore
 * versions are macros so they can be used as constants.
 */

#ifndef _SYS_SYSMACROS_H
#define _SYS_SYSMACROS_H

#include <klibc/compiler.h>
#include <sys/types.h>

#define __major(__d) (((__d) >> 8) & 0xfff)
__static_inline int major(dev_t __d)
{
	return __major(__d);
}

#define __minor(__d) (((__d) & 0xff)|(((__d) >> 12) & 0xfff00))
__static_inline int minor(dev_t __d)
{
	return __minor(__d);
}

#define __makedev(__ma, __mi) \
	((((__ma) & 0xfff) << 8)|((__mi) & 0xff)|(((__mi) & 0xfff00) << 12))
__static_inline dev_t makedev(int __ma, int __mi)
{
	return __makedev(__ma, __mi);
}

#endif				/* _SYS_SYSMACROS_H */
