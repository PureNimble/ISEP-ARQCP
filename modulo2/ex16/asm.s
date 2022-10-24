.section .data

	.global num
	
.section .text

.global steps
steps:
	
	movq num(%rip), %rax    #move num to rax
	movq $3, %rcx           #move 3 to rcx
	movq $0, %rdx           #move 0 to rdx
	imulq $3, %rax			#Multiplies by 3
	addq  $6, %rax			#Adds 6
	cqo
	idivq %rcx				#Divides by 3
	addq $12, %rax			#Adds 12
	subq  num(%rip),%rax	#Subtracts num
	decq %rax			 	#Subtracts 1
	
	ret                     #return
