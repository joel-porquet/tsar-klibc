/*
 * fxopen.c
 *
 * Common code between fopen(), fdopen() and the standard descriptors.
 */

#include "stdioint.h"

FILE *stdin, *stdout, *stderr;

/* Doubly-linked list of all stdio structures */
struct _IO_file __stdio_headnode =
{
	.prev = &__stdio_headnode,
	.next = &__stdio_headnode,
};

int __parse_open_mode(const char *mode)
{
	int rwflags = O_RDONLY;
	int crflags = 0;
	int eflag   = 0;

	while (*mode) {
		switch (*mode++) {
		case 'r':
			rwflags = O_RDONLY;
			crflags = 0;
			break;
		case 'w':
			rwflags = O_WRONLY;
			crflags = O_CREAT | O_TRUNC;
			break;
		case 'a':
			rwflags = O_WRONLY;
			crflags = O_CREAT | O_APPEND;
			break;
		case 'e':
			eflag = O_CLOEXEC;
			break;
		case '+':
			rwflags = O_RDWR;
			break;
		}
	}

	return rwflags | crflags | eflag;
}

FILE *__fxopen(int fd, int flags, int close_on_err)
{
	FILE *f = NULL;

	f = malloc(sizeof *f);
	if (!f)
		goto err;

	f->fd = fd;
	f->filepos = lseek(fd, 0, SEEK_CUR);

	f->buf = malloc(BUFSIZ + _IO_UNGET_SLOP);
	if (!f->buf)
		goto err;

	f->bufsiz = BUFSIZ;
	f->data = f->buf + _IO_UNGET_SLOP;
	f->bytes = 0;		/* No data in buffer */
	f->flags = isatty(fd) ? _IO_FILE_FLAG_LINE_BUF : 0;

	/* Insert into linked list */
	f->prev = &__stdio_headnode;
	f->next = __stdio_headnode.next;
	f->next->prev = f;
	__stdio_headnode.next = f;

	return f;

err:
	if (f) {
		free(f->buf);
		free(f);
	}
	if (close_on_err)
		close(fd);
	errno = ENOMEM;
	return NULL;
}

void __init_stdio(void)
{
	stdin  = __fxopen(0, O_RDONLY, 0);
	stdin->flags = _IO_FILE_FLAG_LINE_BUF;

	stdout = __fxopen(1, O_WRONLY|O_TRUNC, 0);
	stdout->flags = _IO_FILE_FLAG_LINE_BUF;

	stderr = __fxopen(2, O_WRONLY|O_TRUNC, 0);
	stderr->flags = _IO_FILE_FLAG_UNBUF;
}
