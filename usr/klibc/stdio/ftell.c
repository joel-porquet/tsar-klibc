#define __NO_STDIO_INLINES
#include "stdioint.h"

off_t ftell(FILE *f)
{
	return f->_IO_filepos;
}
