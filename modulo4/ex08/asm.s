.section .data

.section .text

	.global calc
	
#############################################	
calc:

	#edi = a
	#rsi = *b
	#edx = c
	movl (%rsi),%eax			#move c to return
	
	sall $1, %edi				# a * 2			
	subl %edi, %eax				# (a * 2) - b
	
	subl $4, %edx				# c - 4

	imull %edx					# (c - 4) * (a * 2) - b
	
end:
	ret						#return the value in eax
	
#############################################	
