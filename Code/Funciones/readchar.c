
#include <stdio.h>

int readchar // Utilizar SOLO en pruebas con teclado
{
    int c = getchar();

    return c == 0x1A ? EOF : c;
}

void main()
{
    int car;
    int letmin,letmay,digit,
        blancos,saltos,otros;

    letmin = letmay = digit = 0;
    blancos = saltos = otros = 0;

    while((car = readchar()) != EOF)
    {
        if(car >= 'a' && car <= 'z')
                  letmin++;
        else if(car >= 'A' && car <='Z')
                  letmay++;
        else if(car >= '0' && car <= '9')
                   digit++;
        else if(car ==' ')
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
