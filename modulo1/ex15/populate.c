#include <stdlib.h>
void populate( int *vec , int num,  int limit)
{
	//Create 100 elemets in a array
	for (int i=0; i<num;i++){
        *vec = rand()%limit;
        
        vec++;
    }
}
