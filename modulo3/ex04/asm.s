.section .bss

	.global ptrvec, num
	.comm ptrvec, 8

.section .text
.global  vec_add_two
vec_add_two:

	movq ptrvec(%rip), %rsi		# move the pointer 1 to rsi
	movl num(%rip), %ecx		# move num to rcx for the number of times 

vec_inc:
	cmpl $0,%ecx				#Check if the array is empty
	jz end
	addl $2, (%rsi)				#add 2 to the element
	addq $4, %rsi				#move to the next int
	loop vec_inc				#jump to loop
end:	
	ret   							#return
