#include <stdio.h>
#include "asm.h"

int op1=0, op2=0;
extern long op3, op4;
int main(void)
{
	int res;
	printf("Valor op1:");
	scanf("%d",&op1);
	printf("Valor op2:");
	scanf("%d",&op2);
	res = sum_v3();
	printf ("op3 %lu \n",op3);
	printf ("op4 %ld \n",op4);
	printf("sum = %d:0x%x\n",res,res);
	return 0;
}
