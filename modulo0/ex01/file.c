#include<stdio.h>
int main() {
	char charType;
    int intType;
    unsigned int uintType;
    long longType;
    short shortType; 
    long long longLongType;
    float floatType;
    double doubleType;
    
   
    // Size of the dataTypes
    
    printf("Size of char: %lu bytes\n", sizeof(charType));
    printf("Size of int: %lu bytes\n", sizeof(intType));
    printf("Size of unsigned int: %lu bytes\n", sizeof(uintType));
    printf("Size of long: %lu bytes\n", sizeof(longType));
    printf("Size of short: %lu bytes\n", sizeof(shortType));
    printf("Size of long long: %lu bytes\n", sizeof(longLongType));
    printf("Size of float: %lu bytes\n", sizeof(floatType));
    printf("Size of double: %lu bytes\n", sizeof(doubleType));
    
    
    return 0;
}
