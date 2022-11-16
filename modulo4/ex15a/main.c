#include <stdio.h>
#include "c.h"
 
int main(void){
	int a = 10;
	int left = 10;
	int right = 4;
	
	int y = activate_bits(a,left,right);
	
	printf("Bits activate:%d\n", y);
	
	return 0;
}
