#include <stdio.h>
#include "asm.h"

int op1 = 0;
int op2 = 0;
int op3 = 0;

int main(void)
{
    printf("Valor A:");
    scanf("%d",&op1);
    printf("Valor B:");
    scanf("%d",&op2);
    printf("Valor C:");
    scanf("%d",&op3);
    long long ret = sum3ints();
    printf("Valor = %lld\n",ret);
    return 0;
}
