#include <stdio.h>
#include "asm.h"

int main()
{

	short w = 2;


	int y = call_incr(w);
	printf("Return:%d\n",y);
	
	return 0;
}
