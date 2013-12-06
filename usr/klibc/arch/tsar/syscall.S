#include <machine/asm.h>
#include <asm/unistd.h>

ENTRY(__syscall_common)
	syscall
	li	t0, -4096
	bltu	v0, t0, 1f
	/* if error, returns -1 and put -v0 in errno */
	negu	v0
	sw	v0, errno
	li	v0, -1
1:
	jr	ra
ENDPROC(__syscall_common)
