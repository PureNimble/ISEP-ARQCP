.section .data
	
    .global byte1, byte2		#Declaring the global variables
    
.section .text

.global concatBytes  

<<<<<<< HEAD
	movw x(%rip), %ax 	#place op1 in ecx
	movb %al, %bl     	#move the the least significant to a register
	movb %ah, %al	   	#move  the most significant byte to the least one
	movb %bl, %ah		#move the register value to the most significant value
=======
concatBytes:
>>>>>>> d52e8b27150f505162c551b4cec1ffa74dc801d2

	movb byte1(%rip), %al	#Put byte1 in the least significant byte
	movb byte2(%rip), %ah	#Put byte2 int the most significant byte

	ret            #return the value in %eax

.global concatBytes
concatBytes:
