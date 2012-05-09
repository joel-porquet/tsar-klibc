/*
 * stdioint.h
 *
 * stdio internals
 */

#ifndef USR_KLIBC_STDIO_STDIOINT_H
#define USR_KLIBC_STDIO_STDIOINT_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

/* Actual FILE structure */
struct _IO_file {
	struct _IO_file *prev, *next;
	off_t filepos;		/* File position */
	char *buf;		/* Buffer */
	char *data;		/* Data in buffer */
	int bytes;		/* Data bytes in buffer */
	int bufsiz;		/* Total size of buffer */
	int fd;			/* Underlying file descriptor */
	int flags;		/* Error, end of file */
};

/* Assign this much extra to the input buffer in case of ungetc() */
#define _IO_UNGET_SLOP	32

__extern int __parse_open_mode(const char *mode);
__extern FILE *__fxopen(int fd, int flags, int close_on_err);

__extern struct _IO_file __stdio_headnode;

#endif /* USR_KLIBC_STDIO_STDIOINT_H */
