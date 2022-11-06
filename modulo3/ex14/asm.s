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
	cmpl $0, %ecx			#check if vec is null
	jz end

loop:

	cmpl %eax, (%rsi)   	
	je   same    		
	jmp  next				

same:
	incw %di
next:
	addq $4,%rsi			#move to next number	
	loop loop         		# loop
	
		
	cmpw $1,%di
	jg duplicate
	movl $0,%eax
	jmp end

duplicate:
	movl $1,%eax
	
end:
	movw %di,x(%rip)
	ret 
##########################################################
vec_diff:
		
	movq $0,%rdi
	movl x(%rip),%edi
	movl num(%rip),%eax
	
	cmpl $1,%edi
	jle end_2
	
	subl %edi, %eax
end_2:	
	ret
##########################################################
