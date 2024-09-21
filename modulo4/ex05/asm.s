.section .data

.section .text

	.global inc_and_square
	
#############################################	
inc_and_square:

	#rdi = *v1
	#esi = v2

	incl (%rdi)			# increase v1
	
	movl %esi,%eax		# move v2 to the return
	imull %esi			# v2 * v2


	ret						#return the value in eax
	
#############################################	
