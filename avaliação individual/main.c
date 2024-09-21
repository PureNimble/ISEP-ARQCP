#include <stdio.h>
#include "asm.h"
#include <stdlib.h>
int main(){

	int i;
	
	unsigned int conjunto_notas[4]={0x12443256,0x2AAAA2DC,0x3EE424CD,0x4A444444};
	char nome[4][10]={"Joel","Maria","Marco","Carla"};
	
	aluno* turma = (aluno*) malloc (4*sizeof(aluno));

	aluno a ;					// struct temporatira										
	aluno *ptr_a = &a;		// apontador da estrutura
	
	//funcao para preencher as estruturas com os dados 
	for(i=0;i<4;i++){
		
		string(ptr_a->nome,nome[i]);
		a.notas = conjunto_notas[i];
		
		turma[i]=a;
	}
		
	int	media_turma = notas(turma,4);
	
	printf("Media dos alunos: %d",media_turma);
	

	for(i=0;i<4;i++){
		printf("--------------------------------------");
		printf("Nome: %s\n", turma[i].nome);
		printf("Notas: %d\n", turma[i].notas);
		printf("Nota final: %d\n",turma[i].nota_final);
		printf("--------------------------------------");
	}
	
	printf("Media dos alunos: %d",media_turma);
	
	free(turma);
	return 0;
	

	
}
//Funcao para copiar uma string para outro address

void string(char *d,char *s){
	while(*s!=0){
		
		*d = *s;
		
		d++;
		s++;		
	}	
	*d = 0;
}

