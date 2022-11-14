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
	
loop:

	cmpl $16, %ecx		# i < 16
	je end				
		
	incl %ecx			# increase i
	shrw %di			# right shift x		
	jc counter			# if carry  = 1
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
	
	movl $0, %eax 		# clear the counter
	movl $0, %r8d		# clear the counter
	movl %esi, %ecx		# counter = num
	
	cmp $0,%ecx			# check if vec = NULL
	jz end_2
	
loop_2:	
	
	movw (%rdi), %dx		# move short to dx
	pushq %rdi				# push rdi
	movw %dx,%di			# 1 argument
	pushq %rcx				# push rcx
	
	call count_bits_one		#call function
	
	popq %rcx				# pop rcx
	popq %rdi				# pop rdi
	addl %eax, %r8d			# sum of the active bits
	addq $2, %rdi			# move to the next number
	
	loop loop_2				# loop
	
	movl %r8d,%eax			# return the number of active bits
	
end_2:	
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
