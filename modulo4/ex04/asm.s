.section .data

.section .text

	.global sum_smaller
	
#############################################	
sum_smaller:

	#edi = num1
	#esi = num2
	#rdx = *smaller
	
	movq $0, %rax			#clear rax
	cmpl %esi,%edi			# num1 < num2
	jl num1					# jmp
	movl %esi,(%rdx)		#point to num2
	jmp sum					# next
num1:
	movl %edi,(%rdx)		#point to num1
sum:
	addl %edi,%eax			# return = return + num1
	addl %esi,%eax			# return = return + num2
end:

	ret						#return the value in rax
	
#############################################	
