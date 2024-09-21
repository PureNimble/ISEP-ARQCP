.section .data

	.global A, B, C, D
	
.section .text

.global compute
compute:
	
	
	movl A(%rip), %eax    #put A in eax
	movl B(%rip), %ecx    #put B in ecx
	movl C(%rip), %esi    #put C in esi
	movl D(%rip), %edi    #put D in edi
	
	imull %ecx, %eax      #A*B, store the value in eax
	subl %esi, %eax       #(A*B)-C, store the value in eax

	idivl %edi            #((A*B)-C)/D, store the value in eax
	
	ret                   #return
