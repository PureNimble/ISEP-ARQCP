.section .data
	.equ GRADES_OFFSET, 4		# the address starts at the byte 4

.section .text

	.global  locate_greater
	
#############################################	
locate_greater:

	#rdi = *s pointer of the struct
	#esi = minimum int
	#rdx = *greater_grade
		
	addq $GRADES_OFFSET,%rdi
	movq $0,%rcx					# move 5 to the loop counter
	movq $0,%r9				# clear the counter
loop:
	cmpq $5, %rcx
	je end
	movl (%rdi , %rcx , 4), %eax
	cmpl %esi,%eax
	jle next
	incq %r9
	movl %eax, (%rdx)
	addq $4, %rdx
next:
	incq %rcx
	jmp loop
end:
	movq %r9, %rax
	ret					# return the value in eax
	
#############################################
