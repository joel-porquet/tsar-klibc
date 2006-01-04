VERSION := $(shell cat version)
SRCROOT = .

# kbuild compatibility
export srctree  := $(shell pwd)
export objtree  := $(shell pwd)
export KLIBCSRC := klibc
export KLIBCINC := include
export KLIBCOBJ := klibc
export KLIBCKERNELSRC := linux/
export KLIBCKERNELOBJ := linux/
include scripts/Kbuild.include

export CC      := gcc
NOSTDINC_FLAGS := -nostdlib -nostdinc -isystem $(shell $(CC) -print-file-name=include)

export ARCH := $(shell uname -m | sed -e s/i.86/i386/ -e s/parisc64/parisc/ -e s/sun4u/sparc64/ -e s/arm.*/arm/ -e s/sa110/arm/)

export HOSTCC     := gcc
export HOSTCFLAGS := -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer
export PERL       := perl

# Location for installation
export prefix      = /usr
export bindir      = $(prefix)/bin
export libdir      = $(prefix)/lib
export mandir      = $(prefix)/man
export INSTALLDIR  = $(prefix)/lib/klibc
export INSTALLROOT =

# Create a fake .config as present in the kernel tree
# But if it exists leave it alone
$(if $(wildcard $(objtree)/.config),,$(shell echo CONFIG_KLIBC=y > .config))

# Prefix Make commands with $(Q) to silence them
# Use quiet_cmd_xxx, cmd_xxx to create nice output
# use make V=1 to get verbose output

ifdef V
  ifeq ("$(origin V)", "command line")
    KBUILD_VERBOSE = $(V)
  endif
endif
ifndef KBUILD_VERBOSE
  KBUILD_VERBOSE = 0
endif

ifeq ($(KBUILD_VERBOSE),1)
  quiet =
  Q =
else
  quiet=quiet_
  Q = @
endif

# If the user is running make -s (silent mode), suppress echoing of
# commands

ifneq ($(findstring s,$(MAKEFLAGS)),)
  quiet=silent_
endif

export quiet Q KBUILD_VERBOSE

# Do not print "Entering directory ..."
MAKEFLAGS += --no-print-directory

# Shorthand to call Kbuild.klibc
klibc := -f $(srctree)/scripts/Kbuild.klibc obj

# Very first target
.PHONY: all klcc klibc
all: klcc klibc

rpmbuild = $(shell which rpmbuild 2>/dev/null || which rpm)

klibc.spec: klibc.spec.in version
	sed -e 's/@@VERSION@@/$(VERSION)/g' < $< > $@

.PHONY: rpm
rpm: klibc.spec
	+$(rpmbuild) -bb klibc.spec --target=$(ARCH)

# Build klcc - it is the first target
klcc:
	$(Q)$(MAKE) $(klibc)=klcc

klibc:
	$(Q)$(MAKE) $(klibc)=.

test: klibc
	$(Q)$(MAKE) $(klibc)=klibc/tests

###
# clean: remove generated files
# mrproper does a full cleaning including .config and linux symlink
FIND_IGNORE := \( -name .git \) -prune -o
quiet_cmd_rmfiles = $(if $(wildcard $(rm-files)),RM     $(wildcard $(rm-files)))
      cmd_rmfiles = rm -f $(rm-files)
clean:
	$(Q)$(MAKE) -f $(srctree)/scripts/Makefile.clean obj=.
	$(Q)find . $(FIND_IGNORE) \
		\( -name *.o -o -name *.a -o -name '.*.cmd' -o \
		   -name '.*.d' -o -name '.*.tmp' \) \
		-type f -print | xargs rm -f

rm-files := .config linux
distclean mrproper: clean
	 $(Q)find . $(FIND_IGNORE) \
		\( -name '*.orig' -o -name '*.rej' -o -name '*~' \
		-o -name '*.bak' -o -name '#*#' -o -name '.*.orig' \
		-o -name '.*.rej' -o -size 0 \
		-o -name '*%' -o -name '.*.cmd' -o -name 'core' \) \
		-type f -print | xargs rm -f
	$(call cmd,rmfiles)
											 

install: all
	$(Q)$(MAKE) -f $(srctree)/scripts/Kbuild.install obj=.

# This does all the prep work needed to turn a freshly exported git repository
# into a release tarball tree
release: klibc.spec
	rm -f maketar.sh
