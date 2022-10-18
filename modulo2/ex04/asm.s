.section .data
	
    .global op1,op2,op3,op4			#Declaring the global variables
    
op3:
	.long 10
op4:
	.long 30
.section .text

.global sum_v3 
sum_v3:

	movq op1(%rip), %rcx #place op1 in rcx int 
	movq op2(%rip), %rax #place op2 in rax int 
	movq op3(%rip), %rsi #place op3 in rbx long
	movq op4(%rip), %rdx #place op3 in rdx long
	addq  %rsi, %rdx      #op4 + op3
	subq  %rax, %rdx      #(op4 + op3) - op2
	subq  %rax, %rdx      #(op4 + op3 - op2) - op2
	addq  %rcx, %rdx      #(op4 + op3 - op2) + op1
	addq  %rcx, %rdx	  #(op4 + op3 - op2 + op1) + op1
	movq  %rdx, %rax
	ret            #return the value in %rax
