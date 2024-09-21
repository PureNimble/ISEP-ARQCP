.section .data

	.global ptrvec
	.global num
	
.section .text

	.global sum_first_byte


##########################################################	
sum_first_byte:	
	
	movq ptrvec(%rip),%rsi		# move the pointer to rsi
	movl num(%rip), %ecx		# move the number of elements to ecx
	movq $0,%rax				#clear rax
	movq $0,%rdi				#clear rdi
	
	cmpl $0,%ecx				# check if vec is null
	jz end
	
loop:
	movq (%rsi), %rdi			# move the number to rdi
	movsxb %dil,%edx			# move from byte to 4 bytes
	addl %edx,%eax				# sum of the 1 byte
	addq $8,%rsi				# move to next number
	
	loop loop					#loop
end: 
	ret							#return


	
##########################################################
