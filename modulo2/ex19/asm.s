.section .data

	.global current, desired;
	
.section .text

.global needed_time
needed_time:
	movb current(%rip), %al
	movb desired(%rip), %sil
	
	movsbl %al, %eax
	movsbl %sil, %esi 
	
	cmpl %esi, %eax
	jg decrease
	jl increase
	movl $0, %eax
	jmp end
	
decrease:
	subl %esi, %eax
	
	imull $240, %eax
	
	jmp end
	
increase:
	subl %eax, %esi
	
	imull $180, %esi
	movl %esi, %eax
	
end:
	ret
