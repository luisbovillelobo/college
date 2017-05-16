
#include <stdio.h>

void dec2bin (int);

/*
    Hacer un seguimiento de este
    programa. ¿Que es la salida?
 */

void main()
{
   int k;

   do {
         scanf("%d",&k);
         dec2bin(k);
         printf("\n"); 
   } while(k > 0);
}

void dec2bin (int n)
{
   if(n > 0)
   {
      dec2bin(n/2);
      printf("%d", n % 2);
   }
}