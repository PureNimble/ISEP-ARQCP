#include <stdio.h>
#include "asm.h"
 
int main(void){
	int x = 10;
	int pos = 4;
	int * ptr = &x;
	
	y = reset_bit(ptr,pos);
	
	if(y == 1){
		printf("The %d bit, was changed from 0 to 1 \n", pos);
	}else{
		printf("The %d bit, wasn't changed\n", pos);
	}
	
	return 0;
}
