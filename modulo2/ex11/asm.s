.section .data

    .global op1,op2
    
.section .text

.global test_flags
test_flags:
    movl op1(%rip), %ecx
    movl op2(%rip), %edx
    
    addl %ecx, %edx
    
    jc carry_detected
    movq $0, %rax
    jmp overlook
    
carry_detected:
    movq $1, %rax
    jmp end
    
overlook:
    jo overflow_detected
    movq $0, %rax
    jmp end
    
overflow_detected:
    movq $1, %rax
    
    
end:
    ret
