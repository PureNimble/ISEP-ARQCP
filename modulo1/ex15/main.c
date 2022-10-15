#include <stdio.h>
#include <stdlib.h>
#include "populate.h"
#include "check.h"
int check ( int x, int y, int z);
int main()
{
	int num = 100;
    int arr[num];
    int limit = 20;
    int sets[num];
    int i;
    
    populate(arr,num,limit);
    
	for (i = 0; i < num; i++){
        printf("%i \n", arr[i]);
    }
    for (i=0; i < num; i++){
		sets[i] = check(arr[i],arr[i+1],arr[i+2]);   
    }
    return 0;
}
 int check ( int x, int y, int z)
 {
	int final;
	if(x < y && y < z){
            final = 1;
            }
        else{
			final = 0;
            }
    return final ;
 }
