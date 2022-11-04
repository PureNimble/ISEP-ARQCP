.section .bss

	.global ptr1, ptr2
	.comm ptr1, 8
	.comm ptr2, 8
	
.section .text
.global str_copy_porto2
str_copy_porto2:

	movq ptr1(%rip), %rsi		# move the pointer 1 to rsi
	movq ptr2(%rip), %rdi		# move the pointer 2 to rdi

str_copy:
	movb (%rsi), %cl			#copy char to cl
	cmpb $0,%cl					#check if is the end of the string
	jz end						#jump to end
	
	
	cmp $79,%cl					#check if cl is equal to 'O' ($79)
	je equal
	cmp $111,%cl				#check if cl is equal to 'o' ($79)
	je equal
	movb %cl, (%rdi)			#move the char to the new string
	incq %rsi					#move to next position
	incq %rdi					#move to next position
	jmp str_copy
	
equal:	
	addb $6, %cl				#convert 'o' to 'u'
	movb %cl, (%rdi)			#move the char to the new string
	incq %rsi					#move to next position
	incq %rdi					#move to next position
	jmp str_copy
end:	
	movb $0, (%rdi)			#put a 0 in the end of the string 
	ret
