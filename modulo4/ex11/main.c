#include <stdio.h>
#include "asm.h"

int main()
{

	int a = 1;
	int b = 1;
	int c = 1;
	int d = 1;


	int y = call_proc(a,b,c,d);
	printf("Return:%d\n",y);
	
	return 0;
}
