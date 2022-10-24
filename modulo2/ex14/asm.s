.section .data
	length1:
		.int 4    #declare length1 = 4
	length2:
		.int 2    #declare length2 = 2
	height:
		.int 5    #declare height = 5
		
.global length1, length2, height

.section .text

.global getArea
getArea:
	movl length1(%rip), %eax   #move length1 to eax
	movl length2(%rip), %esi   #move length2 to esi
	movl height(%rip), %ecx    #move height to ecx
	addl %esi, %eax            #length1 + length2, store the value in eax
	mull %ecx                  #(length1 + length2)*height, store the value in eax
	movl $2, %esi              #move 2 to esi
	
	divl %esi                  #(length1 + length2)*height/2, store the value in eax
	
end:
	ret                        #return
