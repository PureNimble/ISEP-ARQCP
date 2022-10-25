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
	movl i(%rip), %eax
	movl j(%rip), %esi
	cmp  %esi, %eax
	jge if3
	
	leal (%eax, %esi), %edi
	addl $2, %esi
	addl $esi, %eax
	jmp next3
if3:
	imul %eax, %esi
	movl %esi, %edi
	incl %eax
	
next3:
	idivl %edi
	
	ret
f4a:
	movl i(%rip), %eax
	movl j(%rip), %esi
	leal (%eax,%esi),%edi
	cmp  $10, %edi
	jl if4
	movl $3, %esp
	imull %esi,%esi
	movl %esi, %eax
	idivl %esp
	jmp end
if4: 	
	imull %eax,%eax
	sall  $2,%eax
end:
	ret
