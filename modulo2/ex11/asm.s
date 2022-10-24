.section .data

    .global op1,op2
    
.section .text

.global test_flags
test_flags:
    movl op1(%rip), %eax   #put op1 in eax
    movl op2(%rip), %ecx   #put op2 in ecx
    
    addl %ecx, %eax        #op1 + op2, store the value in eax
    
    jc carry_detected      #check for carry and if detected jump to carry_detected
    movl $0, %eax          #move 0 to eax
    jmp overlook           #jump to overlook
    
carry_detected:
    movl $1, %eax          #move 1 to eax
    jmp end		           #jump to end
    
overlook:
    jo overflow_detected   #check for overflow and if detected jump to overflow_detected
    movl $0, %eax          #move 0 to eax
    jmp end                #jump to end
    
overflow_detected:
    movl $1, %eax          #move 1 to eax
    
    
end:
    ret                    #return
