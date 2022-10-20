.section .data
	
    .global x		#Declaring the global variables
    
.section .text

.global swapBytes   
swapBytes:

	movw x(%rip), %ax 	#place op1 in ecx   
	movb %al, %cl     	#move the the least significant to a register
	movb %ah, %al	   	#move  the most significant byte to the least one
	imulb %al
	movb %cl, %ah		#move the register value to the most significant value


	ret            #return the value in %eax
