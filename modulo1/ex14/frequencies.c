
void frequencies(float *grades, int n, int *freq) 
{
	 int vecI[n];
	 for(int i = 0; i<n; i++){
        vecI[i] = (int)*grades;
        grades++;
        }
     int *ptr = freq;
     for(int i = 0; i<n; i++){
		 
		ptr = freq+ vecI[i] ;
        *ptr = *ptr + 1;
        ptr = freq;
        
        }
}
