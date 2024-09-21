#include <stdlib.h>
int ** new_matrix (int lines, int columns){
	int **a;									// declaration of the matrix pointer
	a = (int**) calloc(lines,8);				// create the matrix -> vec with the address
	
	for(int i=0; i< lines; i++){				// cycle for all lines
		
		*(a+i) = (int *) calloc(columns,4);		// create the elements of each line
		
	}
	return a;									// return the address of the matrix
}
int ** add_matrixes(int **a , int **b , int y , int k){
	
	/**
	 * y -> size of lines
	 * k -> size of columns
	 */
	
	int lines,columns;
	int *column_a = *a;							// get the column A pointer
	int *column_b = *b;							// get the column B pointer
	
	int **finalMatrix=new_matrix(y,k);			// create the dynamic matrix	
	int **Return = finalMatrix;					// save the matrix address
	
	int *finalColumn = *finalMatrix;			// get the column pointer
	
	for (lines=0; lines < y; lines++){					// lines cycle
		for(columns =0; columns < k; columns++){		// columns cycle
				
			 *finalColumn = *column_a + *column_b;		// get the sum of **a and **b on the final matrix
			
			// next column of the line
			column_a++;
			column_b++;
			finalColumn++;
		}
		// next line of the matrix
		a++;
		b++;
		finalMatrix++;
		// get the pointer of the line 
		column_a = *a;
		column_b = *b;
		finalColumn = *finalMatrix;
	}
	return Return;
}
