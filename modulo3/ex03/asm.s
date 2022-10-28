.section .data

	.global ptr1, ptr2

.section .text

.global str_copy_porto2
str_copy_porto2:
	leaq ptr2(%rip), %rax
	leaq ptr1(%rip), %rdx

str_loop:

	movb (%rdx), %cl
	cmpb $111, %cl
	je iso
	cmpb $117, %cl	
	je isu
	
	cmpb $79, %cl
	je isupo
	cmpb $85, %cl	
	je isupu
	
store:
	movb %cl, (%rax)
	
	cmpb $0, %cl
	jz str_loop_end
	
	incq %rax
	incq %rdx
	jmp str_loop
iso:
	movb $117, %cl
	jmp store
	
isu:
	movb $111, %cl
	jmp store
	
isupo:
	movb $85, %cl
	jmp store

isupu:
movb $79, %cl
	jmp store

	
str_loop_end:
	ret
