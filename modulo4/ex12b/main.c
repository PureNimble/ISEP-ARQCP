#include <stdio.h>
#include "asm.h"
 
int main(void){
	
	int x = 46;
	int resultado;
	
	resultado = count_bits_one(x);
	
	printf("Number of 0 bits: %d\n", resultado);
	
	return 0;
}
