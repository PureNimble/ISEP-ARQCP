#include <stdio.h>
#include "c.h"
 
int main(void){
	int a = 10;
	int b = 10;
	int pos = 4;
	
	int y = join_bits(a,b,pos);
	
	printf("Bits activate:%d\n", y);
	
	return 0;
}
