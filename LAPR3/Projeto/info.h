#ifndef INFO_H
#define INFO_H
#define DATA_PATH "../Resultados/matrixData.csv"
#define STATUS_PATH "../Resultados/matrixStatus.csv"
#define DIA 86400
#define MEIO_DIA 43200     // segundos de 1 meio dia
#define N_TIPOS_SENSORES 6 // numero de tipos de sensores
#define N 3                // N erros

//Estrutura dos sensores
typedef struct
{
    unsigned short id;              // id do sensor ( serve para identificar o sensor)
    unsigned char sensor_type;      // id do tipo de sensor (serve para identificar o tipo de sensor)
    unsigned short max_limit;       // limite máximo
    unsigned short min_limit;       // limite mínimo
    unsigned long frequency;        // frequencia de leituras (em segundos)
    unsigned long readings_size;    // tamanho da array de leituras
    unsigned long *readings;        // array de leituras diárias
    unsigned int counter;           // conta a posição do ultimo valor inserido na array
    unsigned int errors;            // conta o número de erros dados
    unsigned short totalSensors;    // total de sensores existentes
} Sensor;
//Funcao para gerar uma nova semente 
void dev_random();

//Funções para gerar todos os sensores e os primeiros valores
void createSensors(Sensor *ptr, unsigned short numeroSensores[N_TIPOS_SENSORES], unsigned long frequenciasSensores[N_TIPOS_SENSORES], unsigned short max_min_limite[N_TIPOS_SENSORES][2],unsigned short totalDeSensores);
void createFirstValue(Sensor *ptrSensores, unsigned short totalDeSensores);
// Funções para executar os sensores 
void execute_sensor(Sensor *ptr);
void execute_sensor_1(Sensor *ptr);
void execute_sensor_2(Sensor *ptr);
void execute_sensor_3(Sensor *ptr);
void execute_sensor_4(Sensor *ptr,Sensor *ptrTemp);
void execute_sensor_5(Sensor *ptr,Sensor *ptrPluvio);
void execute_sensor_6(Sensor *ptr,Sensor *ptrPluvio);

// Funções para calcular o status dos sensores
void status(Sensor *ptrSensores);
void checkMaxMin(Sensor *ptrSensores, unsigned short totalDeSensores);
void checkMedia(Sensor *ptrSensores, unsigned short totalDeSensores);
void checkError(Sensor *ptrSensores);

// Função que simula um dia
Sensor * daySimulation(Sensor *ptrSensores, unsigned short totalDeSensores, unsigned short *numeroSensores);
// Funções para dar print e scan
void printSensorsTypes();
void printArray(Sensor *ptrSensores, FILE *matrixData);
void printAllSensors(Sensor *ptrSensores);
unsigned short scanSensorsAndFrequencys(unsigned short numeroSensores[N_TIPOS_SENSORES], unsigned long frequenciasSensores[N_TIPOS_SENSORES], unsigned short max_min_limite[N_TIPOS_SENSORES][2]);

// Funções para alterar os sensores e frequências
Sensor * changeSensors(Sensor *ptrSensores, unsigned short totalSensore, unsigned short *numeroSensores);
Sensor * addSensor(Sensor *ptrSensores, unsigned short totalSensores, unsigned short *numeroSensores);
Sensor * removeSensor(Sensor *ptrSensores, unsigned short totalSensores, unsigned short *numeroSensores);
void changeFrequency(Sensor *ptrSensores, unsigned short totalSensores);

// Funções para libertar o espaço da memória dinamica
void freeAll(Sensor *ptrSensores);

// Funcao para gerar numeros "aleatorios"
uint32_t pcg32_random_r();
//variaveis globais de pcg32_random_r()
uint64_t  state = 0;
uint64_t  inc = 0;

#endif