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
	
	// y -> lines
	// k -> columns
	// num -> number being searched
	y--;									// vec[0] -> posicao 1
	k--;									// vec[0] -> posicao 1
	if(*(*(m+y)+k) == num)					// check if m[y][k] == num
	{
		return 1;							// 1 if is equal
	}
	return 0;								// 0 if is different
}
