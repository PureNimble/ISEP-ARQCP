#include <stdlib.h>
int ** new_matrix (int lines, int columns){
	int **a;									// declaration of the matrix pointer
	a = (int**) calloc(lines,8);				// create the matrix -> vec with the address
	
	for(int i=0; i< lines; i++){				// cycle for all lines
		
		*(a+i) = (int *) calloc(columns,4);		// create the elements of each line
		
	}
	return a;									// return the address of the matrix
}
int find_matrix(int **m, int y, int k, int num){
	
	int i,j;
	// y -> lines
	// k -> columns
	// num -> number being searched



    int * ptrColumn = *m;				// save the address of  the first column

	//lines cycle
	for(i= 0; i<y; i++){
		// columns cycle
		for(j= 0; j<k; j++){
			
			if((*ptrColumn) == num)					// if num is equal return 1
			{
				return 1;				
			}
			ptrColumn++;							// move to the next column of the same line
		}
		m++;										// move to the next line
		
		ptrColumn = *m;								// reset ptrColumn to the first element of the line
	}
	
	return 0;									// if num not found return 0
}
