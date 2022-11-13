.section .data
	
.section .text

	.global count_bits_one
	.global vec_count_bits_one	

#######################################################	
count_bits_one:

	# %di = x
	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
	movl $0,%eax		# return
	movl $0,%ecx		# i
	movw 16(%rbp),%di
loop:

	cmpl $16, %ecx		# i < 16
	je end				
	
	shrw %di			# right shift x	
	incl %ecx			# increase i		
	jnc counter			# if carry  = 0
	jmp loop
	
counter:
	incl %eax			# increase the counter
	jmp loop			# loop


	
end:	
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	

vec_count_bits_one:

	# %rdi = *ptr
	# %esi = num
	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
	
	movl $0, %eax		# clear the counter
	movl %esi, %ecx		# counter = num
	
	cmp $0,%ecx			# check if vec = NULL
	jz end_2
	
loop_2:	
	
	movw (%rdi), %dx		# move short to 1 argument
	pushq %rcx
	pushw %dx
	call count_bits_one	#call function
	addq $2,%rsp
	popq %rcx
	addl %eax, %r8d		# sum of the inactive bits
	addq $2, %rdi		# move to the next number
	
	loop loop_2			# loop
	
	movl %r8d,%eax		# return the number of inactive bits
	
end_2:	
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
