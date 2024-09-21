.section .data

.section .text

	.global cube
	
#############################################	
cube:
	movslq %edi, %rdi			# move 1 parameter that is on edi to rdi
	movslq %edi,%rax			# move 1 parameter that is on edi to rax
	
	imulq %rdi				# x*x
	imulq %rdi				#(x^2)*x
	
	

	ret						#return the value in rax
	
#############################################	
