#include <stdio.h>
#include "asm.h"
 
int main(void){
	
	int vec[] = {1,2,3,4};	
	int num = 4;
	changes_vec(vec,num)
	
	for( int i; num > i ; i++){
		printf("Value:%d\n",vec[i] );
	}
	return 0;
}
