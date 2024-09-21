#include <stdio.h>
#include "c.h"
 
int main(void){
	int x = 10;
	
	printf("X:%d\n", x);
	
	changes(&x);
	
	printf("X:%d\n", x);
	
	return 0;
}
