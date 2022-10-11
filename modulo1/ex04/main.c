#include <stdio.h>
#include "upper1.h"

int main() {
    
        char string[] = "ThisIsATest";
        int arraySize = sizeof(string) / sizeof(string[0]);
        printf("String before transformation: ");
        int i;
        for (i= 0; i< arraySize; i++) {
            printf("%c", string[i]); //prints array information
        } 
        printf("\n");
        
        char *str = string; //pointer that points to the array
        
        upper1(str);
        
        printf("String before transformation: ");
       
		for (int j = 0; j < arraySize; j++) {
			printf("%c", string[j]);			//prints array information
		} 
        
        
        return 0;
}
