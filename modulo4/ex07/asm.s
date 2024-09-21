.section .data

.section .text

	.global count_odd
	
#############################################	
count_odd:
	
	#rdi = *vec
	#esi = n
	
	movslq %esi, %rcx		# set the counter
	movl $0, %r8d			# clear r8d
	movw $2, %r9w			# set the divisor
	
	cmpq $0, %rcx			#check if vec = NULL
	jz end
loop:	
	movb (%rdi), %al		# move a char
	movsbw %al, %ax
	cwd				
	idivw %r9w				# char / 2				
	
	cmpw $0, %dx			# check if rest = 0
	je next
	
	incl %r8d				# if is odd increase the counter
next:	
	incq %rdi				# move to the next char
	loop loop				# loop
end:
	movl %r8d, %eax			# return the counter
	ret						# return
	
#############################################	
