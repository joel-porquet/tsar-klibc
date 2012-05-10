/*
 * fxopen.c
 *
 * Common code between fopen(), fdopen() and the standard descriptors.
 */

#include "stdioint.h"

FILE *stdin, *stdout, *stderr;

/* Doubly-linked list of all stdio structures */
struct _IO_file_pvt __stdio_headnode =
{
	.prev = &__stdio_headnode,
	.next = &__stdio_headnode,
};

FILE *__fxopen(int fd, int flags, bool close_on_err)
{
	struct _IO_file_pvt *f;
	const size_t bufoffs =
		(sizeof *f + 4*sizeof(void *) - 1) &
		~(4*sizeof(void *) - 1);

	f = zalloc(bufoffs + BUFSIZ + _IO_UNGET_SLOP);
	if (!f)
		goto err;

	f->data = f->buf = (char *)f + bufoffs;
	f->pub._io_fileno = fd;
	f->pub._io_filepos = lseek(fd, 0, SEEK_CUR);
	f->bufsiz = BUFSIZ;
	f->data = f->buf + _IO_UNGET_SLOP;
	f->bufmode = isatty(fd) ? _IOLBF : _IONBF;

	/* Insert into linked list */
	f->prev = &__stdio_headnode;
	f->next = __stdio_headnode.next;
	f->next->prev = f;
	__stdio_headnode.next = f;

	return &f->pub;

err:
	if (f)
		free(f);
	if (close_on_err)
		close(fd);
	errno = ENOMEM;
	return NULL;
}

void __init_stdio(void)
{
	stdin  = __fxopen(0, O_RDONLY, 0);
	stdio_pvt(stdin)->bufmode = _IOLBF;

	stdout = __fxopen(1, O_WRONLY|O_TRUNC, 0);
	stdio_pvt(stdout)->bufmode = _IOLBF;

	stderr = __fxopen(2, O_WRONLY|O_TRUNC, 0);
	stdio_pvt(stderr)->bufmode = _IONBF;
}
