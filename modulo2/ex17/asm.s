.section .data

	.global x,y

.section .text

.global sum,subtraction,multiplication,division,modulus,power2,power3
sum:
	
	movl  x(%rip),%eax    #move x to eax
	addl  y(%rip),%eax    #x+y, store the value in eax
	
	ret                   #return
subtraction:

	movl  x(%rip),%eax    #move x to eax
	subl  y(%rip),%eax    #x-y, store the value in eax
	
	ret                   #return
	
multiplication:
	
	movl   x(%rip),%eax   #move x to eax
	imull  y(%rip),%eax   #x*y, store the value in eax
	
	ret                   #return
division:

	movl   x(%rip),%eax   #move x to eax
	movl   y(%rip),%esi   #move y to esi
	idivl  %esi           #x/y, store the value in eax
	
	ret                   #return
	
modulus:
	   
	movl   x(%rip),%eax   #move x to eax
	cmpl   $0, %eax       #compare 0 to eax
	jl     operation      #if eax < 0 jump to operation
	jmp    end            #jump to end
	
operation:
	
	not    %eax           #bitwise inverse
	incl   %eax           #increment eax
end:
	ret                   #return
power2:  

	movl   x(%rip),%eax   #move x to eax
	imull  %eax,%eax      #x*x
	
	ret
	
power3:

	movl   x(%rip),%eax   #move x to eax
	movl %eax, %ecx       #move eax to ecx
	imull  %eax,%eax      #x*x
	imull  %ecx,%eax      #x*x*x
	
	ret                   #return
