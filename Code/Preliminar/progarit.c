
#include <stdio.h>

/*
     Decidir si los elementos de entrada
     forman una progresion aritmetica, y
     calcular la diferencia en su caso.
 */

void main()
{
    int status, ant, act, dif, pa;

    pa = 0;                      /* De momento no hay progresion */

    if(scanf("%d",&ant) == EOF)
    {
        printf("\n**** Secuencia vacia\n");
        return;
    }
    if(scanf("%d",&act) == EOF)
    {
        printf("\n**** Solo hay un numero en la secuencia\n");
        return;
    }

    dif = act - ant;     /* Al menos hay dos numero */
    ant = act;
    pa  = 1;          /* De momento hay progresion de diferencia dif */

    while(pa && scanf("%d",&act) != EOF)
        if(act != ant + dif)
            pa = 0;             /* Fallo, no puede haber progresion */
        else ant = act;         /* Actualizar anterior, otra vuelta */

    switch(pa)
    {
        case 0:
            printf("\n*** No hay progresion aritmetica.");
            break;
        case 1:
            printf("\n*** Hay progresion aritmetica ");
            printf("con diferencia %d.", dif);
            break;
    }

}
