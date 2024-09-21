#include <stdio.h>
#include "copy_vec.h"

int main(){
        
        int n;
        printf("Size of the array? ");
        scanf("%i", &n);
        int vec1[n];
        int vec2[n];
        printf("\n");
        for(int i = 0; i<n; i++){
                printf("What's the integer? ");
                scanf("%i", &vec1[i]);
                }
		printf("\n");
        for(int i = 0; i<n; i++){
                printf("Value of vec2[%i], before copy: %i \n",i, vec2[i]); //As vec2 has no elements yet, there will be values ​​that we are not interested in this line
                }
        printf("\n");
        copy_vec(vec1, vec2, n);
        for(int i = 0; i<n; i++){
                printf("Value of vec2[%i], after copy: %i \n",i, vec2[i]);
                }
        return 0;
}
