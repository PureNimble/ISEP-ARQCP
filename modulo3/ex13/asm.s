.section .data

	.global ptrvec
	.global num
	
.section .text

	.global keep_positives


##########################################################	
keep_positives:	
	movq $0,%rcx			# clear rcx
	movq ptrvec(%rip),%rsi	# move the pointer to rsi
	movw num(%rip), %cx		# move the number of elements of vec
	movw $0, %ax			# counter
	cmpw $0, %cx			# check if vec is null
	jz end

loop:
	
	cmpw $0, (%rsi)   		#compare 0 to rsi
	jl   index     			#if eax < 0 jump to index
	jmp  next				
	
index:	
	movw %ax,(%rsi)			# vec[i]=i
next: 
	addq $2,%rsi			#move to next number	
	incw %ax				# increase the counter
	loop loop         		# loop
end:
	
	ret 
##########################################################

