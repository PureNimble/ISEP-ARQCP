.section .data
	
.section .text

	.global count_odd_matrix

#######################################################	
count_odd_matrix:

	# %rdi = **m matrix pointer
	# %esi = y -> line
	# %edx = k -> column
	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------
	movl %edx,%ecx				
	shll %ecx,%esi			# shift left 
	addq %rsi,%rdi
	
	movl (%rdi,%rdx,4), %eax
	
	andl $1,eax
	xorl $1,%eax
		
	cmpl $0,%eax
	jz  end
	incl %eax
	
	
end:	
	
	
	
	
#------------------------------------------------------
		
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	
