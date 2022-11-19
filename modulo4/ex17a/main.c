#include <stdio.h>
#include "c.h"
 
int main(void){
	unsigned int date1 = 10;
	unsigned int date2 = 10;
	
	int y = greater_date(date1,date2);
	
	printf("Greater:%d\n", y);
	
	return 0;
}
