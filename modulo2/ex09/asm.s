.section .data

	.global A, B, C, D
	
.section .text

.global sum_and_subtract
sum_and_subtract:
	movl A(%rip), %eax
	movw B(%rip), %si
	movb C(%rip), %cl
	movb D(%rip), %dl
	
	movslq %eax, %rax
	movswq %si, %rsi
	movsbq %cl, %rcx
	movsbq %dl, %rdx
	
	addq %rcx, %rax
	subq %rdx, %rax
	addq %rsi, %rax
	ret
