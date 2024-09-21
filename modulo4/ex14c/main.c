#include <stdio.h>
#include "asm.h"
 
int main(void){
	int x = 10;
	int pos = 4;
	int * ptr = &x;
	
	
	printf("Before: %d\n", x);
	
	reset_2bits(ptr,pos);
	
	printf("After: %d\n", x);

	
	return 0;
}
