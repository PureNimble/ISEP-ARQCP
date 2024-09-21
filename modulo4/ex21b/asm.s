.section .data

.section .text

	.global distance
	
#############################################	
distance:

	#rdi = *a
	#rsi = *b
	
	movl $0,%eax			# declaration of the counter
loop:
	movb (%rdi), %dl		# a
	movb (%rsi), %cl		# b
	
	cmpb $0, %dl			# check if string end -> a
	jz checksize
	
	cmpb %dl,%cl			# compare char
	je equal				
	
	incl %eax				# counter of the wrong chars
	
equal:
	incq  %rdi			# next char a
	incq  %rsi			# next char b
	jmp loop			# loop
	
	
checksize:

	cmpb $0, %cl		# check if string end -> b
	je end
	movl $-1,%eax		# the strings arent the same length
end:
	ret					# return the value in eax
	
#############################################	
