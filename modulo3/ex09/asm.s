.section .data

	.global x
	.global num
	.global ptrvec
	
.section .text

	.global vec_search

##########################################
vec_search:
	
	movl num(%rip),%ecx			# numero de ciclos a fazer
	movq ptrvec(%rip),%rsi		# valor do pointer
	movw x(%rip), %ax			# valor de x
	
	cmpl $0, %ecx				# verificar se vec != null
	jz  no_number				# null return = 0

loop:
	movw (%rsi), %dx			# armazenar o numero em dx
	cmpw %ax,%dx				# comparar dx com x 
	je same						# dx = x sao iguais
	addq $2, %rsi				# mover para a proxima posicao
	
	loop loop					#loop
	jmp no_number
same:

	movq %rsi, %rax				# mover o endereco de vec[i] = x
	jmp end						# end
	
no_number:

	movq $0, %rax				# return = 0
	jmp end
	
end: 
	ret
##########################################
