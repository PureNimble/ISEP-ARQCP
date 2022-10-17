.section .data
    .global op1
    .global op2

.section .text

.global sum # void sum(void)
sum:

	movl op1(%rip), %ecx #place op1 in ecx
	movl op2(%rip), %eax #place op2 in eax
	addl %ecx, %eax #add ecx to eax. Result is in eax

	ret            #return the value in %eax
