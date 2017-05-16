#include <stdio.h>

int sd (int);

int main()
{
    int i;

    for(i = 1; i < 10; i++)
    {
         printf("Numero = %d \n",i);
         sd(i);
    }
    sd(284);
}

int sd (int valor)

{
    int suma = 0;

    int i;

    for( i=1; i <= valor/2; i++)
    {
        if( (valor % i) ==0 )
        {
          printf("--------------Divisor = %d\n",i);
           suma += i;
        }

    }
    return suma;
}
