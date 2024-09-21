.section .data

.section .text

	.global greatest
	
#############################################	
greatest:
	#edi = a
	#esi = b
	#edx = c
	#ecx = d

	cmpl %esi,%edi			# a > b
	jg edi
	jmp esi
edi:
	cmpl %edx,%edi			# a < c
	jl edx					#jmp
	cmpl %ecx, %edi			# a < d
	jl ecx					#jmp
	movl %edi,%eax			# return a 
	jmp end

esi:
	cmpl %edx,%esi			# b < c
	jl edx					#jmp
	cmpl %ecx,%esi			# b < d
	jl edx					#jmp
	movl %esi, %eax			#return b
	jmp end
edx:
	cmpl %ecx,%edx			# c < d
	jl ecx					#jmp
	movl %edx,%eax			#return c
	jmp end
ecx:
	movl %ecx,%eax			#return d
end:
	ret						#return the value in rax
	
#############################################	
