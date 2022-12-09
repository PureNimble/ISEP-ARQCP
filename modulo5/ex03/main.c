#include <stdio.h>
#include "c.h"
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


    return 0;
}
