.section .data
	
.section .text

	.global changes

#######################################################	
changes:

	# %rdi = *ptr


	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------
	movl (%rdi), %eax
	movb $16, %cl
	movb $1,%dil
	rorl $8, %eax
	
	cmpb $15,%al
	jle end

loop:	
	cmpb $24,%cl
	je end
	
	shl %cl,%dil
	
	xorb %dil,(%rdi)
	
	incb %cl
	jmp loop
#------------------------------------------------------
end:		
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	
