#include <stdio.h>
#include "upper1.h"

int main() {
    
        //Declaration of the variables
            char string[] = "This is a test";
            int arraySize = sizeof(string) / sizeof(string[0]);
        //Prints of the array
            printf("String before transformation: ");
            for (int i= 0; i< arraySize; i++) {
                printf("%c", string[i]); //prints array information
            } 
            printf("\n");
        //Use of the function upper1
            upper1(string);
        //Prints of the array
            printf("String before transformation: ");
            for (int j = 0; j < arraySize; j++) {
                printf("%c", string[j]);            //prints array information
            } 
        
        
        return 0;
}
