.section .data

.section .text

	.global test_equal
	
#############################################	
test_equal:

	#rdi = *a
	#rsi = *b
	
	movl $1,%eax
loop:
	movb (%rdi), %dl		# a
	movb (%rsi), %cl		# b
	
	cmpb $0, %dl			# check if string end -> a
	jz checksize
	
	cmpb %dl,%cl			# compare char
	jne not_equal			#  jmp  not equal
	
	incq  %rdi			# next char a
	incq  %rsi			# next char b
	jmp loop

not_equal:

	decl %eax			# return = 0
	
	jmp end
	
checksize:

	cmpb $0, %cl		# check if string end -> b
	jne not_equal
		
end:
	ret						#return the value in eax
	
#############################################	
