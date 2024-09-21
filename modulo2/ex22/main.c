#include <stdio.h>
#include "asm.h"
#include "function.h"
int j,i;
int main(void)
{	
	int assm;
	int c;
	printf("----Calculator----\n");
	
	printf("Number of i:\n");
	scanf("%d",&i);
	printf("Number of j:\n");
	scanf("%d",&j);
	
	printf("Which operation you want to do?\n");
	printf("1-f() \n");
	printf("2-f2()\n");
	printf("3-f3()\n");
	printf("4-f4()\n");
	scanf("%i",&i);
	switch(i) {
  case 1:
	assm = fa();
	c =  f();
    break;
  case 2:
	assm = f2a();
	c =  f2();
    break;
  case 3:
  	assm = f3a();
	c =  f3();
	break;
  case 4:
    assm = f4a();
	c =  f4();
    break;
  
  default:
    printf("Error!! \n");
}
	printf("Value in assembly = %d\n",assm);
	printf("Value in c = %d\n",c);
	return 0;
}
