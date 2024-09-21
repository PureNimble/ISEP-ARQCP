
void copy_vec(int *vec1, int *vec2, int n)
{	
	//Copying the elements of vec1 to vec2 
	for (int i = 0; i<n; i++){
			
		*vec2 = *vec1;
		
		vec1++;
		vec2++;

	}

}
