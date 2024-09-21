.section .data
	
.section .text

	.global changes
	.global changes_vec

#######################################################	
changes:

	# %rdi = *ptr

	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------
	movl (%rdi), %eax	# move the number to eax
	andl $0xff00,%eax	# number & mask = just the second byte
	shrl $8, %eax		# second byte
	
	cmpl $15,%eax    	# check if the second byte is greater then 15
	jle end
	
	xorl $0xFF0000,(%rdi)	# inverte the bits in the third byte

#------------------------------------------------------
end:		
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	
changes_vec:

# %rdi = *ptrvec
# %esi = num


	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------
	movl %esi,%ecx		# move to the counter
	decl %ecx			# decrease the counter 
loop:	
	call changes		# call the function
	
	addq $4,%rdi		# move to next number
	loop loop			# loop

#------------------------------------------------------		
hi:
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
#######################################################	
