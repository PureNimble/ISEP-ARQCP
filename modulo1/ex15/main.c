#include <stdio.h>
#include <stdlib.h>
#include "populate.h"
int check ( int x, int y, int z);
int main()
{
	int num = 100;
    int arr[num];
    int limit = 20;
    
    populate(arr,num,limit);
	for (int i = 0; i < num; i++){
        printf("%i \n", arr[i]);
    }
    
    check(*arr,*arr+1,*arr+2);
    return 0;
}
 int check ( int x, int y, int z)
 {
	for (int i = 0; i = 100; i++)
	{
		if ( x < y && y < z)
		{
			printf
			
		}
	}
 }
