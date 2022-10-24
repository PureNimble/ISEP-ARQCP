.section .data

	.global length1, length2, height
	
.section .text

.global getArea
getArea:
	movl length1(%rip), %eax   #put lenght1 in eax
	movl length2(%rip), %esi   #put lenght2 in esi
	movl height(%rip), %ecx    #put height in ecx
	addl %esi, %eax            #lenght1 + length2, store the value in eax
	mull %ecx                  #(length1+length2)*height, store the value in eax
	movl $2, %esi              #move 2 to esi
	
	divl %esi                  #(length1+length2)*height/2, store the value in eax
	
end:
	ret                        #return
