.section .bss

	.global ptrvec
	.comm ptrvec, 8
	
.section .text
.global vec_sum, vec_avg
vec_sum:
	movq ptrvec(%rip), %rsi		# move the pointer of vec to rsi
	movq num(%rip), %rcx
	movq $0, %rax
	
vec:
	movq (%rsi), %rdx
	addq %rdx, %rax
	addq $8, %rsi
	loop vec
end:
	pop 
	call vec_avg

vec_avg:

	movq num(%rip),$rdi
	mov
	
