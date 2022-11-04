.section .bss

	.global ptrvec,num
	.comm ptrvec, 8
	.comm num, 2
	
.section .text
.global  vec_sum, vec_avg
vec_sum:
	
	movw num(%rip),%rdi
	movq vec_sum(%rip),%rsi

