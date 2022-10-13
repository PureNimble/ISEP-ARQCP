//function
int sort_without_reps(int *src, int n, int *dest) 
{
	//Declaration of the variables
		int i;
		int j;
		int k;
		int a;
		int counter =  n;
	//Pass the elements of src to dest
    for(i=0;i<n;i++){
        *dest = *src;
        src++;
        dest++;
    }
    //Remove the repeated numbers
    for(i=0;i<n;i++){
        for(j = 1; j < n; j++){
            if(*dest == *dest){
				counter--;
                for(k = j; k <n; k++){
					
                    *dest = (int)dest++;
                    
                  dest++
                }
                j--;
                n--;
            }
            dest++;
        }
        dest++;
    }
    //Put the elements in order
    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j)
        {
            if (*(dest+i) > *(dest+j)) 
            {
                a =  *(dest+i);
                *(dest+i) = *(dest+j);
                *(dest+j) = a;
            }
        }
     }
     
     return counter;
}
