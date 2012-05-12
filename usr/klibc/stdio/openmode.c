/*
 * openmode.c
 *
 * Parse the mode argument to fopen() or fdopen()
 */

#include "stdioint.h"

int __parse_open_mode(const char *mode)
{
	int rwflags = O_RDONLY;
	int crflags = 0;
	int eflags  = 0;

	while (*mode) {
		switch (*mode++) {
		case 'r':
			rwflags = O_RDONLY;
			crflags = 0;
			break;
		case 'w':
			rwflags = O_WRONLY;
			crflags = O_CREAT | O_TRUNC;
			break;
		case 'a':
			rwflags = O_WRONLY;
			crflags = O_CREAT | O_APPEND;
			break;
		case 'e':
			eflags |= O_CLOEXEC;
			break;
		case 'x':
			eflags |= O_EXCL;
			break;
		case '+':
			rwflags = O_RDWR;
			break;
		}
	}

	return rwflags | crflags | eflags;
}
