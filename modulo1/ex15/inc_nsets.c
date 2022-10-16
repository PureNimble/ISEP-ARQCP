#include <stdio.h>
extern int counter;
extern int sets[]; 
void inc_nsets()
{
	//Count the number of sets
	for (int i=0;i<100;i++){
			if (sets[i]==1){
				counter++;
				}
		}
	printf("\nO número de sets é igual a %i \n", counter);
	
}
