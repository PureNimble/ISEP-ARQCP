#include <stdio.h>
#include "vec_sum.h"
#include "vec_avg.h"
short num = 3;
long vec[3] = {1,2,3};
long *ptrvec = vec;
int main()
{
	long sum = vec_sum();
	long average = vec_avg();
	printf("sum=%ld\n",sum);
	printf("average=%ld\n",average);
	return 0;
}
