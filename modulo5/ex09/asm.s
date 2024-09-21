.section .data
	
	.equ A_OFFSET, 0			# the address starts at the byte 4
	.equ B_OFFSET, 8	
	.equ X_OFFSET, 16
	.equ Z_OFFSET, 20
	.equ C_OFFSET, 22
	.equ Y_OFFSET, 24
	.equ E_OFFSET, 28 
		
.section .text

	.global  fun1
	.global  fun2
	.global  fun3
	.global  fun4
	
#############################################	
fun1:

	#rdi = *s structB

	movw 4(%rdi),%ax
	
	ret					# return the value in eax
	
#############################################

#############################################	
fun2:

	#rdi = *s structB
	
	movw Z_OFFSET(%rdi),%ax
	
	
	ret					# return the value in eax
	
#############################################

#############################################	
fun3:

	#rdi = *s structB
	
	addq $Z_OFFSET,%rdi
	movq %rdi,%rax
	
	
	ret					# return the value in eax
	
#############################################

#############################################	
fun4:

	#rdi = *s structB
	
	movq B_OFFSET(%rdi),%rdi
	movw 4(%rdi),%ax
	
	
	ret					# return the value in eax
	
#############################################
