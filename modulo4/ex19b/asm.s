.section .data
	
.section .text

	.global add_byte

#######################################################	
add_byte:

	# %dil = x
	# %rsi = *vec1
	# %rdx = *vec2


	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------
	movl (%rsi),%ecx		# declarate the counter
	movl %ecx, (%rdx)		# move the 1 element to vec2

	addq $4,%rsi			# move to the second element
	addq $4,%rdx			# move to the second space
	
	cmp $0,%ecx				# check if vec != NULL
	jz end
loop:
	
	movl (%rsi),%eax		# move number to eax
	
	addb %dil,%al			# 1byte + x = al

	movl %eax,(%rdx)		# move to vec2
	
	addq $4,%rsi			# next number
	addq $4,%rdx			# next space

	loop loop				# loop
#------------------------------------------------------
end:		
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	
