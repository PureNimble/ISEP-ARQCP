.section .data

	.global num;
	
.section .text

.global check_num
check_num:
	movl num(%rip), %eax   #move num to eax
	cltd
	movl $2, %ecx          #move 2 to ecx
	
	cmpl $0, %eax          #compare 0 to eax
	jl negative            #if eax < 0 jump to negative
	jge positive           #if eax >= 0 jump to positive
	
negative:
	idivl %ecx             #eax/ecx, store the rest in edx
	cmpl $0, %edx          #compare 0 to edx 
	jl odd                 #if edx < 0 jump to odd
	movl $4, %eax          #move 4 to eax
	jmp end                # jump to end
	
positive:
	idivl %ecx             #eax/ecx, store the rest in edx
	cmpl $0, %edx          #compare 0 to edx
	jg oddp                #if edx > 0 jump to oddp
	movl $6, %eax          #move 6 to eax
	jmp end                #jump to end

odd:
	movl $5, %eax          #move 5 to eax
	jmp end                #jump to end

oddp:
	movl $7, %eax          #move 7 to eax


end:
	ret                    #return
