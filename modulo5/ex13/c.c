#include <stdlib.h>
#include "asm.h"
int ** new_matrix (int lines, int columns){
	int **a;									// declaration of the matrix pointer
	a = (int**) calloc(lines,8);				// create the matrix -> vec with the address
	
	for(int i=0; i< lines; i++){				// cycle for all lines
		
		*(a+i) = (int *) calloc(columns,4);		// create the elements of each line
		
	}
	return a;									// return the address of the matrix
}
