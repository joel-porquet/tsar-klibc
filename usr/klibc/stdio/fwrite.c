/*
 * fwrite.c
 */

#include <string.h>
#include "stdioint.h"

static size_t fwrite_noflush(const void *buf, size_t count, FILE *f)
{
	size_t bytes = 0;
	size_t nb;
	const char *p = buf;
	ssize_t rv;

	while (count) {
		if (f->bytes == 0 && count >= f->bufsiz) {
			/*
			 * The buffer is empty and the write is large,
			 * so bypass the buffering entirely.
			 */
			rv = write(f->fd, p, count);
			if (rv == -1) {
				if (errno == EINTR || errno == EAGAIN)
					continue;
				f->flags |= _IO_FILE_FLAG_ERR;
				break;
			} else if (rv == 0) {
				/* EOF on output? */
				f->flags |= _IO_FILE_FLAG_EOF;
				break;
			}

			p += rv;
			bytes += rv;
			count -= rv;
			f->filepos += rv;
		} else {
			nb = f->bufsiz - f->bytes;
			nb = (count < nb) ? count : nb;
			if (nb) {
				memcpy(f->buf+f->bytes, p, nb);
				p += nb;
				f->bytes += nb;
				count -= nb;
				bytes += nb;
				f->filepos += nb;
				f->flags |= _IO_FILE_FLAG_WRITE;
			}

			if (!count)
				break;	/* Done... */

			/* If we get here, the buffer must be full */
			if (fflush(f))
				break;
		}
	}
	return bytes;
}

size_t _fwrite(const void *buf, size_t count, FILE *f)
{
	size_t bytes = 0;
	size_t pf_len, pu_len;
	const char *p = buf;

	/* We divide the data into two chunks, flushed (pf)
	   and unflushed (pu) depending on buffering mode
	   and contents. */

	if (f->flags & _IO_FILE_FLAG_UNBUF) {
		pf_len = 0;
		pu_len = count;
	} else if (f->flags & _IO_FILE_FLAG_LINE_BUF) {
		pf_len = count;
		pu_len = 0;

		while (pf_len && p[pf_len-1] != '\n') {
			pf_len--;
			pu_len++;
		}
	} else {
		pf_len = 0;
		pu_len = count;
	}

	if (pf_len) {
		bytes = fwrite_noflush(p, pf_len, f);
		p += bytes;
		if (fflush(f) || bytes != pf_len)
			return bytes;
	}

	if (pu_len)
		bytes += fwrite_noflush(p, pu_len, f);

	return bytes;
}
