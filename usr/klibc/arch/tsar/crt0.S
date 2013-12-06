/*
 * Does arch-specific initializations and invokes __libc_init with the
 * appropriate arguments.
 */

#include <machine/asm.h>

ENTRY(__start)
	/* make room for a stackframe */
	subu	sp, 32
	sw	zero, 16(sp)

	/* initialize global pointer (_gp is defined in klibc.ld) */
	la	gp, _gp

	/* prepare arguments to __libc_init:
	 * - arg0 is a pointer on top of the stack (ie ELF entry structure)
	 * - arg1 is a pointer on atexit()
	 */
	addiu	a0, sp, 32
	move	a1, v0

	/* jump to first C function */
	jal	__libc_init
ENDPROC(__start)
