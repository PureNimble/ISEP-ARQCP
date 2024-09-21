#include <stdio.h>
#include "asm.h"
 
int main(void){
	
	int x = 30;	
	changes(&x);
	
	
	printf("Value:\n", x);

	
	return 0;
}
