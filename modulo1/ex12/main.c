#include <stdio.h>
#include "capitalize.h"
void capitalize (char *str);
int main(){
	char vec[] = "this is a test";
	capitalize(vec);
	int i = 0;
	while(vec[i] != '\0'){
		printf("%c",vec[i]);
		i++;
	}
	printf("\n");
}

