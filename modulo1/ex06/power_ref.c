void power_ref(int *x, int y){
	int resultado = 1;
    while (y != 0)
    {
        resultado *= *x;
        --y;
    }
    *x = resultado;
}
