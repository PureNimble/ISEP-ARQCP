.section .data

	.global even
	.global num
	.global ptrvec
	
.section .text

	.global test_even
	.global vec_sum_even

##########################################
test_even:
	
	movq $0, %rdx				#limpar rdx onde o resto da divisao vai estar armazenado
	movq even(%rip),%rax 		# mover o numero para rax
	movq $2, %rcx				# divisor de rax
	cqo 						# rdx:rax
	idivq %rcx
	
	cmpq $0, %rdx				# ver se existe resto
	je n_even					# jmp se nao ouver
	jmp n_odd					# jmp odd

n_even:
	movq $1,%rax				# return = 1
	jmp end
	
n_odd:
	movq $0,%rax				# return = 0
	
end:
	ret

##########################################	
vec_sum_even:
	
	movl num(%rip),%ecx				# mover num para ecx (para contar o numero de ciclos)
	movq ptrvec(%rip),%rsi			# mover o valor do pointer para rsi
	movq $0,%r8						# limpar rbx
	
	
loop:								# inicio do loop 
	
	cmpl $0,%ecx					# verficar se vec e null
	jz end_2						#jmp = null
	
	movq (%rsi),%rdi				# mover o valor apontado por rsi em rdi
	movq %rdi,even(%rip)			# mudar o valor da variavel global even	
	
	pushq %rcx						# guardar na stack rcx
	pushq %rsi						# guardar na stack rsi
	call test_even	
	popq %rsi						# devolve o valor 
	popq %rcx						# devolve o valor 
	
	cmpq $1, %rax					# rax = 1
	je sum_even						# jmp sum_even, pois e par
	addq $8, %rsi					# proxima posicao
	loop loop						#loop
	jmp end_2
sum_even:

	addq (%rsi),%r8					# armazenar os numeros pares em rbx
	addq $8, %rsi					# mover para o proximo numero de vec
	loop loop						#loop
		
end_2:
	movq %r8,%rax					# return da soma
	ret								# return 

##########################################		
