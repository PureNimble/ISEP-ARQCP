.section .data
.global ptrsrc
.global num

.section .text
.global sort_without_reps


sort_without_reps:
    
    pushq %rbx
    pushq %r12 
    
    movq ptrsrc(%rip),%rsi                      # move pointer src to rsi
    movq ptrdest(%rip),%rdi						# move pointer dest to rdi
    movslq num(%rip),%rcx                       # move size of the vecs to rcx
    movq $0,%r8                                 # i = 0
    
    cmpq $0,%rcx                                # check if vec = NULL
    jz end
    
    
first_loop:                                     # for(int i=0;i<num;i++)

    movq $0,%r9                                 # j = 0
    addq %r8,%r9                                # j = i
    incq %r9                                    # j = i+1
    
    cmpq %r8,%rcx                               # i < num
    jg second_loop                              # jmp num is greater
    
    jmp end                                     # end


second_loop:
    
    cmpq %r9,%rcx                               # j < num
    jle continuation_loop                       # jmp next i
    
    movw (%rsi,%r8,2),%bx                       # vec[i]
    movw (%rsi,%r9,2),%r12w                     # vec[j]
        
    cmpw %bx,%r12w                              # vec[i] < vec[j]
    jl swap_elements                            # jmp r12d is greater
    
    incq %r9                                    # j++
    jmp second_loop
    
    
    
swap_elements:            
    
    movw %r12w,(%rsi,%r8,2)                     # swap
    movw %bx,(%rsi,%r9,2)                       # swap
    
    incq %r9                                    # j++
    jmp second_loop                                
        
    

continuation_loop:
    incq %r8                                    # i++
    jmp first_loop

    
end:
    popq %r12                                    
    popq %rbx
    ret
	 

	
