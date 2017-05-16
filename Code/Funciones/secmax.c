#include <stdio.h>

double secuencia (int * min, int * max)
{
    int x, cont = 1;
    double media = 0;

    if(scanf("%d",&x) == EOF)
        return (double) -1; /* entrada vacia */
    *min = *max = x;
    media = (double) x;
    while(scanf("%d",&x) != EOF)
    {
        if(x < *min)
             *min = x;
        else if(x > *max)
                  *max = x;
        media += (double) x;
        cont++;
    }
    return (double) media/cont;
}

void main()
{
    int min, max;
    double media = secuencia(&min, &max);

    if(media != -1)
        printf("\nMinimo = %d, Maximo = %d, Media = %lf\n",min,max,media);
    else printf("\nEntrada vacia\n");
}
