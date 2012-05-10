/*
 * stddef.h
 */

#ifndef _STDDEF_H
#define _STDDEF_H

#ifndef __KLIBC__
# error "__KLIBC__ not defined, compiler invocation error!"
#endif

#include <bitsize/stddef.h>

#undef NULL
#ifdef __cplusplus
# define NULL 0
#else
# define NULL ((void *)0)
#endif

#undef offsetof
#define offsetof(t,m) ((size_t)&((t *)0)->m)

/*
 * The container_of construct: if p is a pointer to member m of
 * container class c, then return a pointer to the container of which
 * *p is a member.
 */
#undef container_of
#define container_of(p, c, m) ((c *)((char *)(p) - offsetof(c,m)))

#endif				/* _STDDEF_H */
