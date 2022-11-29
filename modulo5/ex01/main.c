#include <stdio.h>


struct struct_s1{
	char vec[32];
	float a;
	int b;
}s;
 
union union_u1{
	char vec[32];
	float a;
	int b;
}u;

int main(){
	
	printf("Size of struct_s1: %ld\n", sizeof(struct struct_s1)); // size of struct = the sum of the sizes of the variables (or more) =  1 * 32 + 4 + 4 = 40  (4 is a multiple of 32)
	
	printf("Size of union_u1: %ld \n", sizeof(union union_u1));  // size of union = the size of the bigest variable in the onion, in this case -> char vec[32] = 32 bytes

	
	return 0;
}
