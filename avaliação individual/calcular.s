.section .data


.section .text

	.global calcula_nota
	
#############################################	
calcula_nota:

	#%edi notas
	
	movl $8,%ecx		# declarate the index of the loop
	movl $0,%eax		# clear the return register
	
loop:

	rorl $3,%edi		# get the 3 bit which says if the number is valid	
	movl %edi,%esi
	andl $0x1,%esi		# mask  to get the first 4 bits
	
	rorl $3,%edi		# get the 3 bit
		
	cmpl $0,%esi		# check if the nota is valid
	jz next
	
	subl $8, %edi		# remove the 3 bit 
	
	addl %edi,%eax		# sum of the valid notas
	
next:
	
	shrl $4,%esi		# move to the next 4 bits
	
	loop loop
ret

#############################################
