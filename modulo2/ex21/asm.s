.section .data

	.global currentSalary, code;
	
.section .text

.global new_salary
new_salary:
	movw currentSalary(%rip), %ax
	movw code(%rip), %cx
	
	cmpw $20, %cx
	jl othercode
	je code20
	
	cmpw $22, %cx
	jg othercode
	je code22
	jl code21
	
code20:
	addw $400, %ax
	jmp end

code21:
	addw $300, %ax
	jmp end

code22:
	addw $200, %ax
	jmp end

othercode:
	addw $150, %ax
	
	
end:
	ret
