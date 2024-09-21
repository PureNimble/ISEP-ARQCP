#include <stdlib.h>
char *  new_str(char *p1){
	
	char *ptr_char = NULL;				// create a pointer
	ptr_char = (char *) malloc(80);		//sizeof(char) = 1
	char *x = ptr_char;					// create a variable to work in the memory
	
	char counter = 0;					// Declare the counter
	while (*p1 != 0){					//check for the end of the string
		*x = *p1;						// move the char to the memory
		x++;							// move to the next potition
		p1++;							// move to the next char
		counter++;						// increase the counter
	}
	ptr_char = (char *) realloc(ptr_char,counter+1);		// relocate the memory with the size (counter) + 1 for the end of vec
	return ptr_char;
}
