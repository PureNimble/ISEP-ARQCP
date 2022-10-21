.section .data

	.global A,B
	
.section .text

.global isMultiple
isMultiple:
	movl B(%rip), %eax
	movl A(%rip), %ecx
	movl $0, %ebx
	
	divl %ecx
	
	cmpl %edx, %ebx
	
	je isequal
	movb $0, %al
	jmp end
	
isequal:
	movb $1, %al
	
end:
	ret
