#include <stdio.h>

void copy_vec(int *vec1, int *vec2, int n){

                for (int i = 0; i<n; i++){

                *(vec2+i) = *(vec1+i);

                }

}
