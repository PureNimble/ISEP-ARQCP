.section .data

	.global i
A:
		.int 1
B:
		.int 2

.section .text

.global somatorio
somatorio:
	
	movq num(%rip), %rax
	movq $3, %rcx
	movq $0, %rdx
	imulq $3, %rax			#Multiplies by 3
	addq  $6, %rax			#Adds 6
	cqo
	idivq %rcx				#Divides by 3
	addq $12, %rax			#Adds 12
	subq  num(%rip),%rax	#Subtracts num
	decq %rax			 	#Subtracts 1
	
	ret
