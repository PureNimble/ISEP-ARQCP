.section .data

	.global i,n
A:
		.int 1
B:
		.int 2

.section .text

.global somatorio
somatorio:
	
	movl  A(%rip),%eax
	movl  B(%rip),%esi
	movl  i(%rip),%edi
	movl  n(%rip),%ecx
	
loop:	
	
	imul 	%edi, %edi   	# i*i
	imul 	%eax, %eax     	# A*A
	imul 	%edi, %eax		# (i*i) * (A*A)
	idivl	%esi			# (i*i) * (A*A) / B
	incl 	%edi			# increase i
	
	cmp   %edi, %ecx	# if n > i
	jg  loop 			#Jump if n > i
 
	ret
