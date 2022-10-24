.section .data

    .global op1,op2, op3
    
.section .text

.global sum3ints
sum3ints:
    movl op1(%rip), %eax  #put op1 in eax
    movl op2(%rip), %ecx  #put op2 in ecx
    movl op3(%rip), %edx  #put op3 in edx
    
    movslq %eax, %rax     #move eax to rax
    movslq %ecx, %rcx     #move ecx to rcx
    movslq %edx, %rdx     #move edx to rdx
    
    addq %rcx, %rax       #op1 + op2, store the value in rax
    addq %rdx, %rax       #(op1 + op2) + op3, store the value in rax
    ret                   #return
