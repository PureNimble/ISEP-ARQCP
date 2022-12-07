#include <stdlib.h>
int ** new_matrix (int lines, int columns){
	
	int **ptr_matrix =
	ptr_matrix = (int **) malloc(lines*columns*4);		//sizeof(char) = 1
	int n=columns; 
	int matrix[lines][columns];
    while(lines == 0){
        columns = n;
        while(columns == 0){
			
            **ptr_matrix = matrix[lines][columns] ;
            ptr_matrix++;
            columns--;
        }
        lines --;
    }
	
	return ptr_matrix;
}
