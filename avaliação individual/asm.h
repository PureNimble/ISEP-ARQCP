typedef struct{
	char * nome;			//0-7		
	unsigned int notas;		//8-11
	short nota_final;		//12-13   sizeof(16)
	
}aluno;


short calcula_nota(unsigned int notas);
int notas(aluno *notas_alunos,int n);

void string(char *d,char *s);
