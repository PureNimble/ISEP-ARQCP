.section .data
	
.section .text

	.global join_bits
	.global mixed_sum

#######################################################	
join_bits:

	# %edi = a
	# %esi = b
	# %edx = pos
	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------
	movl $1, %eax		# 1	
	movl %edx,%ecx		# move edx to ecx
	
	shl %cl,%eax		# Shift left (pos) bits 
	subl $1,%eax		# (Shift left (pos) bits) - 1 = mask with 1s before (pos) and 0s after (pos)
	
	shl %eax			# (Shift left (pos) bits) - 1 = mask with 1s before (pos) and 0s after (pos)
	incl %eax			# Active the first bit, that was changed in the last line
	
	andl %eax,%edi		# a & mask ( clear the left bits of a, start at (pos+1) )
	notl %eax			# ~mask
	
	andl %eax, %esi		# b & ~mask ( clear the right bits of b, start at pos )
	
	orl %edi,%esi		# a | b ( combine all bits )
	
	movl %esi,%eax
#------------------------------------------------------
		
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	
mixed_sum:

	# %edi = a
	# %esi = b
	# %edx = pos
	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------
	pushq %rdi			# save a
	pushq %rsi			# save b
	
	call join_bits		# call the function
	movl %eax,%r8d		# move the return to r8d
	
	popq %rsi			# pop a
	popq %rdi			# pop b
	
	xchg %esi, %edi		# swap

	call join_bits		# call the function with inverse arguments
	
	addl %r8d,%eax		# sum of the 2 functions
	 

#------------------------------------------------------
		
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
#######################################################	
