/*
 * ungetc.c
 */

#include "stdioint.h"

int ungetc(int c, FILE *f)
{
	if (f->flags & _IO_FILE_FLAG_WRITE || f->data <= f->buf)
		return EOF;

	*(--f->data) = c;
	f->bytes++;
	f->flags |= _IO_FILE_FLAG_READ;
	return c;
}
