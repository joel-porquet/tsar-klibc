/*
 * fread.c
 */

#include <stdbool.h>
#include <string.h>
#include "stdioint.h"

size_t _fread(void *buf, size_t count, FILE *f)
{
	size_t bytes = 0;
	size_t nb;
	char *p = buf;
	char *rdptr;
	ssize_t rv;
	bool bypass;

	if (!count)
		return 0;

	if (f->flags & _IO_FILE_FLAG_WRITE)
		fflush(f);

	while (count) {
		while (f->bytes == 0) {
			/*
			 * The buffer is empty, we have to read
			 */
			bypass = (count >= f->bufsiz);
			if (bypass) {
				/* Large read, bypass buffer */
				rdptr = p;
				nb = count;
			} else {
				rdptr = f->buf + _IO_UNGET_SLOP;
				nb = f->bufsiz;
			}

			rv = read(f->fd, rdptr, nb);
			if (rv == -1) {
				if (errno == EINTR || errno == EAGAIN)
					continue;
				f->flags |= _IO_FILE_FLAG_ERR;
				return bytes;
			} else if (rv == 0) {
				f->flags |= _IO_FILE_FLAG_EOF;
				return bytes;


			}

			if (bypass) {
				p += rv;
				bytes += rv;
				count -= rv;
				f->filepos += rv;
			} else {
				f->bytes = rv;
				f->data = rdptr;
				f->flags |= _IO_FILE_FLAG_READ;
			}

			if (!count)
				return bytes;
		}

		/* If we get here, the buffer is non-empty */
		nb = f->bytes;
		nb = (count < nb) ? count : nb;
		if (nb) {
			memcpy(p, f->data, nb);
			p += nb;
			bytes += nb;
			count -= nb;
			f->data += nb;
			f->bytes -= nb;
			f->filepos += nb;
			if (!f->bytes)
				f->flags &= ~_IO_FILE_FLAG_READ;
		}
	}
	return bytes;
}
