#include <stdio.h>
#include "c.h"
 
int main(void){
	
	int num = 10;
	int nbits = 3;
	
	int left rotate_left ();
	int right = rotate_right();
	
	printf("Rotate %d bits left = %d\n",nbits,left);
	printf("Rotate %d bits right = %d\n",nbits,right);
	
	return 0;
}
