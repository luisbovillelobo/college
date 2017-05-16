
#include <stdio.h>

#define N 100

void main()
{
    int   k, signo = 1;
    float x, term, suma;

    suma = term = 1.0;
    scanf("%f",&x);

    for(k = 1; k <= N; k++)
    {
        signo = -signo;
        term = term * x / (k * k);
        suma += signo * term;
    }
    printf("Suma = %f\n",suma);
}
