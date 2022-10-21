.section .data

	.global num;
	
.section .text

.global steps
steps:

	movq num(%rip), %rax
	movq num(%rip), %rdx
	movq $3, %rcx
	imulq $3, %rax			#Multiplies by 3
	addq  $6, %rax			#Adds 6
	divq  %rcx				#Divides by 3
	addq  $12, %rax			#Adds 12
	subq  %rdx,%rax			#Subtracts num
	decq  %rax				#Subtracts 1
end:
	ret
