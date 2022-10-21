.section .data
	length1:
		.int 4
	length2:
		.int 2
	height:
		.int 5
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
