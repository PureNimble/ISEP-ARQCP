#include <stdio.h>
#include "frequencies.h"
int main()
{
    //Declaration of the variables
		int n;
	//Print and scan of the size of the array
		printf("\nQual o número de alunos? ");
		scanf("%i", &n);
	//Declaration of the arrays
		float vec[n];
		int vecNotas[21];
    // Print and scan the elements of a array
		for(int i = 0; i<n; i++){
			do
			{
			printf("\nQual a nota do %iº aluno? ", i+1);
			scanf("%f", &vec[i]);
			}
			while(vec[i] < 0 || vec [i] > 20);
			}
	//Print the elements if the array
		for(int i = 0; i<n; i++){
			printf("\nA nota do %iº aluno é %f\n", i+1, vec[i]);
			}
    //Use of the function
		frequencies(vec, n, vecNotas);     
    //Final print
		printf("\n{");
		for(int i = 0; i<21; i++){
			printf("%i ",vecNotas[i]);
			}
		printf("}\n");
}


