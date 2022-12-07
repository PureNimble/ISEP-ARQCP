.section .data
	
	.equ C_OFFSET, 0			# the address starts at the byte 4
	.equ W_OFFSET, 4		
	.equ J_OFFSET, 12	
.section .text

	.global  fill_s2
	
#############################################	
fill_s2:

	#rdi = *s pointer of the struct
	#rsi  = W vec[3] shorts
	#edx = J int
	#rcx  = C vec[3] char
	
	movb $3,%r8b			# start the loop index
	movq %rdi,%r9			# save the address in other register
char:
	cmpb $0,%r8b			# check for the end of the loop
	jz next				# move to the next loop
	
	movb (%rcx),%al			# move the char to a register
	movb %al,(%rdi)			# move the char to the struct
	
	incq %rdi				# next element of the struct
	incq %rcx				# next char in the array
	decb %r8b				# decrease the counter
	jmp char

next:
	movq %r9,%rdi			# move the saved pointer to rsi
	addq $W_OFFSET,%rdi		# go to the short vec[]
	
short:
	cmpb $3,%r8b			# check for the end of the loop
	je end				
		
	movw (%rsi),%ax			# move the short to a register
	movw %ax,(%rdi)			# move the short to the struct
	
	addq $2,%rdi			# next element of the struct
	addq $2,%rsi			# next char in the array
	incb %r8b				# decrease the counter
	jmp short
	
end:
	movl %edx,J_OFFSET(%r9)	
	ret					# return the value in eax
	
#############################################
