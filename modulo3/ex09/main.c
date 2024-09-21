#include <stdio.h>
#include "asm.h"

short x = 3;
short vec[] = {1,2,3,4,5,6};
short *ptrvec = vec;
int num = 6;
int main()
{	
	short *xptr = vec_search();
	printf("Start of vec = %p \n",ptrvec);
	printf("Adress of x = %p \n",xptr);
	
	return 0;
}
