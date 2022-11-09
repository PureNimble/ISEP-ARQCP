.section .data

.section .text

	.global sum_n2
	
#############################################	
sum_n2:
	
	movq $0, %rax			#clear rax
	cmpl $1, %edi			#edi > 0
	jl end
	movslq %edi, %rdi
	movq %rdi, %rcx			# move n to ecx (the counter)
loop:
	movq %rcx , %rsi		# move ecx to esi
	
	imulq %rsi,%rsi			# n^2			
	
	addq %rsi, %rax			# return = return + n
	
	loop loop				# n-1
end:
	ret						#return the value in rax
	
#############################################	
