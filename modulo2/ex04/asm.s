.section .data
	
    .global op1,op2,op3,op4			#Declaring the global variables
    
op3:
	.long 10
op4:
	.long 30
.section .text

.global sum_v3 
sum_v3:

	movl op1(%rip), %ecx #place op1 in ecx
	movl op2(%rip), %eax #place op2 in eax
	movq op3(%rip), %rbx #place op3 in eax
	movq op4(%rip), %rdx #place op3 in eax
	addq  %rbx, %rdx      #op4 + op3
	subq  %eax, %rdx      #(op4 + op3) - op2
	subq  %eax, %rdx      #(op4 + op3) - op2
	addq  %ecx, %rdx      #(op4 + op3 - op2) + op1
	addq  %ecx, %rdx	  #(op4 + op3 - op2 + op1) + op1
	pop   %eax
	movq  %rdx, %rax
	ret            #return the value in %rax
