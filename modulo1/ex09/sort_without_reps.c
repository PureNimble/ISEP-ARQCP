
int sort_without_reps(int *src, int n, int *dest) 
{	

	//Declaration of the variables
	int i, j, k, a;
	int contador = 0;
	//Pass the elements of src to dest
		int *p =dest;
		for(i=0;i<n;i++){
			*p = *src;
			p++;
			src++;
			
		}
    //Remove the repeated numbers
    int *x = dest;
		for(i=0;i<n;i++){
			for(j = i+1; j < n; j++){
				if(*(x+i) == *(x+j)){
					for(k = j; k <n; k++){
						*(x+k) = *(x+(k+1));
						contador = n - 1;
					}
					j--;
					n--;
				}
			}
		}
    //Put the elements in order
    int *r= dest;
		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j)
			{
				if (*(r+i) > *(r+j)) 
				{
					a =  *(r+i);
					*(r+i) = *(r+j);
					*(r+j) = a;
				}
			}
		 }
		 return contador;
}
