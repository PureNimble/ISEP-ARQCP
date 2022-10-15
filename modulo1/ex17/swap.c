#include <stdio.h>
//funcao swap
void swap(int* vec1, int* vec2, int size)
{
	//Declaration of the variables 
	int t = 0;
	//Swapping the elements
    for (int i=0;i<size;i++) {
        t=*(vec2+i);
        *(vec2+i)=*(vec1+i);
        *(vec1+i)=t;
    }
}
