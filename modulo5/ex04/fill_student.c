#include <stdio.h>
#include <string.h>
#include "fill_student.h"
void fill_student(Student *s, char age, short number, char *name,char *address){

 s->age = age; //s.age (apontado por (s + offset até age)) passa a ser a nova por parametro.
 s->number = number; //o number de s passa a ser o passado por parametro
 strcpy(s->name, name); // copiamos a string recebida por parametro para o apontado por s.name
 strcpy(s->address, address); // igual ao de cima mas para o apontado por s.address


}
