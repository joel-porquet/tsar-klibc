#include "stdioint.h"

int fileno(FILE *f)
{
	return f->fd;
}
