.section .data

	.global ptrvec
	.global num
	
.section .text
.global  vec_sum
vec_sum:

	movw num(%rip),%cx				#move the num to cx
	movq ptrvec(%rip),%rsi			#move the pointer to rsi
	movq $0,%rax					# clear rax

###########################################

loop:								#start of the loop
	
	cmpw $0,%cx						#check if the vetor is not null
	jz end							#jmp if is null
	
	movq (%rsi),%rdi				# move value that is being pointed to rdi
	addq %rdi,%rax					# add the value to rax
	addq $8, %rsi					# move to the next position
	
	loop loop						# go back to the loop end when rcx is 0
	
###########################################
		
end:

	ret								# return 
