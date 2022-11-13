.section .data

	.global ptrvec, num
	
.section .text
.global vec_zero
vec_zero:

	movq ptrvec(%rip), %rsi		#move the pointer to rsi
	movl num(%rip), %ecx        #move num elements to ecx
	movl $0, %eax				#clear eax

vec_check:

	cmpl $0,%ecx			    #check if is the end of the cycle
	jz end						#jump to end	
	
	movl (%rsi), %edx			#copy int to %edx
	cmpl $100, %edx			    #check edx >= 100 and jump to greatequal if true
	jge greatequal
	
	addq $4, %rsi                #move to next position
	loop vec_check
	jmp end
	
greatequal:
	
	movl $0, (%rsi)			    #replace number with 0
	incl %eax					#increment eax
	addq $4, %rsi               #move to next position
	loop vec_check

end:
	ret
