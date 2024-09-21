.section .data
	
.section .text

	.global sens_pluvio

#######################################################	
sens_pluvio:

	# %dil = ult_pluvio
	# %sil = ult_temp
	# %dl  = comp_rand
	
	cmpb $0,%dil			# check if ult_pluvio is less or equal 0
	jz zero
	cmpb $20,%sil			# check if ult_temp is greatter then 20 °C
	jg greater
	cmpb $10,%sil			# check if ult_temp is less then 10 °C
	jl less
	
	subb $5,%dl				# comp_rand -> number(0,10) - 5 = number(-5,5)
	addb %dl,%dil			# add the comp_rand to the ult_pluvio
	
	jmp end

greater:
	
	neg %dl					# change the number to negative
	addb %dl,%dil			# add the comp_rand to the ult_pluvio -> number(-10,0)
	jmp loop
less:	
	addb %dl,%dil			# add the comp_rand to the ult_pluvio -> number(0,10)
	jmp loop

loop:	
	cmpb $180,%dil		# check if  value > 180
	jg reduce
	cmpb $0,%dil		# check if value < 0
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
zero:
	subb $5,%dl				# comp_rand -> number(0,10) - 5 = number(-5,5)
	cmpb $0,%dl				# check if the random number is negative
	jle end				# if greater or equal go to end
	addb %dl,%dil			# if less change to 0
end:

	movb %dil,%al			# return the value 
	ret
	
#######################################################	
