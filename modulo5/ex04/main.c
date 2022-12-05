#include <stdio.h>
#include "asm.h"
int main(void){
	
	Student s1;
	Student array[5];
	char address[]= "boas";
	fill_student(&s1,20,20,"joao","porto");
	update_address(&s1, &address);
	
	return 0;
}
