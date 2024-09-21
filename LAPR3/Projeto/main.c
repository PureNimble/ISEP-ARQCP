// Library -> standard library
#include <stdio.h>
// Library -> more portable code -> set of typedefs
#include <stdint.h>
// header files
#include "info.h"
#include "sensores.h"
// Library -> delay the program
#include <unistd.h>
// Library -> String copy
#include <string.h>
// Library -> malloc
#include <stdlib.h>
// Library -> trunc a number (remover a parte decimal de um numero)
#include <math.h>
int main()
{
	unsigned short numeroSensores[N_TIPOS_SENSORES];												  // array que armazena o número de sensores para cada tipo
	unsigned long frequenciasSensores[N_TIPOS_SENSORES];											  // ver a frequência de todos os tipos
	unsigned short max_min_limite[6][2] = {{0, 60}, {0, 359}, {0, 38}, {0, 180}, {0, 100}, {0, 100}}; // maximo e minimo dos sensores

	/*************************************************************************
	 *Função: dev_random  					        					     *
	 *************************************************************************
	 * -> Gera uma seed aleatória para simular os números "aleatórios"   	 *
	 *************************************************************************/
	dev_random();	

	/*************************************************************************
	 *Função: printSensorsType   										     *
	 *************************************************************************
	 * -> print  dos ID de todos os tipos de sensores 	       				 *
	 *************************************************************************/
	printSensorsTypes();						

	/******************************************************************************
	 *Função: scanSensorsAndFrequencys  										  *
	 ******************************************************************************
	 * -> scan de o numero e frequencia para cada tipo de sensor 			      *
	 * @param numeroSensores = array com o numero de sensores par cada tipo		  *
	 * @param frequenciasSensores = array com a frequencia de cada tipo de sensor *
	 * @param max_min_limite =	array com o valor maximo e minimo para cada tipo  *
	 * @return totalDeSensores = número total de sensores                         *
	 ******************************************************************************/
	unsigned short totalDeSensores = scanSensorsAndFrequencys(numeroSensores, frequenciasSensores, max_min_limite);

	// Criação da array dinamica de sensores
	Sensor *ptrSensores = (Sensor *)malloc(totalDeSensores * sizeof(Sensor));
	if (ptrSensores == NULL)
	{
		printf("Erro ao criar a array dinâmico de estruturas\n");
		exit(0);
	}
	/******************************************************************************
	 *Função: createSensores  										              *
	 ******************************************************************************
	 * -> Criação de todos os sensores com os dados fornecidos                    *	
	 * @param ptrSensores = array dinamica de sensores          				  *
	 * @param numeroSensores = array com o numero de sensores par cada tipo		  *
	 * @param frequenciasSensores = array com a frequencia de cada tipo de sensor *
	 * @param max_min_limite =	array com o valor maximo e minimo para cada tipo  *
	 * @param totalDeSensores = número total de sensores                          *
	 ******************************************************************************/
	createSensors(ptrSensores, numeroSensores, frequenciasSensores, max_min_limite, totalDeSensores);

	/******************************************************************************
	 *Função: createFirstValue 										              *
	 ******************************************************************************
	 * -> Gerar os primeiros valores em todos os sensores                         *
	 * @param ptrSensores = array dinamica de sensores          				  *
	 * @param totalDeSensores = número total de sensores   		                  *
	 ******************************************************************************/
	createFirstValue(ptrSensores, totalDeSensores);

	/**************************************************************************************************************************************
	 *Função: daySimulation 										                                                                      *
	 **************************************************************************************************************************************
	 * -> Simulação de um dia, execução de todos os sensores com as frequências descritas                                                 *
	 * @param ptrSensores = array dinamica de sensores          				                                                          *
	 * @param totalDeSensores = número total de sensores   																				  *	
	 * @param numeroSensores = número de sensores de cada tipo                                                                            *
	 * @return pointer da array de estruturas, que pode ter sido modificado                                                               *
	 **************************************************************************************************************************************/
	ptrSensores = daySimulation(ptrSensores, totalDeSensores, numeroSensores);

	/*******************************************************************************************************
	 *Função: printAllSensors 										                                       *
	 *******************************************************************************************************
	 * -> Escreve todos elementos criados em cada estrutura de sensores (no terminal e num ficheiro csv)   *
	 * @param ptrSensores = array dinamica de sensores          				                           * 		                                           
	 *******************************************************************************************************/
	printAllSensors(ptrSensores);


	/*************************************************************************
	 *Função: printSensorsType   										     *
	 *************************************************************************
	 * -> print  dos ID de todos os tipos de sensores 	       				 *
	 *************************************************************************/
	printSensorsTypes();

	/**********************************************************************************************************
	 *Função: status										                                                  *
	 **********************************************************************************************************
	 * -> Calcula o valor máximo, valor minimo  e a média de cada estrutura  (no terminal e num ficheiro csv) *
	 * @param ptrSensores = array dinamica de sensores          				                              *                                       
	 **********************************************************************************************************/
	status(ptrSensores);
	
	/****************************************************************************************
	 *Função: freeAll									                                    *
	 ****************************************************************************************
	 * -> Liberta toda a memória dinamica usada                                             *
	 * @param ptrSensores = array dinamica de sensores          				            *                            
	 ****************************************************************************************/
	freeAll(ptrSensores);

	return 0;
}

unsigned short scanSensorsAndFrequencys(unsigned short numeroSensores[N_TIPOS_SENSORES], unsigned long frequenciasSensores[N_TIPOS_SENSORES], unsigned short max_min_limite[N_TIPOS_SENSORES][2])
{
    unsigned short totalDeSensores = 0;
	for (int i = 0; i < N_TIPOS_SENSORES; i++)
	{
		do
		{
			printf("Número de sensores id %d: ", i + 1); // perguntar o número de sensores do tipo i
			scanf("%hd", &numeroSensores[i]);

		} while (numeroSensores < 0); // verificar se o sensor é valido

		printf("\n");
		if (numeroSensores[i] != 0) // verficar se existe sensores do tipo i
		{
			do
			{
			printf("Frequências dos sensores do tipo id %d (em segundos): ", i + 1); // perguntar a frequencia do sensor i
			scanf("%ld", &frequenciasSensores[i]);
			printf("\n");
			} while (frequenciasSensores[i] <= 0 || (frequenciasSensores[i] % 2) != 0); // verificar se o valor é valido
		}
		totalDeSensores += numeroSensores[i]; // armazenar o total de todos os sensores
	}
	return totalDeSensores; // return total de sensores
}
void createSensors(Sensor *ptr, unsigned short numeroSensores[N_TIPOS_SENSORES], unsigned long frequenciasSensores[N_TIPOS_SENSORES], unsigned short max_min_limite[N_TIPOS_SENSORES][2], unsigned short totalDeSensores)
{
	int j,i;
	Sensor s; // Estrutura temporária
	for (i = 0; i < N_TIPOS_SENSORES; i++)			// loop para todos os tipos de sensores
	{
		for (j = 0; j < numeroSensores[i]; j++)		// loop para todos os sensores do tipo [i]
		{
			s.id = j + 1;																				  // id de todos os sensores
			s.counter = 0;																				  // contador do ultimo valor da array
			s.errors = 0;																				  // contador de erros dados
			s.sensor_type = i + 1;																		  // id do tipo de sensores
			s.frequency = frequenciasSensores[i];														  // frequencia dos sensores
			s.readings_size = trunc(DIA / frequenciasSensores[i]);											  // tamanho da array de leitura
			unsigned long *ptrValores = (unsigned long *)malloc(s.readings_size * sizeof(unsigned long)); // Criação da array de leitura
			if (ptrValores == NULL)
			{
			printf("Erro ao criar a array dinâmico de leitura[%d]\n", j+1);
			exit(0);
			}
			s.readings = ptrValores;																	  // Colocar a array na estrutura
			s.min_limit = max_min_limite[i][0];															  // Valor Máximo
			s.max_limit = max_min_limite[i][1];															  // Valor Mínimo
			s.totalSensors = totalDeSensores;															  // número total de sensores			  
			// mover a estrutura para a array de estruturas
			*ptr = s; // Colocar a Estrutura temporária na array de estruturas
			ptr++;
		}
	}
}
void createFirstValue(Sensor *ptrSensores, unsigned short totalDeSensores)
{
	int i;
	unsigned long lastTemp = 0;	  // Variavel para saber a posição em ptrSensores de estruturas do tipo lastTemp
	unsigned long lastPluvio = 0; // Variavel para saber a posição em ptrSensores de estruturas do tipo lastPluvio
	for (i = 0; i < totalDeSensores; i++)
	{
		if (ptrSensores[i].sensor_type == 1) // estruturas do tipo 1
		{
			ptrSensores[i].readings[ptrSensores[i].counter] = (unsigned long)pcg32_random_r() % 40;
			ptrSensores[i].counter++;
		}
		if (ptrSensores[i].sensor_type == 2) //  estruturas do tipo 2
		{
			ptrSensores[i].readings[ptrSensores[i].counter] = (unsigned long)pcg32_random_r() % 359;
			ptrSensores[i].counter++;
		}
		if (ptrSensores[i].sensor_type == 3) // estruturas do tipo 3
		{
			lastTemp = (unsigned long)pcg32_random_r() % 30;
			ptrSensores[i].readings[ptrSensores[i].counter] = lastTemp;
			ptrSensores[i].counter++;
		}
		if (ptrSensores[i].sensor_type == 4) // estruturas do tipo 4
		{
			lastPluvio = (unsigned long)pcg32_random_r() % 60;
			ptrSensores[i].readings[ptrSensores[i].counter] = lastPluvio;
			if (lastTemp <= 15) // aumentar o valor de pluviosidade se a temperatura for menor ou igual a 15
			{
			ptrSensores[i].readings[ptrSensores[i].counter] += (unsigned long)pcg32_random_r() % 60;
			}
			ptrSensores[i].counter++;
		}
		if (ptrSensores[i].sensor_type == 5) // estruturas do tipo 5
		{
			ptrSensores[i].readings[ptrSensores[i].counter] = (unsigned long)pcg32_random_r() % 40;
			if (lastPluvio > 60)
			{
			ptrSensores[i].readings[ptrSensores[i].counter] += 30;
			}
			ptrSensores[i].counter++;
		}
		if (ptrSensores[i].sensor_type == 6) // estruturas do tipo 6
		{
			ptrSensores[i].readings[ptrSensores[i].counter] = (unsigned long)pcg32_random_r() % 40;
			if (lastPluvio > 60)
			{
			ptrSensores[i].readings[ptrSensores[i].counter] += 30;
			}
			ptrSensores[i].counter++;
		}
	}
}
Sensor * daySimulation(Sensor *ptrSensores, unsigned short totalDeSensores, unsigned short *numeroSensores)
{
	int i,j;
	int structTemp = 0; // Variavel para saber a posição em ptrSensores de estruturas do tipo lastTemp
	int structPluvio = 0;
	
	for (i = 0; i < DIA ; i++)
	{ // Simulation of a day (in  seconds cycles)
		for (j = 0; j < totalDeSensores; j++)
		{
			if (ptrSensores[j].sensor_type == 1 || ptrSensores[j].sensor_type == 2) // sensor_type == 1 or 2
			{
				if (i % ptrSensores[j].frequency == 0)
				{
					execute_sensor(&ptrSensores[j]);
				
				}
			}
			else if (ptrSensores[j].sensor_type == 3)
			{
				structTemp = j;
				if (i % ptrSensores[j].frequency == 0)
				{
					execute_sensor(&ptrSensores[j]);
					
				}
			}
			else if (ptrSensores[j].sensor_type == 4)
			{
				structPluvio = j;
				if (i % ptrSensores[j].frequency == 0)
				{
					execute_sensor_4(&ptrSensores[j], &ptrSensores[structTemp]);
					
				}
			}
			else if (ptrSensores[j].sensor_type == 5)
			{
				if (i % ptrSensores[j].frequency == 0)
				{
					execute_sensor_5(&ptrSensores[j], &ptrSensores[structPluvio]);
					
				}
			}
			else if (ptrSensores[j].sensor_type == 6)
			{
				if (i % ptrSensores[j].frequency == 0)
				{
					execute_sensor_6(&ptrSensores[j], &ptrSensores[structPluvio]);
					
				}
			}
			checkError(&ptrSensores[j]);
		}
		// Perguntar se o utilizador quer fazer alterações ao meio-dia
		if (i == MEIO_DIA)
		{
			ptrSensores = changeSensors(ptrSensores, totalDeSensores, numeroSensores);
			totalDeSensores = ptrSensores[0].totalSensors;
		}
	}
	return ptrSensores;
}
void execute_sensor(Sensor *ptr)
{
	if(ptr->sensor_type == 1){
		execute_sensor_1(ptr);
	}
	else if(ptr->sensor_type == 2){
		execute_sensor_2(ptr);
	}
	else{
		execute_sensor_3(ptr);
	}
}
void execute_sensor_1(Sensor *ptr)
{
	int i = (ptr->counter);
	int isub = i - 1;
	ptr->readings[i] = (unsigned long)sens_velc_vento(ptr->readings[isub], (unsigned long)pcg32_random_r() % 20);
	ptr->counter++;
}
void execute_sensor_2(Sensor *ptr)
{
	int i = (ptr->counter);
	int isub = i - 1;
	ptr->readings[i] = (unsigned long)sens_dir_vento(ptr->readings[isub], (unsigned long)pcg32_random_r() % 360);
	ptr->counter++;
}
void execute_sensor_3(Sensor *ptr)
{
	int i = (ptr->counter);
	int isub = i - 1;
	ptr->readings[i] = (unsigned long)sens_temp(ptr->readings[isub], (unsigned long)pcg32_random_r() % 10);
	ptr->counter++;
}
void execute_sensor_4(Sensor *ptr, Sensor *ptrTemp)
{
	int i = (ptr->counter);
	int isub = i - 1;
	ptr->readings[i] = (unsigned long)sens_pluvio(ptr->readings[isub], ptrTemp->readings[ptrTemp->counter], (unsigned long)pcg32_random_r() % 10);
	ptr->counter++;
}
void execute_sensor_5(Sensor *ptr, Sensor *ptrPluvio)
{
	int i = (ptr->counter);
	int isub = i - 1;
	ptr->readings[i] = (unsigned long)sens_humd_atm(ptr->readings[isub], ptrPluvio->readings[ptrPluvio->counter], (unsigned long)pcg32_random_r() % 10);
	ptr->counter++;
}
void execute_sensor_6(Sensor *ptr, Sensor *ptrPluvio)
{
	int i = (ptr->counter);
	int isub = i - 1;
	ptr->readings[i] = (unsigned long)sens_humd_solo(ptr->readings[isub], ptrPluvio->readings[ptrPluvio->counter], (unsigned long)pcg32_random_r() % 10);
	ptr->counter++;
}
void printAllSensors(Sensor *ptrSensores)
{
	//Se existir um ficheiro igual, será removido
	unsigned short totalDeSensores = ptrSensores[0].totalSensors;
	FILE *file = fopen(DATA_PATH, "r");
	if (file)
	{
			remove(DATA_PATH);
			fclose(file);
	}

	FILE *matrixData = fopen(DATA_PATH, "w+"); // cria o ficheiro só para escrever

	int i;
	for (i = 0; i < totalDeSensores; i++)
	{
		// escrever no ficheiro .csv
		fprintf(matrixData, "\n");
		fprintf(matrixData, "Tipo de Sensor = %d ; Sensor ID = %d\n", ptrSensores[i].sensor_type, ptrSensores[i].id);
		fprintf(matrixData, "\n"); 
		// escrever no terminal
		printf("Tipo de Sensor = %d\n", ptrSensores[i].sensor_type);
		printf("Sensor ID = %d\n", ptrSensores[i].id);
		// chamar função para dar print dos elementos da array
		printArray(&ptrSensores[i], matrixData);

		printf("\n");
	}
	printf("\n");
	fclose(matrixData);
}
void printArray(Sensor *ptrSensores, FILE *matrixData)
{
	int counter = 1;
	for (int j = 0; j < ptrSensores->readings_size; j++)
	{
		// Escrever os elementos no ficheiro CSV
		fprintf(matrixData, "%lu;", ptrSensores->readings[j]);
		// Escrever 10 valores por linha
		if(counter == 20)
		{
			fprintf(matrixData,"\n");
			counter = 0;
		}
		// Escrever os elementos no terminal
		printf("[%lu]", ptrSensores->readings[j]);
		// Aumentar o counter
		counter++;
	}
	fprintf(matrixData, "\n");
	printf("\nNúmero de elementos: %lu \n",ptrSensores->readings_size);
}
void checkError(Sensor *ptrSensores)
{
	int counter = ptrSensores->counter;
	counter--;
	if ((ptrSensores->readings[counter]) > ptrSensores->max_limit || (ptrSensores->readings[counter]) < ptrSensores->min_limit)
	{ // se o valor for maior que o max e menor que o min, aumenta o counter de erros

		ptrSensores->errors += 1;
		if ((ptrSensores->errors) == N)
		{ // quando chegar ao limite de erros da clear dos ultimos n elementos e cria uma nova semente
			for (int i = 0; i < N; i++)
			{
				ptrSensores->readings[counter] = 0; // limpar o elemento
				counter --;							// mover para o elemento anterior
			}
			counter ++;
			dev_random();	 						// gerar numa nova semente
			ptrSensores->errors = 0;				// reset do numero de erros
			ptrSensores->counter = counter;     // reset do numero de element
			}
	}
}
Sensor * changeSensors(Sensor *ptrSensores, unsigned short totalSensores, unsigned short *numeroSensores)
{
	int option;
	printf("-----------------------------------------------\n");
	printf("|Já se passou 12h - pertende fazer alterações?|\n");
	printf("-----------------------------------------------\n");
	printf("| 1- sim                                      |\n");	
	printf("| Qualquer outro número - não                 |\n");
	printf("-----------------------------------------------\n");

	scanf("%d", &option);

	if(option == 1){
		do{
		printf("\n");
		printf("-------------------------------------------------\n");
		printf(" 1- Acrescentar sensores de um dado tipo\n");
		printf(" 2- Remover sensores de um dado tipo\n");
		printf(" 3- Alterar a frequência de leituras de um sensor\n");
		printf("-------------------------------------------------\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			ptrSensores = addSensor(ptrSensores, totalSensores, numeroSensores);
			break;
		case 2:
			ptrSensores = removeSensor(ptrSensores, totalSensores, numeroSensores);
			break;

		case 3:
			changeFrequency(ptrSensores, totalSensores);
			break;
		}
		printf("-------------------------------\n");
		printf("|Quer fazer mais alterações?  |\n");
		printf("-------------------------------\n");
		printf("| 1- sim                      |\n");
		printf("| Qualquer outro número - não |\n");
		printf("-------------------------------\n");
		scanf("%d", &option);
		}while(option == 1);
	}
	return ptrSensores;

}
Sensor * addSensor(Sensor *ptrSensores, unsigned short totalSensores, unsigned short *numeroSensores)
{
	unsigned long dadosTemporarios[4];
	int i, n, tipoSensor;
	printSensorsTypes();
	do{
	printf("Pertende adicionar um sensor de que tipo? ");
	scanf("%d",&tipoSensor);
	}while(tipoSensor > 7 && tipoSensor < 0);
	do{
	printf("Existem %d sensores desse tipo. Quantos quer adicionar? ", numeroSensores[tipoSensor - 1]);
	scanf("%d", &n);
	}while( n <= 0);
	ptrSensores = (Sensor *)realloc(ptrSensores, (totalSensores + n ) * sizeof(Sensor));
	if (ptrSensores == NULL)
	{
		printf("Erro na adição de sensores");
		exit(0);
		
	}
	for(i=0; i<totalSensores; i++)
	{
		if(ptrSensores[i].sensor_type == tipoSensor)
		{
			dadosTemporarios[0] = ptrSensores[i].max_limit;
			dadosTemporarios[1] = ptrSensores[i].min_limit;
			dadosTemporarios[2] = ptrSensores[i].frequency;
			dadosTemporarios[3] = ptrSensores[i].readings_size;
			break;
		}
	}
	unsigned short novoTotalSensores = totalSensores + n;
	for(i=0; i<novoTotalSensores; i++)
	{
		ptrSensores[i].totalSensors = novoTotalSensores;
	}
	Sensor *ptr = &ptrSensores[totalSensores];
	Sensor s;
	for (i = totalSensores; i < novoTotalSensores; i++)
	{
		numeroSensores[tipoSensor] += 1;
		s.id = numeroSensores[tipoSensor];
		s.counter = 0;
		s.errors = 0;
		s.sensor_type = tipoSensor;
		s.frequency = dadosTemporarios[2];
		s.readings_size = trunc((dadosTemporarios[3])/2);
		unsigned long *ptrValores = (unsigned long * ) malloc(s.readings_size * sizeof(unsigned long));
		if(ptrValores == NULL)
		{
			printf("Erro a criar a array dinamica de leitura.\n");
			exit(1);
		}
		s.readings = ptrValores ;
		s.max_limit = dadosTemporarios[0];
		s.min_limit = dadosTemporarios[1];
		*ptr = s;
		createFirstValue(ptr, (unsigned short) 1);
		ptr ++;
	}
	return ptrSensores;
}
Sensor * removeSensor(Sensor *ptrSensores, unsigned short totalSensores, unsigned short *numeroSensores)
{
	int i,j,n,tipoSensor,removeId;
	printSensorsTypes();
	do
	{
	printf("Pertende remover um sensor de que tipo? ");
	scanf("%d", &tipoSensor);
	} while (tipoSensor > 7 && tipoSensor < 0);
	do
	{
	printf("Existem %d sensores desse tipo. Quantos quer remover? ", numeroSensores[tipoSensor- 1]);
	scanf("%d", &n);
	} while (n > numeroSensores[tipoSensor- 1]);
	unsigned short novoTotalSensores = totalSensores;
	for(i = 0; i < n; i++)
	{
		novoTotalSensores --;
		for (j=0; j < totalSensores; j++)
		{
			if (ptrSensores[j].sensor_type == tipoSensor)
			{
				removeId = j ;

				break;
			}
		}
		for (j = removeId ; j < novoTotalSensores; j++)
		{
			ptrSensores[j] = ptrSensores[j + 1];
		}
	}
	ptrSensores = (Sensor *)realloc(ptrSensores, novoTotalSensores * sizeof(Sensor));
	if (ptrSensores == NULL)
	{
		printf("Erro a remover os sensores");
		exit(0);
	}
	for (i = 0; i < novoTotalSensores; i++)
	{
		ptrSensores[i].totalSensors = novoTotalSensores;
	}
	return ptrSensores;
}	
void changeFrequency(Sensor * ptrSensores, unsigned short totalSensores)
{
	int i, n, tipoSensor;
	printSensorsTypes();
	do
	{
		printf("Pertende mudar a frequência de que tipo de sensor ? ");
		scanf("%d", &tipoSensor);
	} while (tipoSensor >= 7 || tipoSensor <= 0);
	do
	{
		printf("Qual a frequência pertendida ? ");
		scanf("%d", &n);
	} while (n <= 0);
	for(i = 0; i < totalSensores; i++)
	{
		if(ptrSensores[i].sensor_type == tipoSensor - 1)
		{
			ptrSensores[i].frequency = n;
			ptrSensores[i].readings_size = (ptrSensores[i].readings_size / 2) + trunc(MEIO_DIA / n);
			ptrSensores[i].readings = (unsigned long *)realloc(ptrSensores[i].readings, ptrSensores[i].readings_size * sizeof(unsigned long));
		}
	}

}
void status(Sensor *ptrSensores)
{
	unsigned short totalDeSensores = ptrSensores[0].totalSensors;
	// Se existir um ficheiro igual, será removido
	FILE *file = fopen(STATUS_PATH, "r");
	if (file)
	{
		remove(STATUS_PATH);
		fclose(file);
	}

	FILE *matrixStatus = fopen(STATUS_PATH, "w+"); // cria o ficheiro só para escrever
	int i,j;
	fprintf(matrixStatus,"Tipo de Sensor; ID; Max; Min; Media\n");
	for (i = 0; i < totalDeSensores; i++)
	{
		// Inicializar o somatorio de todos os elementos (para a média)
		int sum = 0;
		// Print do tipo e ID do sensor
		printf("Tipo de Sensor = %d  -> ID= %d   ", ptrSensores[i].sensor_type, ptrSensores[i].id);
		fprintf(matrixStatus, "%d;%d;", ptrSensores[i].sensor_type, ptrSensores[i].id);
		// Inicializar o max e min igual ao primeiro elemento
		int max;
		int min;
		min = max = ptrSensores[i].readings[0];
		for (j = 0; j < ptrSensores[i].readings_size; j++)
		{
		// Verificar  o valor mais baixo
		if (min > (int)ptrSensores[i].readings[j])
		{
			min = (int)ptrSensores[i].readings[j];
		}
		// Verificar o valor mais alto
		if (max < (int)ptrSensores[i].readings[j])
		{
			max = (int)ptrSensores[i].readings[j];
		}
		// somatório de todos os elemtos
		sum += (int)ptrSensores[i].readings[j];
		}
		// calculo da media
		float media = (float)sum / (float)ptrSensores[i].readings_size;
		// print do valor maximo e minimo
		printf("-> max= %u   min= %u -> Media =  %.2f\n", max, min, media);
		fprintf(matrixStatus, "%u;%u;%.2f\n", max, min, media);
	}
	fclose(matrixStatus);
}

void dev_random()
{
	uint32_t buffer[64];
	FILE *f;							// pointer para aceder o ficheiro
	int result;
	f = fopen("/dev/urandom", "r");		// ler o ficheiro no caminho "dev/urandom"
	if (f == NULL)
	{
		printf("Error: open() failed to open /dev/random for reading\n");
	}
	result = fread(buffer, sizeof(uint32_t), 64, f);			// ler  um conjunto de números
	if (result < 1)
	{
		printf("error , failed to read and words\n");
	}
	int v1 = pcg32_random_r() % 64; // "random" number 0-64
	int v2 = pcg32_random_r() % 64; // "random" number 0-64
	state = buffer[v1];
	inc = buffer[v2];
	
}
void printSensorsTypes()
{
	printf("----------------------------------\n");
	printf(" ID:1- Sensor Velocidade do vento \n");
	printf(" ID:2- Sensor Direcao do vento    \n");
	printf(" ID:3- Sensor Temperatura         \n");
	printf(" ID:4- Sensor Pluviosidade        \n");
	printf(" ID:5- Sensor Humidade Atmosférica\n");
	printf(" ID:6- Sensor Humidade no solo    \n");
	printf("----------------------------------\n");
}
void freeAll(Sensor *ptrSensores)
{
	unsigned short totalDeSensores = ptrSensores[0].totalSensors;
	int i;

	for (i = 0; i < totalDeSensores ; i++)
	{
		free((ptrSensores[i].readings));
	}
	free(ptrSensores);
}