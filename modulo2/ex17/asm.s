.section .data

	.global x,y

.section .text

.global sum,subtraction,multiplication,division,modulus,power2,power3
sum:
	
	movl  x(%rip),%eax
	addl  y(%rip),%eax
	
	ret
subtraction:

	movl  x(%rip),%eax
	subl  y(%rip),%eax
	
	ret
	
multiplication:
	
	movl   x(%rip),%eax
	imull  y(%rip),%eax
	
	ret
division:

	movl   x(%rip),%eax
	movl   y(%rip),%esi
	idivl  %esi
	
	ret
	
modulus:
	   
	movl   x(%rip),%eax
	cmpl   $0, %eax
	jl     operation
	jmp    end
	
operation:
	
	not    %eax
	incl   %eax
end:
	ret
power2:  

	movl   x(%rip),%eax
	imull  %eax,%eax
	
	ret
	
power3:

	movl   x(%rip),%eax 
	imull  %eax,%eax
	imull  %eax,%eax
	
	ret
