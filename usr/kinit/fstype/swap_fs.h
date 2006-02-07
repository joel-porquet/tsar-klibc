#ifndef __LINUX_SWAP_FS_H
#define __LINUX_SWAP_FS_H

/* The basic structures of the swap super block */
#define SWAP_MAGIC_L		10
#define SWAP_RESERVED_L		(1024 - SWAP_MAGIC_L)
#define SWAP_MAGIC_1		"SWAP-SPACE"
#define SWAP_MAGIC_2		"SWAPSPACE2"
/* The superblock is the last block in the first page */
#define SWAP_OFFSET()		((getpagesize() - 1024) >> 10)

/* On-disk "super block" */
struct swap_super_block {
	char reserved[SWAP_RESERVED_L];
	char magic[SWAP_MAGIC_L];
};

#endif
