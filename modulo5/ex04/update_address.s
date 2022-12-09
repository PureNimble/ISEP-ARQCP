.section .data
	
	.equ ADDRESS_OFFSET, 84			# the address starts at the byte 84
.section .text

	.global update_address
	
#############################################	
update_address:

	#rdi = *s pointer of the struct
	#rsi = *new_adress pointer of the newadress
	
	addq $ADDRESS_OFFSET,%rdi

loop:
	movb (%rsi),%al		# move the char to a register
	
	cmp	$0,%al			# check for the end of the string
	jz end
	
	movb %al,(%rdi)		# move the char to the address in the struct			
	
	incq %rdi			# move to the next space
	incq %rsi			# move th the next char
	jmp loop
end:
	movb $0, (%rdi)
	
	ret					# return the value in eax
	
#############################################	
