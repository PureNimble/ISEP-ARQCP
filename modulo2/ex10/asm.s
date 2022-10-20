.section .data

    .global op1,op2, op3
    
.section .text

.global sum3ints
sum3ints:
    movl op1(%rip), %eax
    movl op2(%rip), %ebx
    movl op3(%rip), %ecx
    
    movslq %eax, %rax
    movslq %ebx, %rbx
    movslq %ecx, %rcx
    
    addq %rbx, %rax
    addq %rcx, %rax
    ret
