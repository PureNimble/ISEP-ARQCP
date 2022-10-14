#include <stdio.h>
int main(){
	//Declaring the variables
	int x = 5; 
	int *xPtr = &x;
	float y = *xPtr + 3;
	int vec[] = {10, 11, 12, 13};
	

	//print of the value and adresses of the variables
	    
	    printf("The value of x = %i \n",x);
	    printf("The value of y = %f \n",y);
	    printf("The adress of x = %p \n",&x);
	    printf("The adress of xPtr = %p \n",&xPtr);
	    printf("The value pointed by xPtr = %i \n",*xPtr);
	    printf("The adress of vec = %p \n",vec);
	    
	//print of the value of the variables of vec[]
	    for (int i=0;i < 4; i++)
	    {
	    	printf("The value of vec[%i] = %i \n",i,vec[i]);
	    }
	//print of the adress of the variables of vec[]
    	for (int i=0;i < 4; i++)
    	{
    		printf("The adress of vec[%i] = %p \n",i,&vec[i]);
    	}
	return 0;
	
	/* 
	a) 	The value x is 5 because it is the value that we set the variable x to. 
	 	The value of y is 8 because the pointer (*xPtr) is set to the address of x -> (5 + 3).
		The address of x comes after the address of xPtr because the smallest goes to the smallest byte
		The value by *xPtr is 5 because it points to the address of x which currently has the value of 5
		The address of vec is the address of the first element of the array and it is given by &vec[0]
	
	b) 	The address of vec is the same as the address of vec[0] as it is the initial position of the array, the next addresses of the array values
			are all followed, having a size of 4 bytes as we are working with integers.
	c)	Every time the computer starts the program, it randomly chooses registers that are free to be used. 
			So being on another computer the addresses will be different 
	*/
}
