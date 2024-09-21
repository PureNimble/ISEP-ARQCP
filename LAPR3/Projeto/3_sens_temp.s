.section .data
	
.section .text

	.global sens_temp

#######################################################	
sens_temp:

	# %dil = ult_temp
	# %sil = comp_rand
	
	subb $5, %sil		# comp_rand -> number(0,10) - 5 = number(-5,5)
	addb %sil,%dil		# comp_rand + ult_temp

	cmpb $0,%dil
	jz end
loop:	
	cmpb $37,%dil		# check if  value > 38
	jg reduce
	cmpb $0,%dil		# check if value < -5
	jl increase
	jmp end			# jmp to end
	
reduce:					# reduce the number by 20%
	shlb $3, %dil		# x * 8 
	movb %dil,%cl
	shrb %cl			# x / 2
	shrb $3,%dil		# x / 8
	addb %cl,%dil		# (x / 2) + (x / 8) = x / 10

	jmp end
increase:				# increase the number by 20%
	neg %dil
	movb %dil,%cl
	shlb $3, %dil		# x * 8 
	shlb $2, %cl		# x * 4 
	addb %cl,%dil		# (x * 8) + (x * 4) = x * 12
	movb %dil,%cl
	shrb %cl			# x / 2
	shrb $3,%dil		# x / 8
	addb %cl,%dil		# (x / 2) + (x / 8) = x / 10
	jmp end
end:
	movb %dil,%al		# return

	ret

#######################################################	
