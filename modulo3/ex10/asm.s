.section .bss

	.global ptr1, ptr2, ptr3
	.comm ptr1, 8
	.comm ptr2, 8
	.comm ptr3, 8
	
.section .text
.global str_cat
str_cat:

	movq ptr1(%rip), %rsi		# move the pointer of vec to rsi
	movq ptr2(%rip), %rdi
	movq ptr3(%rip), %rdx
	
str:
	
	movb (%rsi), %cl			#copy char to cl
	cmpb $0,%cl					#check if is the end of the string
	jz str2
	
	movb %cl, (%rdx)
	incq %rsi
	incq %rdx
	jmp str

str2:

	movb (%rdi), %cl			#copy char to cl
	cmpb $0,%cl					#check if is the end of the string
	jz end

	movb %cl, (%rdx)
	incq %rdi
	incq %rdx
	jmp str2
	
end:
	movb $0, (%rdx)
	ret
