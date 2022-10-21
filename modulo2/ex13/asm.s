.section .data

	.global length1, length2, height
	
.section .text

.global getArea
getArea:
	movl length1(%rip), %eax
	movl length2(%rip), %ebx
	movl height(%rip), %ecx
	addl %ebx, %eax
	mull %ecx
	movl $2, %ebx
	
	divl %ebx
	
end:
	ret
