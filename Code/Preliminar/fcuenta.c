#include <stdio.h>
/*
     Contar letras, digitos, numeros,
     saltos de linea y otros caracteres
 */

#define SUB 0x1A  /*  codigo ascii para detectar el
                      fin de stream de la consola ^Z,
                      usar solo en pruebas por teclado
                   */

void main()
{
    int car;
    int letmin,letmay,digit,blancos,saltos,otros;

    letmin = letmay = digit = 0;
    blancos = saltos = otros = 0;

    while((car = getchar()) != EOF)
    {
        if(car == SUB)
            /*   Fin stream consola ^Z
                 equivalente a EOF,
                 solo usar en pruebas
             */  break;

        if(car >= 'a' && car <= 'z')
                  letmin++;
        else if(car >= 'A' && car <='Z')
                  letmay++;
        else if(car >= '0' && car <= '9')
                   digit++;
        else if(car == ' ')
                  blancos++;
        else if(car == '\n')
                  saltos++;
        else
            otros++;
    }

    printf("\nEn el texto hay %3d letras minusculas,",letmin);
    printf("\n                %3d letras mayusculas,",letmay);
    printf("\n                %3d digitos,",digit);
    printf("\n                %3d blancos,",blancos);
    printf("\n                %3d saltos de linea,",saltos);
    printf("\n                %3d caracteres especiales.\n\n",otros);

}
