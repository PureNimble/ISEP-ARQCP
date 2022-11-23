.section .data

	.global ptrvec
	.global num
	
.section .text

	.global count_max
	
#############################################	
count_max:

	movq ptrvec(%rip), %rsi		# move the pointer 1 to rsi
	movl num(%rip), %ecx        # move num to ecx for counter
	movl $0, %eax				# clear the sum variable
	cmpl $0, %ecx				# check if vec is null
	jz end
loop:
	movl (%rsi), %edi			# vec[i]
	movl 4(%rsi),%edx			#vec[i+1]
	movl 8(%rsi),%r8d			#vec[i+2]
	
	cmp %edi,%edx				#vec[i] >= vec[i+1]
	jle	no_equal
	cmp %edx,%r8d				#vec[i+1] <= vec[i+2]
	jge no_equal
	
	incl %eax					# satisfy the condition (counter++)
	
no_equal:
 
	addq $4,%rsi				# move to the next number
	
	loop loop					#loop
end:
	ret							#return
	
#############################################	
