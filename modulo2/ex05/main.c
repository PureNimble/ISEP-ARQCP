#include <stdio.h>
#include "asm.h"


int main(void)
{
	printf("Value of s:");
	scanf("%hd",&s);
	short ret = swapBytes();
	printf("Value of s in hexadecimal : 0x%hx \n",s);
	printf("Value of s after the byte swap: %hd\n",ret);
	printf("Value of s after the byte swap in hexadecimal: 0x%hx\n",ret);
	
	return 0;
}
