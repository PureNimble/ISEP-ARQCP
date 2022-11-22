.section .data
	
.section .text

	.global sum_multiples_x

#######################################################	
sum_multiples_x:

	# %rdi = *vec
	# %esi = x

	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------

	shrl $8,%esi			# move 2byte to the 1byte
	movl $0,%ecx			# sum = 0
	
loop:

	cmpb $0,(%rdi)			# check for the end of vec
	je end
	
	movw (%rdi),%ax			# put the number in %ax
	cbw						# Conversion instruction
	idiv %sil				# %ax / %sil the rest goes to %ah
	
	cmpb $0,%ah				# Check if had any rest
	jne next				
	addb (%rdi),%cl			# sum the number with no rest
next:
	incq %rdi			   	# move to the next number
	jmp loop				# loop
	
end:
	movl %ecx,%eax			# return the sum
#------------------------------------------------------
	
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	
