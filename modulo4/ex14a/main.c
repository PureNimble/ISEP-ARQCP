#include <stdio.h>
#include "count_bits_zero.h"
 
int main(void){
	
	int x = 46;
	int y;
	
	y = count_bits_one(x);
	
	printf("Number of active bits = %d\n", y);
	
	return 0;
}
