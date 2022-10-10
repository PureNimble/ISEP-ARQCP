#include <stdio.h>
void printValue(int array[]){
	for (int i=0;i < 4; i++)
	{
		printf("The value of vec[%i] = %i \n",i,array[i]);
	}
}
void printAdress(int array[]){
	for (int i=0;i < 4; i++)
	{
		printf("The adress of vec[%i] = %p \n",i,&array[i]);
	}
}
