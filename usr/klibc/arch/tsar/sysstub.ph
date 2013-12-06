# -*- perl -*-
#
# Script to generate system call stubs
#

sub make_sysstub($$$$$@) {
	my($outputdir, $fname, $type, $sname, $stype, @args) = @_;

	open(OUT, '>', "${outputdir}/${fname}.S");
	print OUT "#include <machine/asm.h>\n";
	print OUT "#include <asm/unistd.h>\n";
	print OUT "\n";
	print OUT "ENTRY(${fname})\n";
	print OUT "\t.set push\n";
	print OUT "\t.set noreorder\n";
	print OUT "\tj\t__syscall_common\n";
	print OUT "\tli\tv0, __NR_${sname}\n";
	print OUT "\t.set pop\n";
	print OUT "ENDPROC(${fname})\n";
	close(OUT);
}

1;
