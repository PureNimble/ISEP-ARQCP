.section .data

.section .text

	.global calc
	
#############################################	
calc:

	#edi = a
	#rsi = *b
	#edx = c
	
	movl (%rsi),%eax			#move b to return
	
	sall $1, %edi				#  a * 2			
	subl %eax, %edi				# (a * 2) - b
	
	subl $4, %edx				# c - 4

	imull %edx, %edi			# (c - 4) * ((a * 2) - b)

	movl %edi,%eax				
end:
	ret							#return the value in eax
	
#############################################	
