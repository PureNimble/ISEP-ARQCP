#include <stdio.h>
#include "swap.h"
int main()
{
	//Declaration of the variable
		int size;
    //Print and scan the size of the array
		printf("Enter the size of the array: ");
		scanf("%d",&size);
    //Declaration of the second array with the size given
		int arr[size];
	//Print and scan of entering the elements of the array 1
		for(int i=0; i<size; i++){
			printf("Enter the 1º Array elements: ");
				scanf("%d",&arr[i]);
		}
	//Declaration of the second array with the same size
		int ary[size];
    
     ;
    //Print and scan of entering the elements of the array 2
		for(int i=0; i<size; i++){
			printf("Enter the 2º Array elements: ");
				scanf("%d",&ary[i]);
		}
    //Use of the function swap
		swap(arr,ary,size);
    //Print the arrays after the swap
		for (int i=0;i<size;i++) {
			printf("Valor do 1º array: %i \n", arr[i]);
		 }
		 for (int i=0;i<size;i++) {
			printf("Valor do 2º array: %i \n", ary[i]);
		 }
		 
    return 0;
}

