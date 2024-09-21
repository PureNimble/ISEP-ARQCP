.section .data

	.global A,B
	
.section .text

.global isMultiple
isMultiple:
	movq A(%rip), %rax    #put A in rax
	movq B(%rip), %rcx    #put B in rcx
	
	divq %rcx             #rax/rcx, store the rest in rdx
	
	cmpq $0, %rdx         #compare 0 to rdx	
	je isequal            #if rdx = 0 jump to isequal
	
	movq $0, %rax         #move 0 to rax
	jmp end               #jump to end
	
isequal:
	movq $1, %rax         #move 1 to rax
	
end:
	ret                   #return
