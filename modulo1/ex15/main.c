#include <stdio.h>
#include <stdlib.h>
#include "populate.h"
#include "check.h"
#include "inc_nsets.h" 
int counter = 0;
int sets[100];
int main()
{
	//Declaration of the functions
		int num = 100;
		int arr[num];
		int limit = 21;
		int i;
    //Use of the function which generate random numbers
		populate(arr,num,limit);
    //Print the array
		for (i = 0; i < num; i++){
			printf("%i \n", arr[i]);
		}
	//Use of the function that satisfy the condition
		for (i=0; i < num; i++){
			sets[i] = check(arr[i],arr[i+1],arr[i+2]);   
		}
		
		printf("Array: { ");
		for (i=0; i<100; i++){
			printf("%i ", sets[i]);
			}
		printf("}\n");
	//Use of the function that count the number of sets
		inc_nsets();
    return 0;
}


