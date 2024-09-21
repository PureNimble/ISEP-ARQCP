.section .data
	
    .global op1,op2			#Declaring the global variables
    
CONST:
	.int 20                 #Defining a constant

.section .text

.global sum_v2   
sum_v2:

	
	movl op1(%rip), %ecx #place op1 in ecx
	movl op2(%rip), %eax #place op2 in eax
	movl CONST(%rip), %ebx #place op2 in eax
	subl  %ecx, %ebx    #  CONST - op1
	subl  %ecx, %ebx    #  (CONST - op1 - op1)
	addl  %ebx, %eax    #  (CONST - op1 - op1) + op2        


	ret            #return the value in %eax
