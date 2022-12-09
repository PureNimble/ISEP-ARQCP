#include <stdio.h>
#include <string.h>

int main(){

	union union_u1{				//size of union_u1 = 32
		char vec[32];
		float a;
		int b;
	}u;

	union union_u1 *ptr_u = &u;	// ptr

	struct struct_s1{				//size of struct_s1 = 40
		char vec[32];
		float a;
		int b;
	}s;

	struct struct_s1 *ptr_s = &s;	// ptr
	printf("Union\n");
	strcpy(ptr_u->vec, "arquitectura de computadores");
	printf("[1]=%s\n", ptr_u -> vec);		// uses 32 bytes of union
	ptr_u -> a = 123.5;						// writes in the string space the float
	printf("[2]=%f\n", ptr_u -> a);			// uses 4 bytes
	ptr_u -> b = 3;							// writes in the float space the int
	printf("[3]=%d\n", ptr_u -> b);			// uses 4 bytes
	
	printf("[1]=%s\n", ptr_u -> vec);		// reads the last value (b) as a string
	printf("[2]=%f\n", ptr_u -> a);			// reads (b) as a float 
	printf("[3]=%d\n", ptr_u -> b);			// reads (b)
	
	printf("Struct\n");
	strcpy(ptr_s->vec, "arquitectura de computadores");
	printf("[1]=%s\n", ptr_s -> vec);		// uses 32 bytes of struct_s1
	ptr_s -> a = 123.5;						// uses the next 4 bytes
	printf("[2]=%f\n", ptr_s -> a);			
	ptr_s -> b = 3;							// uses the next 4 bytes
	printf("[3]=%d\n", ptr_s -> b);
	
	printf("[1]=%s\n", ptr_s -> vec);		// print the same thing
	printf("[2]=%f\n", ptr_s -> a);			// print the same thing
	printf("[3]=%d\n", ptr_s -> b);			// print the same thing
	return 0;

    /**Alíena a: O programa imprime primeiro "arquitetura de computadores", em segundo 123.5, terceiro 2 e 
     * depois nas 3 seguintes impressões o valor 2 (que foi a última atribuição) em formato string, float e 
     * finalmente em inteiro. Como se trata de um número inteiro, então nas impressões de string e float o resultado
     * será o inteiro 2 em float(0.000000) e em string. Isto deve-se ao facto de numa union apenas podemos utilizar 
     * um campo de cada vez. Esta union tem um tamanho de 32 bits (todas as variáveis têm este tamanho) e esta memória
     * é partilhada por todos os elementos. Quando atribuimos 2 ao campo b, interfere com todos os campos, sendo este
     * o único valor guardado.
    **/

   /**Alínea b: Depois de ter declarado uma estrutura, o progama imprimiu sempre "arquitetura de computadores" com o campo 
    * vec (char[]), imprimiu sempre 123.5 com o campo a (float) e imprimiu sempre 2 com o campo b (inteiro). A diferença
    * para a alínea anterior deve-se ao facto de que as estruturas não partilham a memória como as union. A estrutura 
    * definida tem 40 bytes. Assim, todos os campos têm o seu valor definido e não é subscrito pela atribuição dos outros
    * campos, como acontece nas union.
    **/
}
