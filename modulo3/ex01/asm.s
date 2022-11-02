.section .bss
.global ptr1
	.comm ptr1, 8		#declarar pointer (8 bytes)

.section .text
.global seven_count
seven_count:
	movq ptr1(%rip), %rsi    	#Move pointer to rsi
	movl $0,%eax				#counter = 0
	
str_copy:
	
	movb (%rsi), %dil	#copy the value
	cmpb $0, %dil		#check if this is the end of the string
	jz end				#jump to end
	cmpb $55, %dil		#check if the value is equal to '7' that is $55
	jne   notequal		#jump to not equal
	incl %eax			#increase the counter
	incq %rsi			#move to the next position
	jmp str_copy		# jump to the start of the cycle
notequal:
	incq %rsi			#move to the next position
	jmp str_copy		# jump to the start of the cycle
end:
	ret					#return

