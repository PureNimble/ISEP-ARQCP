.section .data
	
    .global s		#Declaring the global variables
    
.section .text

.global swapBytes   
swapBytes:

	movw s(%rip), %ax 	#place  ax =al + ah
	
	movb %al, %cl     	# move the least significant to a register
	movb %ah, %al		# move the most significant to the least one
	addb %al, %al   	# multiply the previous most significant byte by 2						
	movb %cl, %ah		# move the register to the most significant byte
	

	ret            #return the value in %eax
