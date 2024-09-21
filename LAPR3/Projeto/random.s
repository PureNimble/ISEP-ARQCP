.section .data

	.global state, inc
	
.section .text

	.global pcg32_random_r
	
#############################################	
pcg32_random_r:

	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------

	movq state(%rip),%rax					# rax = state
	movq inc(%rip),%rsi						# rsi = inc
	
	
	movq $6364136223846793005ULL,%rdi		# put the value into a register
	
	pushq %rax								# save old state 
	
	mulq %rdi								# oldstate * 6364136223846793005ULL
	orq  $1,%rsi							# (inc|1)
	addq %rax,%rsi							# rsi = state
	
	popq %rax								# pop the old state
	
	movq %rsi,state(%rip)					# move the value to the global variable
	
	movq %rax,%rdx							# save oldstate in rdx
	shrq $18u, %rdx							# oldstate >> 18u
	
	xorq %rax,%rdx							# (oldstate >> 18u) ^ oldstate)
	shrq $27u,%rdx							# xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u
	shrq $59u,%rax							# rot = oldstate >> 59u
	
	movl %eax,%ecx
	
	rorl %ecx,%edx							# rorl xorshifted (rot) times
	
	movl %edx,%eax

#------------------------------------------------------
	
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#############################################	
