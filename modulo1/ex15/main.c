#include <stdio.h>
#include <stdlib.h>
void populate( int *vec , int num,  int limit);
int main()
{
    int arr[num];
    int num = 100;
    int limit = 20;
    
    populate(arr,num,limit);
	for (int i = 0; i < num; i++){
        printf("%i \n", arr[i]);
    }
    return 0;
}
void populate( int *vec , int num,  int limit)
{
	for (int i=0; i<num;i++){
        *vec = rand()%limit;
        
        vec++;
    }
}
