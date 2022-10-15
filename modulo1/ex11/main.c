#include <stdio.h>
#include "palindrome.h"

int main(){
	//Declaration of the array
	char vec2[] = "A man a plan a canal Panama";
	//Use of the function
	int check2 = palindrome(vec2);
	//Final print
	printf(":%d \n",check2);

}
