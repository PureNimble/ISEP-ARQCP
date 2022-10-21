.section .data
	
    .global byte1, byte2		#Declaring the global variables
    
.section .text

.global concatBytes  

concatBytes:

	movw $0, %ax            #clean the 2 bytes
	movb byte1(%rip), %al	#Put byte1 in the least significant byte
	movb byte2(%rip), %ah	#Put byte2 int the most significant byte

	ret            #return the value in %eax
