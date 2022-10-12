#include <stdio.h>

int sum_even( int *p, int num) 
{
	int evenSum =0;
    for(int i=0; i<num; i++)
    {
        if(p[i]%2==0){
         evenSum=evenSum+p[i];
        }
    }
    printf("\nThe sum of even numbers are: %i",evenSum);
    printf("\nThe address of the array is: %p", p);
    
    return 0;
    
}
