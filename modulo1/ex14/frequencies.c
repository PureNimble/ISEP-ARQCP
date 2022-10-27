
void frequencies(float *grades, int n, int *freq) 
{
	//Declaration of a array
		int vecI[n];
	//Converte floats into ints and puting the elements in a array
		for(int i = 0; i<n; i++){
			vecI[i] = (int)*grades;
			grades++;
			}
	//Declaration of a pointer
		int *ptr = freq;
	//Puting the values of vecI[] in the adress of freq
		for(int i = 0; i<n; i++){
			 
			ptr = freq+ vecI[i];
			*ptr = *ptr + 1;
			ptr = freq;
			
			}
}
