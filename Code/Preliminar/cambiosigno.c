
/* Contar cuantas cambios de signo se
 * producen en una secuencia de enteros
 */

#include <stdio.h>

void main()
{
   int ant, act, cont = 0;

   if(scanf("%d",&ant) == EOF)
   {
       printf("Secuencia vacia\n");
       return;
   }

   while(scanf("%d",&act) != EOF)
    if(act)
    {
        if(ant * act < 0)
              cont++;
        ant = act;
    }
    printf("Hay %d cambios de signo\n",cont);
}
