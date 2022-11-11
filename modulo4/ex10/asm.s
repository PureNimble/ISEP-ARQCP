.section .data


.section .text

	.global incr
	.global call_incr
	
#############################################	
incr:
	
	#rdi = short *p1
	#sil = char val
	
	movswl (%rdi), %eax			# x = (int)*p1
	movsbl %sil, %esi			# (int)val
	addl %eax, %esi				# y = x + val


	
	movw %si, (%rdi)			# *p1 = y
	

	ret							#return x
	
#############################################
call_incr:
	
	#di = short w
	
	addw  $3, %di			# x1 = w + 3
	pushw %di				# push
	movq  %rsp, %rdi		# &x1
	movb  $0xC3,%sil		# 2 parameter 0xC3
	
	
	call incr				# call the function
	
	popw %di				# pop
	
	movswl %di,%edx
	addl %edx,%eax			# x1 + x2
	
	
	ret
	
#############################################	
