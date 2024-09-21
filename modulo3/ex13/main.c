#include <stdio.h>
#include "asm.h"

short vec[]={1,-2,3,-4,5,6};
unsigned short num = 6;
short *ptrvec = vec;
int main()
{
	
	
	for(int i = 0; i<num; i++){
		printf("%d ", vec[i]);
	}
	keep_positives();
	printf("\n");
	for(int i = 0; i<num; i++){
		printf("%d ", vec[i]);
	}
	printf("\n");
	
	
	return 0;
}
