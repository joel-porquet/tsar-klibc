#include "stdioint.h"

off_t ftell(FILE *f)
{
	return f->filepos;
}
