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
}
