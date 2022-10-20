.section .data
	
    .global s		#Declaring the global variables
    
.section .text

.global swapBytes   
swapBytes:

<<<<<<< HEAD
	movw x(%rip), %ax 	#place op1 in ecx   
	movb %al, %cl     	#move the the least significant to a register
	movb %ah, %al	   	#move  the most significant byte to the least one
	imulb %al
	movb %cl, %ah		#move the register value to the most significant value

=======
	movw s(%rip), %ax 	#place  ax =al + ah
	movb $2,%cl
	
	movb  %al, %cl     	# move the least significant to a register
	movb  %ah, %al		# move the most significant to the least one
	imulb %al   	    # multiply the previous most significant byte by 2						
	movb  %cl, %ah		# move the register to the most significant byte
	
>>>>>>> d52e8b27150f505162c551b4cec1ffa74dc801d2

	ret            #return the value in %eax
