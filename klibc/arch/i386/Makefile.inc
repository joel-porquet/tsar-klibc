# -*- makefile -*-
#
# arch/i386/Makefile
#
# Special rules for this architecture.  Note that this is actually
# included from the main Makefile, and that pathnames should be
# accordingly.
#

OPTFLAGS = -march=i386 -mcpu=i686 -Os -fomit-frame-pointer \
	   -malign-functions=0 -malign-jumps=0 -malign-loops=0
BITSIZE  = 32

archclean: