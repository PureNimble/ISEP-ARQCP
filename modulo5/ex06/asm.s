.section .data
	
	.equ GRADES_OFFSET, 4			# the address starts at the byte 4

.section .text

	.global  locate_greater
	
#############################################	
locate_greater:

	#rdi = *s pointer of the struct
	#esi = minimum int
	#rdx = *greater_grade
		
	addq $GRADES_OFFSET,%rdi
	movb $5,%cl					# move 5 to the loop counter
	movl $0,%eax				# clear the counter
loop:
	movl (%rdx),%r8d
	cmpl %esi,%r8d
	jle next
	
	incl %eax
	movl %r8d,(%rdi)
	addq $4,%rdi
next:
	addq $4,%rdx
	loop loop

	ret					# return the value in eax
	
#############################################
