.section .data

	.global vec
	
.section .text

.global seven_count
seven_count: 


		leaq vec(%rip), %rdi	#rdi is the pointer of vec
		movq $12, %rcx
		movq $0,%rax
loop:
		cmpb $55,(%rdi)	# 7 
		jne notequal
		incq %rax
		addq $1, %rdi
		loop loop
		jmp end
		
notequal:
	addq $1, %rdi
	loop loop
end:                #return
ret
