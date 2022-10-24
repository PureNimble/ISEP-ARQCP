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

f4a:

end:
	ret
