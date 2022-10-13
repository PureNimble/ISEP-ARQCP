#include <stdio.h>
void frequencies(float *grades, int n, int *freq) ;
int main()
{
    
    int n;
    printf("\nQual o número de alunos? ");
    scanf("%i", &n);
    float vec[n];
    int vecNotas[]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    for(int i = 0; i<n; i++){
        printf("\nQual a nota do %iº aluno? ", i+1);
        scanf("%f", &vec[i]);
        }
    for(int i = 0; i<n; i++){
        printf("\nA nota do %iº aluno é %f\n", i+1, vec[i]);
        }
    frequencies(vec, n, vecNotas);     
    
    printf("\n{");
    for(int i = 0; i<21; i++){
        printf("%i ",vecNotas[i]);
        }
    printf("}");
}

void frequencies(float *grades, int n, int *freq) 
{
		int vecI[n];
	 for(int i = 0; i<n; i++){
        vecI[i] = (int)*grades;
        grades++;
        }
     int *ptr = freq;
     for(int i = 0; i<n; i++){
		 
		printf("%p \n",freq);
		ptr = freq+ vecI[i] ;
        printf("%p\n",ptr);
        *ptr++;
        ptr = freq;
        }
}
