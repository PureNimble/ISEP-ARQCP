.section .data
	
    .global s		#Declaring the global variables
    
.section .text

.global swapBytes   
swapBytes:

	movw s(%rip), %bx 	#place op1 in ecx   
	movw $2, %al
	
	movb %bl, %cl     	#move the the least significant to a register 
	movb %bh, %bl	   	#move  the most significant byte to the least one
	mulq %al, %bl		#multiplication
	movb %cl, %bh		#move the register value to the most significant value


	ret            #return the value in %eax
