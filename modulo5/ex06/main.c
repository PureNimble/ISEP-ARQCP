#include <stdio.h>
#include "fill_student.h"
#include "update_address.h"
#include "locate_greater.h"
#include <string.h>


int main(){

    Student vec[5];

    Student * s = vec;

    char nome [80] = "Antonio";
    char *ptrnome = nome;
    char address [120] = "Rua 3, 454";
    char *ptraddress = address;
    fill_student(s, 18, 100, ptrnome, ptraddress);
    printf("Nome: %s\nIdade: %d\nNumero: %d\nAddress: %s\n\n\n", s->name, s->age, s->number, s->address);
    s++;

    strcpy(ptrnome, "Ana");
    strcpy(ptraddress,"Rua 5, 123");
    fill_student(s, 19, 101, ptrnome, ptraddress);
    printf("Nome: %s\nIdade: %d\nNumero: %d\nAddress: %s\n\n\n", s->name, s->age, s->number, s->address);
    s++;

    strcpy(ptrnome, "Raul");
    strcpy(ptraddress,"Rua 15, 153");
    fill_student(s, 19, 102, ptrnome, ptraddress);
    printf("Nome: %s\nIdade: %d\nNumero: %d\nAddress: %s\n\n\n", s->name, s->age, s->number, s->address);
    s++;

    strcpy(ptrnome, "Nuno");
    strcpy(ptraddress,"Rua 979, 13");
    fill_student(s, 19, 103, ptrnome, ptraddress);
    printf("Nome: %s\nIdade: %d\nNumero: %d\nAddress: %s\n\n\n", s->name, s->age, s->number, s->address);
    s++;

    strcpy(ptrnome, "Nelson");
    strcpy(ptraddress,"Rua Prg, 0");
    fill_student(s, 19, 104, ptrnome, ptraddress);
    printf("Nome: %s\nIdade: %d\nNumero: %d\nAddress: %s\n\n\n", s->name, s->age, s->number, s->address);

    //Nova morada e apontador para a mesma
    char new_address_string [120] = "Rua do Isep,123";
    char *new_address = new_address_string;
    //Chama a função que substitui a address
    update_address(s, new_address);
    //Imprime o ultima estrutura, pois é esta que é passada por parametro
    printf("Nome: %s\nIdade: %d\nNumero: %d\nAddress: %s\n\n\n", s->name, s->age, s->number, s->address);


    int grades [10] = {1,2,3,4,5,6,7,8,9,10};
    int *newgrades = grades;
    update_grades(s, newgrades);
    printf("Nome: %s\nIdade: %d\nNumero: %d\nAddress: %s\n", s->name, s->age, s->number, s->address);
    int i;
    printf("Grades: ");
    for(i = 0; i < 10; i++){
        printf("  %d     ", s->grades[i]);
    }
    printf("\n"); 

    int minimum = 8;
    int vec_greater_grades[10];
    int *greater_grades = vec_greater_grades;
    int result = locate_greater(s, minimum, greater_grades);
    printf("Número de notas superior ao mínimo(%d): %d\n", minimum, result);

    return 0;
}