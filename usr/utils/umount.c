/*
 * by rmk
 */
#include <sys/mount.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *progname;

int main(int argc, char *argv[])
{
	int c, flag = 0;

	progname = argv[0];

	do {
		c = getopt(argc, argv, "f");
		if (c == EOF)
			break;
		switch (c) {
		case 'f':
			flag |= MNT_FORCE;
			break;
		case '?':
			fprintf(stderr, "%s: invalid option -%c\n",
				progname, optopt);
			exit(1);
		}
	} while (1);

	if (optind + 1 != argc) {
		fprintf(stderr, "Usage: %s [-f] mntpoint\n", progname);
		return 1;
	}

	if (umount2(argv[optind], flag) == -1) {
		perror("umount2");
		return 255;
	}

	return 0;
}
