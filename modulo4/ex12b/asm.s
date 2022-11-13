.section .data
	
.section .text

	.global count_bits_one	

#######################################################	
count_bits_one :

	# %edi = x
	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#######################################################	
	
	movl $0,%eax		# return
	movl $0,%ecx		# i

loop:

	cmpl $32, %ecx		# i < 32
	je end				
	
	shrl %edi			# right shift x			
	jc counter			# if carry  = 1 
	incl %ecx			# increase i
	jmp loop
	
counter:
	incl %eax			# increase the counter
	jmp loop			# loop


	
#######################################################	
	
end:	
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	
