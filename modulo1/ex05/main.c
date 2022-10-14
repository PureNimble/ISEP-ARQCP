#include <stdio.h>
#include "upper2.h"

int main() {
    
        //Declaration of the variables
			char string[30]; 
        //Prints and scan of the string
			printf("Write a phrase: ");
			scanf("%s",string);
			printf("\n");
		//Use of the function upper1
			upper2(string);
        //Prints of the array
			printf("String after transformation: %s \n",string);
		
        
        return 0;
}
