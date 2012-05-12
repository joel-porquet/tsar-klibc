#include <stdio.h>

void rewind(FILE *f)
{
	if (!fseek(f, 0, SEEK_SET))
		clearerr(f);
}
