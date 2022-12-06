#include <stdio.h>
#include "asm.h"
int main(void){
	
	Student s1;
	Student array[5];
	char address[]= "boas";
	
	update_(&s1, &address);
	
	return 0;
}
