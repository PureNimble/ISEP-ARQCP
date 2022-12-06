.section .data
	
	.equ GRADES_OFFSET, 4			# the address starts at the byte 4

.section .text

	.global update_grades
	
#############################################	
update_grades:

	#rdi = *s pointer of the struct
	#rsi = *new_grades pointer of the newadress
	
	addq $GRADES_OFFSET,%rdi
	movb $5,%cl					# move 5 to the loop counter
loop:
	movl (%rsi),%eax		# move the int to a register
	
	movl %eax,(%rdi)		# move the int to the grades in the struct			
	
	addq $4,%rdi			# move to the next space
	addq $4, %rsi			# move th the next int
	
	loop loop
	
	ret					# return the value in eax
	
#############################################
