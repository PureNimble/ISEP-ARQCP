#include <stdio.h>
#include "asm.h"

int main()
{

	int a = 2;
	int b = 10;

	int y = calculate(a,b);
	printf("(%d-%d)-(%d*%d) = %d\n",a,b,a,b,y);
	
	return 0;
}

void print_result(char op, int o1, int o2, int res) 
{ 
	printf("%d %c %d = %d\n", o1, op, o2, res); 
	
}
