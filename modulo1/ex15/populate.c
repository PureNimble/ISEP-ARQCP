#include <stdlib.h>
void populate( int *vec , int num,  int limit)
{
	for (int i=0; i<num;i++){
        *vec = rand()%limit;
        
        vec++;
    }
}
