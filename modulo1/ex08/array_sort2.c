void array_sort2(int *vec, int n) 
{

    //Put the elements in order
        int i,j,a;
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j)
            {
                if (*(vec+i) > *(vec+j)) 
                {
                    a =  *(vec+i);
                    *(vec+i) = *(vec+j);
                    *(vec+j) = a;
                }
            }
         }
}
