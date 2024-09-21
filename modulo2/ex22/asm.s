.section .data

	.global i,j

.section .text

.global fa,f2a,f3a,f4a

fa:
	movl i(%rip), %eax
	movl j(%rip), %esi
	cmp  %eax, %esi
	je  if1
	addl %esi, %eax
	decl %eax
	jmp  end
if1:
	subl %esi, %eax
	incl %eax
f2a:
	movl i(%rip), %eax
	movl j(%rip), %esi
	cmp  %esi, %eax
	jg if2
	incl %esi
	jmp next
if2:	
	decl %eax
next: 
	imull %esi, %eax
	
	ret
f3a:
	movl i(%rip), %eax		#Put i in a register
	movl j(%rip), %esi		#Put j in a register
	cmp  %esi, %eax			#compare i with j
	jge if3					#jump if i is greater or equal

	leal (%esi, %eax), %edi	# i + j and put it in register
	addl %esi, %eax			# j + i
	addl $2, %eax			# 2 +( j + i)		
	jmp next3				#jump to the end of the if
if3:
	imull %eax, %esi		# i * j
	movl  %esi, %edi		#move esi to edi			
	incl  %eax				# i + 1
	
next3:
	idivl %edi				# divide eax / edi
	
	ret
f4a:
	movl i(%rip), %eax   	#Put i in a register
	movl j(%rip), %esi		#Put j in a register	
	leal (%eax,%esi),%edi	# i + j and is being register in %edi
	cmp  $10, %edi			#compare 10 with edi
	jl if4					#jump if edi is less than 10
	movl $3, %ecx			#			
	imull %esi,%esi
	movl %esi, %eax
	idivl %ecx
	jmp end
if4: 	
	imull %eax,%eax
	sall  $2,%eax
end:
	ret
