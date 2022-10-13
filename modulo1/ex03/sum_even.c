#include <stdio.h>

int sum_even( int *p, int num) 
{
	int evenSum = 0;
    for(int i=0; i<num; i++)
    {
        if((*p)%2==0){
         evenSum=evenSum+(*p);
       
        }
		p++;   
    }
    return evenSum;    
}
