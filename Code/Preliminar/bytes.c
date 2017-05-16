
#include <stdio.h>

void main ()
{
    int var[9];

    printf("Memoria ocupada por tipos simples:\n\n");

    printf("char ==> %d byte\n", sizeof(long double));
    printf("signed char ==> %d byte\n", sizeof(signed char));
    printf("unsigned char ==> %d byte\n", sizeof(unsigned char));
    printf("int ==> %d bytes\n", sizeof(int));
    printf("signed int ==> %d bytes \n", sizeof(signed int));
    printf("unsigned int ==> %d bytes \n", sizeof(unsigned int));
    printf("short ==> %d bytes \n", sizeof(short));
    printf("signed short ==> %d bytes\n", sizeof(signed short));
    printf("unsigned short ==> %d bytes\n", sizeof(unsigned short));
    printf("long ==> %d bytes\n", sizeof(long));
    printf("signed long ==> %d bytes\n", sizeof(signed long));
    printf("unsigned long ==> %d bytes\n", sizeof(unsigned long));
    printf("long long ==> %d bytes\n", sizeof(long long));
    printf("float ==> %d bytes\n", sizeof(float));
    printf("double ==> %d bytes\n", sizeof(double));
    printf("long double ==> %d bytes\n", sizeof(long double));
    printf("La variable 'var' ==> %d bytes\n", sizeof var);
}
