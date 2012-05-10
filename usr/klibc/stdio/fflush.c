/*
 * fflush.c
 */

#include "stdioint.h"

int __fflush(struct _IO_file_pvt *f)
{
	ssize_t rv;
	char *p;

	if (!f->obytes)
		return 0;

	p = f->buf;
	while (f->obytes) {
		rv = write(f->pub._io_fileno, p, f->obytes);
		if (rv == -1) {
			if (errno == EINTR || errno == EAGAIN)
				continue;
			f->pub._io_error = true;
			return EOF;
		} else if (rv == 0) {
			/* EOF on output? */
			f->pub._io_eof = true;
			return EOF;
		}

		p += rv;
		f->obytes -= rv;
	}

	return 0;
}

int fflush(FILE *file)
{
	struct _IO_file_pvt *f;

	if (__likely(file)) {
		f = stdio_pvt(file);
		return __fflush(f);
	} else {
		int err = 0;

		for (f = __stdio_headnode.next; f != &__stdio_headnode;
		     f = f->next)
			err |= __fflush(f);
		return err;
	}
}


