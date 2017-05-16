#include <stdio.h>

/*
     Contar letras, digitos, numeros,
     saltos de linea y otros caracteres
 */

void main()
{
    int car;
    int letmin,letmay,digit,saltos,otros;

    letmin = letmay = digit = saltos = otros = 0;

    while((car = getchar()) != EOF)
        if(car >= 'a' && car <= 'z')
            letmin++;
        else if(car >= 'A' && car <='Z')
            letmay++;
        else if(car >= '0' && car <= '9')
            digit++;
        else if(car == '\n')
            saltos++;
        else
            otros++;

    printf("\nEn el texto hay %3d letras minusculas,",letmin);
    printf("\n                %3d letras mayusculas,",letmay);
    printf("\n                %3d digitos,",digit);
    printf("\n                %3d saltos de linea,",saltos);
    printf("\n                %3d caracteres especiales.\n\n",otros);

}
