.section .data
	
.section .text

	.global reset_bits
	.global reset_2bits

#######################################################	
reset_bits:

	# (%rdi) = *ptr
	# %esi = pos
	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
	movl %esi, %ecx			# move pos to ecx
#------------------------------------------------------	
	
	rorl %cl, (%rdi)		# rotate right (pos) bits
	movl (%rdi), %r8d		# the (pos) bit is in the first position
	andl $-2, (%rdi)		# 1110 | %ebx
	roll %cl, (%rdi)		# rotate left (pos) bits
	
	andl $1, %r8d			# 0001 & num
	cmpl $0, %r8d			# check if the bit has been changed
	jz notchange
	movl $1, %eax			# return 0, if the bit was 0  
	jmp end
notchange:
	movl $0, %eax			# return 1, if the bit was 1
	
#------------------------------------------------------		
	
end:	
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	

reset_2bits:

	# %rdi  *ptr
	# %esi  pos
	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
	
	call reset_bits 	# call the function to change the (pos) bit
	movl $31, %r10d		# r10d = 31
	subl %esi, %r10d	# r10d = 31 - pos
	movl %r10d, %esi	# move r10d to 2 argument
	call reset_bits 	# call the function to change the (31 - pos) bit

end_2:	
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret	
	
#######################################################

