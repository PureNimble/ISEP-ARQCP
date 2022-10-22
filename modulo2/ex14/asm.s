.section .data
	length1:
		.int 4
	length2:
		.int 2
	height:
		.int 5
		
.global length1, length2, height

.section .text

.global getArea
getArea:
	movl length1(%rip), %eax
	movl length2(%rip), %esi
	movl height(%rip), %ecx
	addl %esi, %eax
	mull %ecx
	movl $2, %esi
	
	divl %esi
	
end:
	ret
