/*
 * fgetc.c
 */

#include "stdioint.h"

int fgetc(FILE *file)
{
	struct _IO_file_pvt *f = stdio_pvt(file);
	unsigned char ch;

	if (__likely(f->ibytes)) {
		ch = *f->data++;
		f->ibytes--;
		f->pub._io_filepos++;
	} else if (_fread(&ch, 1, file) != 1) {
		return EOF;
	}

	return (int)ch;
}
