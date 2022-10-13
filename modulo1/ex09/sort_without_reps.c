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
        *(dest+i) = *(src+i);
    }
    //Remove the repeated numbers
    for(i=0;i<n;i++){
        for(j = i+1; j < n; j++){
            if((int)*(dest+i) == (int)*(dest+j)){
				counter--;
                for(k = j; k <n; k++){
                    *(dest+k) = *((dest+k)+1);
                }
                j--;
                n--;
            }
        }
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
