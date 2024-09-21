.section .data
	
.section .text

	.global count_odd_matrix

#######################################################	
count_odd_matrix:

	# %rdi = **m matrix pointer
	# %esi = y -> line
	# %edx = k -> column
	
	
	movl $0,%eax						# declaration of the counter
	movl %edx,%ecx						# save the number of columns

looplines:

	cmpl $0, %esi 						# check for the end of the lines				
	jz end
	movq (%rdi), %r9					# get the column pointer				
										
										# go to the second loop					 

loopcolumn:
	cmpl $0, %edx 						# check for the end of the columns of one line			
	jz nextline 						

	movl (%r9), %r8d 					# get the number					
	andl $1, %r8d  						# get the first bit	
	
	cmpl $0, %r8d 						# check if it is 1 ( if the first bit is 1 than the number is odd)	
	jz even
	
	incl %eax							# increase the counter
	
even:
	decl %edx 							# decrease the index of columns				
	addq $4, %r9						# move to the next column 								
	jmp loopcolumn 						# loop

nextline:
	movl %ecx, %edx 					# reset the column index						
	addq $8, %rdi						# move to the next line					 
	decl %esi 							# decrease the index of lines						
	jmp looplines								  											 
									
end:
	
	ret
	
#######################################################	
