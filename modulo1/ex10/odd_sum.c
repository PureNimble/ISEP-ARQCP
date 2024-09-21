
int odd_sum(int *p){
	//Declaration of the variables
	int n = *p;
	int soma = 0;
	p++;
	//Seeing if the element is odd, skipping the first one
	for(int i = 1; i < n; i++){
		if(*p % 2 != 0){
			soma += *p;
		}
		p++;
	}
	return soma;
}
