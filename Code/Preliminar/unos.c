
#include <stdio.h>

/*
     Secuencia de 0's o 1's
     estrictamente mas larga
 */

void main()
{
   int x, tipo, plong = 0, mlong = 0, mtipo = 2;

   if(scanf("%d",&x) != EOF) {
      tipo = x;
      plong = 1;
   }

   while(scanf("%d",&x) != EOF)
      if(x == tipo)    /* el while solo tiene   */
             plong++;  /* una sentencia if-else */
      else 
      {
          if(plong > mlong) {
                  mlong = plong;
                  mtipo = tipo;
                  plong = 1;     
          }
          else if(plong == mlong) {
                     mtipo = 2;
                     plong = 1;
               }
               else plong = 1;
        
          tipo = x;
      }
   
   if(plong > mlong) {
           mlong = plong;
           mtipo = tipo;
   }
   else if(mlong == plong)
              mtipo = 2;

   if(mtipo != 2) {
        printf("\nLa cadena mas larga tiene ");
        printf("%d caracteres y es de %d's.",mlong,mtipo);
   }
   else printf("\nNo hay secuencia mas larga.");  
}