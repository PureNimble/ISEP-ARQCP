.section .data
.global ptrgrades
.global ptrfreq
.global num

.section .text
.global frequencies

#########################################################
frequencies:

	pushq %r8
	pushq %r9
	pushq %r12
	pushq %r10
	pushq %rdx
	pushq %rsi
	pushq %rdi
	
	movq ptrgrades(%rip),%rsi						# move grades pointer to rsi
	movq ptrfreq(%rip),%rdi							# move freq pointer to rdi	
	movb $21,%r10b									# size of freq[]
	movl num(%rip),%edx								# size of grades[]
		
	movb $0,%r8b									# i = 0
	movq $0,%r9										# j = 0	
		

#########################################################
first_loop:											# for (int i =0; i< 21;i++)
	
	cmpb %r8b,%r10b									#  i < size 
	je end
	
	movl $0,%eax									# counter = 0					
	cmpl $0,%edx									# check if grades[]= NULL
	jz first_loop_continuation

#########################################################
second_loop:										# for (int j = i+1 ; i< num;j++)

	cmpq %r9,%rdx									#   j < size  
	je first_loop_continuation
	
	cmpb %r8b,(%rsi,%r9,1)							# check if vec[j]= i 
	je found										
	
	jmp second_loop_continuation					# jmp second_loop_continuation
	
	
found:

	incl %eax										# counter++
	
second_loop_continuation:
	
	incq %r9										# j++
	jmp second_loop									# jmp second_loop
	

#########################################################
first_loop_continuation:
	
	movsbq %r8b,%r12								# %r12 = i
	movl %eax,(%rdi,%r12,4)							# freq[i] = counter
	incb %r8b										# i++
	
	movq $0,%r9										# clear j			

	jmp first_loop									# jmp first_loop
	
	
#########################################################
end:
	popq %rdi
	popq %rsi
	popq %rdx
	popq %r10
	popq %r12
	popq %r9
	popq %r8
	
	ret

#########################################################
