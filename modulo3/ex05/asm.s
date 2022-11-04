.section .bss

	.global ptrvec,num
	.comm ptrvec, 8
	.comm num, 2
	
.section .text
.global  vec_sum, vec_avg
vec_sum:
	
	movw num(%rip),%cx
	movq vec_sum(%rip),%rsi

vec_star:
	
	cmpw %cx
	addq (%rsi),%rax
	addq $8, %rsi
	
	
	
	loop vec_star

