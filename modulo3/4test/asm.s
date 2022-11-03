.section .data

	.global ptrvec

.section .text

.global vec_add_two
vec_add_two:
	leaq ptrvec(%rip), %rax
	movl $15, %ecx
str_loop:
	addq $2, (%rax)
	addq $4, %rax
	loop str_loop
	
	ret
