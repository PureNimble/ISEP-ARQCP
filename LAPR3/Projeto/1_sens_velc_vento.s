.section .data
	
.section .text

	.global sens_velc_vento

#######################################################	
sens_velc_vento:

	# %dil = ult_velc_vento
	# %sil = comp_rand
	
	subb $10, %sil		# comp_rand -> number(0,20) - 10 = number(-10,10)
    addb %sil, %dil		# add the comp_rand to the ult_velc_vento

	cmpb $0,%dil
	jz end
loop:
	cmpb $60,%dil
	jg reduce
	cmpb $0,%dil
	jl  increase
	jmp end

increase:				# increase the number by 20%
	neg %dil
	movb %dil,%cl
	salb $3, %dil		# x * 8 
	salb $2, %cl		# x * 4 
	addb %cl,%dil		# (x * 8) + (x * 4) = x * 12
	movb %dil,%cl
	sarb %cl			# x / 2
	sarb $3,%dil			# x / 8
	addb %cl,%dil		# (x / 2) + (x / 8) = x / 10
	
	jmp loop
reduce:					# reduce the number by 20%
	salb $3, %dil		# x * 8 
	movb %dil,%cl
	sarb %cl			# x / 2
	sarb $3,%dil			# x / 8
	addb %cl,%dil		# (x / 2) + (x / 8) = x / 10

	jmp loop


end:
    movb %dil, %al		#return

	ret
	
#######################################################	
