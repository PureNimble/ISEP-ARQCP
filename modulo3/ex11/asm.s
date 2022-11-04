.section .bss

	.global ptrvec
	.comm ptrvec, 8
	
.section .text
.global vec_greater10
vec_greater10:

	movq ptrvec(%rip), %rsi		# move the pointer to rsi
	movl num(%rip), %ecx
	movl $0, %eax

vec:
	cmpl $0,%ecx				#Check if the array is empty
	jz end
	movl (%rsi), %edx			#copy int to ecx
	cmpl $10, %edx
	jg bigger10
	addq $4, %rsi
	loop vec
	jmp end
	
bigger10:

	incl %eax
	addq $4, %rsi
	loop vec

end: 
	ret
