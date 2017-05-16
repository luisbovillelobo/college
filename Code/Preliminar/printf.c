
#include <stdio.h>

void main()
{
    char  a,b,c;
    int   i,j,k;

    a = 5;
    b = 2;
    c = 3;

    /** Aunque son char pueden tratarse como un numero **/

    printf("a = %d, b = %d, c = %d\n",a,b,c);

    /** Ahora como caracteres **/
    a = '*';
    b = 'm';
    c = '8';
    printf("a = %c, b = %c, c = %c\n",a,b,c);
    printf("a = %d, b = %d, c = %d\n",a,b,c); /** Todo depende como se pinte **/

    a = 5 + '$'; /** Numero + caracter, ¿Una barbaridad? **/
    printf("a = %d\n",a); /** NO, a = 10 + valor ASCII de '$' **/
    printf("a = %c\n",a); /** Esto es cuanto vale a como caracter **/

    i = 3;
    j = k = 15;
    printf("i = %d, j = %d, k = %d\n",i,j,k);
    printf("La suma de i, j y k es %d\n",i + j + k);

    printf("\n\n\n*** Modificar y experimentar con el programa.\n\n");
}

