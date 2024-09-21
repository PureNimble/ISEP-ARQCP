.section .data

	.global current, desired;
	
.section .text

.global needed_time
needed_time:
	movb current(%rip), %al     #move current to al
	movb desired(%rip), %sil    #move desired to sil
	
	movsbl %al, %eax            #move al to eax
	movsbl %sil, %esi           #move sil to esi
	
	cmpl %esi, %eax             #compare eax to esi
	jg decrease                 #if eax > esi jump to decrease
	jl increase                 #if eax < esi jump to increase
	movl $0, %eax               #move 0 to eax
	jmp end                     #jump to end
	
decrease:
	subl %esi, %eax             #eax - esi, store the value in eax
	
	imull $240, %eax            #eax * 240
	
	jmp end                     #jump to end
	
increase:
	subl %eax, %esi             #esi - eax, store the value in esi
	
	imull $180, %esi            #esi * 180
	movl %esi, %eax             #move esi to eax
	
end:
	ret                         #return
