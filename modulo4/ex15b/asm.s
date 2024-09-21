.section .data
	
.section .text

	.global activate_bits

#######################################################	
activate_bits:

	# %edi = a
	# %esi = left
	# %edx = right
	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------
	cmpl $31,%esi		# check if is the end of the int
	je next
	
	incl %esi			# left + 1
	movl %esi,%ecx		# move (left +1) to counter
	
	
loop:
	cmp	$32, %ecx		# check if is the end of the int
	jg next
	
	rorl %ecx, %edi		# rotate the bit to the first position
	orl $1,%edi			# first bit = 1
	roll %ecx, %edi		# rotate back to (a) value
	incl %ecx			# increase the counter
	jmp loop			# loop
	
next:	
	
	decl %edx			# right - 1
	movl %edx, %ecx		# move (right - 1) to counter
	
loop2:
	cmp	$0,%ecx			# check if is the end of the int
	jle next2
	rorl %ecx, %edi		# rotate the bit to the first position
	orl $1,%edi			# first bit = 1
	roll %ecx, %edi		# rotate back to (a) value
	decl %ecx			# decrease the counter		
	jmp loop2			# loop

next2:
	movl %edi, %eax		# return a 
#------------------------------------------------------
		
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	
