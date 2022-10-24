.section .data

	.global currentSalary, code;
	
.section .text

.global new_salary
new_salary:
	movw currentSalary(%rip), %ax     #move currentSalary to ax
	movw code(%rip), %cx              #move code to cx
	
	cmpw $20, %cx                     #compare 20 to cx
	jl othercode                      #if cx < 20 jump to othercode
	je code20                         #if cx = 20 jump to code20
	
	cmpw $22, %cx                     #compare 22 to cx
	jg othercode                      #if cx > 22 jump to othercode
	je code22                         #if cx = 22 jump to code22
	jl code21                         #if cx < 22 jump to code21
	
code20:
	addw $400, %ax                    #currentSalary + 400, store the value in ax
	jmp end                           #jump to end

code21:
	addw $300, %ax                    #currentSalary + 300, store the value in ax
	jmp end                           #jump to end

code22:
	addw $200, %ax                    #currentSalary + 200, store the value in ax
	jmp end                           #jump to end

othercode:
	addw $150, %ax                    #currentSalary + 150, store the value in ax
	
	
end:
	ret                               #return
