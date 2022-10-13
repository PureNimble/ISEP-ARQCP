void power_ref(int *x, int y){
	//Declaration of variables
		int resultado = 1;
    while (y != 0)
    {
        resultado *= *x;
        --y;
    }
    *x = resultado;
}
