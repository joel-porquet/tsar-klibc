#include "stdioint.h"

int feof(FILE *f)
{
	return !!(f->flags & _IO_FILE_FLAG_EOF);
}
