.section .data
	
.section .text

	.global sens_dir_vento

#######################################################	
sens_dir_vento:

	# %di = ult_dir_vento
	# %si = comp_rand
loop:	
	subw $180,%si			# comp_rand -> number(0,360) - 180 = number(-180,180)
	addw %si,%di			# add the comp_rand to the ult_dir_vento
	movw %di,%ax			
	
	cmpw $359,%ax			# check if is not greatter then 359
	jg reduce				# if it is go to reduce 
	
	cmpw $0,%ax				# check if is not less then 0
	jl increase				# if it is go to increase 
	
	jmp end					# return valid number
	
reduce:					# reduce the number by 20%
	salw $3, %ax		# x * 8 
	movw %ax,%cx
	sarw %cx			# x / 2
	sarw $3,%ax			# x / 8
	addw %cx,%ax		# (x / 2) + (x / 8) = x / 10

	jmp loop
	
increase:				# increase the number by 20%
	movw %ax,%cx
	salw $3, %ax		# x * 8 
	salw $2, %cx		# x * 4 
	addw %cx,%ax		# (x * 8) + (x * 4) = x * 12
	movw %ax,%cx
	sarw %cx			# x / 2
	sarw $3,%ax			# x / 8
	addw %cx,%ax		# (x / 2) + (x / 8) = x / 10
	
	jmp loop

end:

	ret
	
#######################################################	
