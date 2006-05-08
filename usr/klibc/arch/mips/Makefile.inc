# -*- makefile -*-
#
# arch/mips/Makefile.inc
#
# Special rules for this architecture.  Note that this is actually
# included from the main Makefile, and that pathnames should be
# accordingly.
#

KLIBCARCHOBJS = \
	arch/$(KLIBCARCH)/pipe.o \
	arch/$(KLIBCARCH)/vfork.o \
	arch/$(KLIBCARCH)/setjmp.o \
	arch/$(KLIBCARCH)/syscall.o \
	libgcc/__clzsi2.o \
	libgcc/__clzdi2.o \
	libgcc/__ashldi3.o \
	libgcc/__ashrdi3.o \
	libgcc/__lshrdi3.o \
	libgcc/__divdi3.o \
        libgcc/__moddi3.o \
        libgcc/__udivdi3.o \
	libgcc/__umoddi3.o \
        libgcc/__udivmoddi4.o


KLIBCARCHSOOBJS = $(patsubst %.o,%.lo,$(KLIBCARCHOBJS))


archclean: