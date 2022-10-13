void power_ref(int *x, int y){
	//Declaration of variables
		int resultado = 1;
	//Calculation
		while (y != 0)		// Number of times the number is multiplied
		{
			resultado *= *x; 	// Multipling the number and storing at -> 'resultado'
			--y;				// Decreasing the counter	
		}
		*x = resultado;   //final value goes to the pointer
}
