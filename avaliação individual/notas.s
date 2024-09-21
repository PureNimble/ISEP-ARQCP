.section .data
	
	.equ NOME_OFFSET, 0
	.equ NOTAS_OFFSET, 8
	.equ NOTA_FINAL_OFFSET, 12

.section .text

	.global notas
	
#############################################	
notas:
	#%rdi struct 
	#%esi n de alunos
	
	push %rsi
	movl %esi,%ecx			# Declarate the index of the loop
	movq %rdi,%rsi			# move the address to rsi
	
	movl $0, %edx			# Clear the counter of the nota_final of all students
	
loop:

	movl NOTAS_OFFSET(%rsi), %edi		# get the Notas
	
	call calcula_nota					# calculate the nota_final
	
	movl %eax,NOTA_FINAL_OFFSET(%rsi)	# move the return to nota_final
	
	
	addl %eax,%edx						# sum of the nota_final of all students
	
	addq $16,%rsi						# move to the next student
	
	loop loop
	
	popq %rsi							# get n de alunos
	
	movl %edx,%eax						# move the sum to the dividend
	
	idivl %esi							# div by the number of students
	
ret										# return media

#############################################
