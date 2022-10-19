.section .data
	
    .global byte1,byte2		#Declaring the global variables
    
.section .text

.global concatBytes  
concatBytes:

	movw byte1(%rip), %ax 	   
	movw byte2(%rip), %cx
	
	movb %bl, %cl     	#move the the least significant to a register 
	movb %bh, %bl	   	#move  the most significant byte to the least one
	mulq %al, %bl		#multiplication
	movb %cl, %bh		#move the register value to the most significant value


	ret            #return the value in %eax
