.section .data
	
    .global s1, s2		#Declaring the global variables
    
.section .text

.global crossSumBytes

crossSumBytes:
	
	movw s1(%rip), %ax	#Put byte1 in the least significant byte
	movw s2(%rip), %bx	#Put byte2 int the most significant byte
	addb %bl, %ah    	#Sum the most significant bytes1 with the least significant byte of s2
	addb %bh, %al		#Sum the most significant bytes2 with the least significant byte of s1
	ret            #return the value in %ax
