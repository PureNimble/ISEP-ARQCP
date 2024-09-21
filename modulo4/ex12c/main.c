#include <stdio.h>
#include "asm.h"
 
int main(void){
	
	short vec[]= {1,2,3,4};
	int num= 4;
	
	int y = vec_count_bits_one(vec,num);
	
	printf("Number of inactive bits: %d\n", y);
	
	
	return 0;
}
