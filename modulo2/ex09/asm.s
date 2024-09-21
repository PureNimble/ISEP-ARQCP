.section .data

	.global A, B, C, D
	
.section .text

.global sum_and_subtract
sum_and_subtract:
	movl A(%rip), %eax #put A in eax
	movw B(%rip), %si  #put B in si
	movb C(%rip), %cl  #put C in cl
	movb D(%rip), %dl  #put D in dl
	
	movslq %eax, %rax  #move eax to rax
	movswq %si, %rsi   #move si to rsi
	movsbq %cl, %rcx   #move cl to rcx
	movsbq %dl, %rdx   #move dl to rdx
	
	addq %rcx, %rax    #A+C, store the value in rax
	subq %rdx, %rax    #(A+C)-D, store the value in rax
	addq %rsi, %rax    #(A+C-D)+B, store the value in rax
	ret				   #return
