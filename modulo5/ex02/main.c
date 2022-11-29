#include <stdio.h>
#include <string.h>

int main(){

	union union_u1{				//size of union_u1 = 32
		char vec[32];
		float a;
		int b;
	}u;

	union union_u1 *ptr = &u;	// ptr



	strcpy(ptr ->vec, "arquitectura de computadores");
	printf("[1]=%s\n", ptr -> vec);			// uses 28 bytes of union
	ptr -> a = 123.5;						// writes in the string space the float
	printf("[2]=%f\n", ptr -> a);			// uses 4 bytes
	ptr -> b = 3;							// writes in the float space the int
	printf("[3]=%d\n", ptr -> b);			// uses 4 bytes
	
	printf("[1]=%s\n", ptr -> vec);			// reads the last value (b) as a string
	printf("[2]=%f\n", ptr -> a);			// reads (b) as a float 
	printf("[3]=%d\n", ptr -> b);			// reads (b)
	return 0;
}
