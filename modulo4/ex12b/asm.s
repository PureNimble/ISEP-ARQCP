.section .data
	
.section .text

	.global count_bits_one	

#######################################################	
count_bits_one :

	# %esi = x
	
	#prologue
	pushl %rbp  		# save the original value of RBP  
	movl %rsp, %rbp 	# copy the current stack pointer to RBP
	
	
	
	
	
	
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	
