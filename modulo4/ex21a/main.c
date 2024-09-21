#include <stdio.h>
#include "c.h"
 
int main(void){
	char b[]="abc";
	char a[]="abc";

	int x = sum_multiples_x(&a,&b);
	
	printf("Return:\n",x);
	
	return 0;
}
