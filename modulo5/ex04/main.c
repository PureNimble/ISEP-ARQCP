#include <stdio.h>
#include "asm.h"
int main(void){
	
	Student s1;
	char grades[5]={15,10,0,20};
	update_grades(s1,grades);
	
	return 0;
}
