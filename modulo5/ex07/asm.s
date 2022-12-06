.section .data
	
	.equ C_OFFSET, 0			# the address starts at the byte 4
	.equ I_OFFSET, 4	
	.equ D_OFFSET, 8	
	.equ J_OFFSET, 12	
.section .text

	.global  fill_s1
	
#############################################	
fill_s1:

	#rdi = *s pointer of the struct
	#esi = I
	#dl  = C
	#ecx = J
	#r8b = D
	
	
	movb %dl,C_OFFSET(%rdi)
	movl %esi,I_OFFSET(%rdi)
	movb %r8b,D_OFFSET(%rdi)
	movl %ecx,J_OFFSET(%rdi)

	ret					# return the value in eax
	
#############################################
