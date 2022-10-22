.section .data

	.global num;
	
.section .text

.global check_num
check_num:
	movl num(%rip), %eax
	cltd
	movl $2, %ecx
	
	cmpl $0, %eax
	jl negative
	jge positive
	
negative:
	idivl %ecx
	cmpl $0, %edx
	jl odd
	movl $4, %eax
	jmp end
	
positive:
	idivl %ecx
	cmpl $0, %edx
	jg oddp
	movl $6, %eax
	jmp end

odd:
	movl $5, %eax
	jmp end

oddp:
	movl $7, %eax


end:
	ret
