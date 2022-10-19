.section .data
	
    .global s		#Declaring the global variables
    
.section .text

.global swapBytes   
swapBytes:

	movw s(%rip), %ax 	#place  ax =al + ah
	
	movb %al, %cl     	# move the least significant
	movb %ah, %al	
	addb %al, %al   						
	movb %cl, %ah		
	

	ret            #return the value in %eax
