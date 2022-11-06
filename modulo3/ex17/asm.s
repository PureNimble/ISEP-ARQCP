.section .data

	.global ptr1, ptr2, num
	
.section .text
.global swap
swap:

	movq ptr1(%rip), %rsi		# move the pointer 1 to rsi
	movq ptr2(%rip), %rdi		# move the pointer 2 to rdi
	movl num(%rip), %ecx        # move num to ecx for counter

str_swap:

	cmpl $0,%ecx				#check if is the end of the cycle
	jz end						#jump to end	
	
	movb (%rsi), %al			#copy char from string 1 to al
	movb (%rdi), %dl            #copy char from string 1 to dl
					
	movb %dl, (%rsi)			#swap
	movb %al, (%rdi)            #swap
					
	incq %rsi                   #move to next position
	incq %rdi				    #move to next position
	loop str_swap

end:
	ret
