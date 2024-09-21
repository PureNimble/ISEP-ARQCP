.section .data

.section .text

	.global calculate
	.global print_result
	
#############################################	
calculate:
	
	#edi = a
	#esi = b
	
	movl %esi, %ecx			# move b to ecx (4 parameter  (imull))

	

	
	imull %edi, %ecx		# a * b
	
	movl  %esi,	%edx		# 3 parameter  (b)
	movl  %edi,	%esi		# 2 parameter  (a)
	
	movb $'*', %dil			# 1 parameter
	
	pushq %rcx				#  push mull
	pushq %rsi				#  push a
	pushq %rdx				#  push b
	
	
	
	call print_result   	# call the function in main
	
	
	popq %rdx				# b
	popq %rsi				# a

	
	movl %esi, %ecx  		# move b to ecx
	
	subl %edx, %ecx			# a - b 4 parameter  (sub)
	 						
	movb $'-', %dil			# 1 parameter
	
	movl %ecx, %eax			# move (a - b) to eax
	
	pushq %rax 
	
	call print_result		# call the function in main
	
	popq %rax				# (a * b)
	popq %rcx				# (a - b)
	
	subl %ecx, %eax			# (a - b) - (a * b)


	ret							#return the value in eax
	
#############################################	
