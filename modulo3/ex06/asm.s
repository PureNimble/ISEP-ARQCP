.section .bss

	.global ptr1
	.comm ptr1, 8
	
.section .text
.global encrypt
encrypt:

	movq ptr1(%rip), %rsi		# move the pointer 1 to rsi
	movl $0, %eax

str_copy:

	movb (%rsi), %cl			#copy char to cl
	cmpb $0,%cl					#check if is the end of the string
	jz end						#jump to end	
	
	cmp $32,%cl					#check if cl is equal to space ($32)
	je equal
	cmp $97,%cl				    #check if cl is equal to 'a' ($97)
	je equal
	
	addb $3, %cl				
	movb %cl, (%rsi)			#move the char to the new string
					
	incq %rsi                   #move to next position
	incl %eax				    #increment counter
	jmp str_copy
	
equal:
	
	movb %cl, (%rsi)			#move the char to the new string
						
	incq %rsi					#move to next position
	jmp str_copy

end:
	
	movb $0, (%rsi)			    #put a 0 in the end of the string 
	ret
