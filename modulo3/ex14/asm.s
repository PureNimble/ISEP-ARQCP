.section .data

	.global ptrvec
	.global num
	.global x
	
.section .text

	.global exists
	.global vec_diff


##########################################################	
exists:	

	movq ptrvec(%rip),%rsi
	movl num(%rip), %ecx
	movl x(%rip),%eax
	movw $0,%di
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
	
	ret 
##########################################################

