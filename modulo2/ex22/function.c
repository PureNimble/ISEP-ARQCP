extern int i,j;

int f(){
	int h;
	if( i==j){
		h = i - j + 1;
	}
	else{
		h = i + j - 1;
	}
	return h;
}
int f2(){
	int h;
	if (i > j){
		i = i - 1;
	}
	else{
		j = j + 1;
	}
	h = j * i;
	return h; 
}
int f3(){
	int h,g,r;
	if (i >= j) {
		h = i * j;
		g = i + 1;
	}
	else{
		h = i + j; 
		g = i + j + 2;
	}
	r = g / h;
	return r;
}
int f4(){
	int h;
	if (i+j < 10){
		h = 4 * i * i;
	}
	else{
		h = j * j / 3;
	}
	return h;
}
		
	
