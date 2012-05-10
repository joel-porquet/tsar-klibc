/*
 * fseek.c
 */

#include "stdioint.h"

__extern int fseek(FILE *file, off_t where, int whence)
{
	struct _IO_file_pvt *f = stdio_pvt(file);
	off_t rv;

	if (f->obytes)
		__fflush(f);

	if (whence == SEEK_CUR) {
		where += f->pub._io_filepos;
		whence = SEEK_SET;
	}

	rv = lseek(f->pub._io_fileno, where, whence);
	if (rv != -1) {
		f->pub._io_filepos = rv;
		f->ibytes = 0;
		f->obytes = 0;
		f->data = f->buf + _IO_UNGET_SLOP;
		return 0;
	} else {
		return -1;
	}
}
