.section .data
	
.section .text

	.global greater_date

#######################################################	
greater_date:

	# %edi = date1
	# %esi = date2

	
	#prologue
	pushq %rbp  		# save the original value of RBP  
	movq %rsp, %rbp 	# copy the current stack pointer to RBP
	
#------------------------------------------------------
	pushq %rsi			# push date2
	pushq %rdi			# push date1

	rorl $8,%edi		# di = year1
	rorl $8,%esi		# si = year2
	
	cmpw %si,%di		# compare (di = year1 , si = year2)
	jg date1			
	jl date2
	
	roll $8,%edi		# dil = month1
	roll $8,%esi		# sil = month2
	
	cmpb %sil,%dil		# compare (dil = month1 , sil = month2)
	jg date1			
	jl date2
	
	rorl $24,%edi		# dil = day1
	rorl $24,%esi		# sil = day2
	
	cmpb %sil,%dil		# compare (dil = day1 , sil = day2)
	jg date1			
	jl date2
	
	roll $24,%edi		# restore the number
	movl %edi,%eax		# date is equal, return esi or edi

	jmp end
date1:
	movq -16(%rbp),%rdi
	movl %edi,%eax		# return date1
	jmp end
date2:
	movq -8(%rbp),%rsi
	movl %esi,%eax		# return date2
#------------------------------------------------------
end:		
	#epiloque 
	movq %rbp, %rsp 	# retrieve the original RSP value
	popq %rbp			# restore the original RBP value
	
	ret
	
#######################################################	
