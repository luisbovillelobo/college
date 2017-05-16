
#include <stdio.h>
#include <math.h>

typedef enum {FALSE,TRUE} BOOLEAN; /* FALSE = 0, TRUE = 1 */

/*
      Decide si un numero es primo
 */

void main()
{
   int x, i, cota;
   BOOLEAN esprimo = TRUE;

   do
        scanf("%d",&x);
   while(x < 2);

   i = 2;
   cota = (int) floor(sqrt(x));

   while(esprimo && i <= cota)
     if(x % i == 0)
            esprimo = FALSE;
     else i++;

   printf("\nEl numero %d",x);
   if(! esprimo) printf(" no");
   printf(" es primo.\n");
}
