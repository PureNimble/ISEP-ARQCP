.section .data

	.global ptrvec
	.global num
	.global x
	
.section .text

	.global exists
	.global vec_diff


##########################################################	
exists:	

	movq ptrvec(%rip),%rsi		#move pointer to rsi
	movl num(%rip), %ecx		#move the size of vec to ecx
	movl x(%rip),%eax			#move the search number to eax
	movw $0, %di				#clean the counter
	cmpl $0, %ecx				#check if vec is null
	jz end

loop:

	cmpl %eax, (%rsi)   		# check if x = vec[i]
	je   same    				# jmp if equal
	jmp  next					# next number			

same:
	incw %di					# increase the counter
next:
	addq $4,%rsi				#move to next number	
	loop loop         			# loop
	
		
	cmpw $0,%di					# check if the number is duplicate
	jg duplicate				#
	movl $0,%eax
	jmp end

duplicate:
	movl $1,%eax
	
end:
	ret 
##########################################################
vec_diff:

	movq ptrvec(%rip),%rsi		#move pointer to rsi
	movl num(%rip), %ecx		#move the size of vec to ecx
	movl $0,%edx
	movq $0,%rax
	cmpl $0, %ecx				#check if vec is null
	jz end_2
loop_2:
	movl (%rsi),%edi
	movl %edi,x(%rip)
	
	pushq %rsi
	pushq %rcx
	call exists
	popq %rcx
	popq %rsi
	
	cmpl $0,%eax
	jz valid
	jmp next_2
	
valid:

	incl %edx
	
next_2:

	addq $4,%rsi
	
	loop loop_2
	
	movl %edx,%eax
	
end_2:
	ret
##########################################################
