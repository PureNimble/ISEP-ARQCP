.section .data

	.global A, B, C, D
	
.section .text

.global compute
compute:
	
	
	movl A(%rip), %eax
	movl D(%rip), %esi
	
	imull B(%rip), %eax
	subl  C(%rip), %eax
	
	cltd
	idivl %esi
	
	ret
