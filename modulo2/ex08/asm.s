.section .data
	
s1:
		.short 10
s2:
		.short 20
		
.global s1, s2
   
.section .text

.global crossSumBytes

crossSumBytes:
	
	movw s1(%rip), %ax	#Put byte1 in the least significant byte
	movw s2(%rip), %cx	#Put byte2 int the most significant byte
	addb %cl, %ah    	#Sum the most significant bytes1 with the least significant byte of s2
	addb %ch, %al		#Sum the most significant bytes2 with the least significant byte of s1
	ret            #return the value in %ax
