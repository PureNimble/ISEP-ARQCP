.section .data

.section .text

	.global cube
	
#############################################	
cube:

	movq %rdi,%rax			# move 1 parameter that is on rdi to rsi
	
	imulq %rdi				# x*x
	imulq %rdi				#(x^2)*x
	
	

	ret						#return the value in rax
	
#############################################	
