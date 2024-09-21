
int sum_even( int *p, int num) 
{
	//Declaration of a variable
		int evenSum = 0;
	//Function that given a element of the array, divide the number by 2 to identify if the number is even
		for(int i=0; i<num; i++)
		{
			if((*p)%2==0){
			 evenSum += *p;
		   
			}
			p++;   
		}
    return evenSum;    
}
