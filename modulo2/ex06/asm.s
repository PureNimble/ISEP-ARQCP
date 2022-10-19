.section .data
	
    .global s		#Declaring the global variables
    
.section .text

.global swapBytes   
swapBytes:

	movw s(%rip), %ax 	#place op1 in ecx   
	movb %al, %bl     	#move the the least significant to a register
	movb %ah, %al	   	#move  the most significant byte to the least one
	movb %bl, %ah		#move the register value to the most significant value


	ret            #return the value in %eax
