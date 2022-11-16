.section .data


.section .text

	.global proc
	.global call_proc
	
#############################################	
proc:
	
	
	#%edi 1 parameter int x1
	#%rsi 2 parameter int *p1
	#%edx 3 parameter int x2
	#%rcx 4 parameter int *p2
	#%r8w 5 parameter short x3
	#%r9  6 parameter short *p3
	#pop r10 7 parameter char x4
	#pop r11 8 parameter char *p4
	
	# prologue
	
	pushq %rbp				# save the original value of rbp
	movq %rsp, %rbp			# copy the current stack pointer to rbp
	
	movq 16(%rbp), %r10		# 7 parameter (char x4)
	movq 24(%rbp), %r11		# 8 parameter (char *p4)
	
	movl %edi, (%rsi)		# move x1 to *p1
	addl %edx, (%rsi)		# x1 + x2 = *p1
	movl %edx, (%rcx)		# move x2 to *p2
	subl %edi, (%rcx)		# x2 - x1 = *p2
	movw %r8w, (%r9)		# move x3 to *p2
	addw %dx,  (%r9)		# x3 + x2 = *p3
	leaq (%r10,%r10,2),%rax	# 3 * x4
	movb %al, (%r11)		# 3 * x4 = *p4
	
	#epilogue

	movq %rbp, %rsp			# retrieve thr original rsp value
	popq %rbp				# restore the original rbp value
	
	ret
	
#############################################
call_proc:
	
	#edi = int a  = x1
	#esi = int b  = x2
	#edx = int c  = x3 (%dx)
	#ecx = int d  = x4 (%cl)
	
	# prologue
	
	pushq %rbp				# save the original value of rbp
	movq %rsp, %rbp			# copy the current stack pointer to rbp
	
	subq $32, %rsp			# reserve 32 bits for local variables
	
	# function body
	

	
	movl %ecx,%r10d			# move x4 to r10d
	
	movl %edi, -8 (%rbp)	# x1 -> local variable
	movl %esi, -16(%rbp)	# x2 -> local variable
	movl %edx, -24(%rbp)	# x3 -> local variable
	movl %r10d,-32(%rbp)	# x4 -> local variable
	
	
	
	leaq -8 (%rbp), %rsi	# &x1
	leaq -16(%rbp), %rcx	# &x2
	leaq -24(%rbp), %r9		# &x3
	leaq -32(%rbp), %r11	# &x4
	
	pushq %rsi
	pushq %rcx
	pushq %r9
	pushq %r11
	
	movw %dx, %r8w			# x3
	movl %esi, %edx			# x2
	pushq %r11				# 8 parameter *p4
	pushq %r10				# 7 parameter char x4
	
	

	call proc				# call the function (int x1, int *p1, int x2, int *p2, short x3, short *p3, char x4, char *p4)
	addq $16,%rsp
	
	popq %r11
	popq %r9
	popq %rcx
	popq %rsi
	
	movl (%rsi), %eax	#x1
	movl (%rcx), %r10d	#x2
	movl (%r9),  %edi	#x3
	movl (%r8),  %r11d	#x4

	addl %r10d, %eax			# (x1 + x2)
	subl %r11d, %edi			# (x3 - x4)
	imull %edi, %eax			# (x1 + x2) * (x3 - x4)

	#epilogue
	
	movq %rbp, %rsp			# retrieve thr original rsp value
	popq %rbp				# restore the original rbp value

	ret
	
#############################################	
