.section .data

	.global i
A:
		.int 1
B:
		.int 2

.section .text

.global somatorio
somatorio:
	
	movl  A(%rip),%eax
	movl  B(%rip),%ebx
	movl  i(%rip),%ebx
	cmp 
	ret
