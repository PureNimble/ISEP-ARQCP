.section .data

	.global num
	
.section .text
.global  vec_avg
vec_avg:


	
	call vec_sum			#call the other asm function
	movq $0,%rcx			#clear rcx
	movw num(%rip),%cx		#move num to cx
	cmpw $0,%cx				#check if the divisor is not zero
	je zero					# jmp if = 0
	cqo 					# sign-extend quad to oct word %rdx:%rax
	idivq %rcx
	jmp end
	
zero:
	movq $0,%rax			# move 0 to the rax	
end:
	
	ret
