.section .data

	.global A, B, C, D;
	
.section .text

.global compute
compute:
	movl A(%rip), %eax
	movl B(%rip), %ebx
	movl C(%rip), %ecx
	movl D(%rip), %esi
	
	mull %ebx
	subl %ecx, %eax
	divl %esi
	
	
end:
	ret
