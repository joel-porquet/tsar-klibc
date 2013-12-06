#ifndef _KLIBC_ARCHCONFIG_H
#define _KLIBC_ARCHCONFIG_H

/* we don't have the NR_fork syscall, so we have to specify we have a MMU anyway */
#define _KLIBC_NO_MMU 0

#endif /* _KLIBC_ARCHCONFIG_H */
