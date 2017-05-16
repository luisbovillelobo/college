
#include <stdio.h>

/******** Prototipos de funcion *********/

void factprim (long int); 

/****************************************/

void main()
{
   long int x;

   for(;;) /* Probar varios numeros */
   {
      scanf("%ld",&x);
      if(x < 2)
           break;
      factprim(x);
      printf("\n");
   }
}

/*  Escribe la descomposicion
    en factores primos
 */

void factprim (long int x)
{
   long int div = 2;

   while(x > 1)
   {
      while(x % div == 0)
      {
         printf("%ld ",div);
         x /= div;
      }
      div++;
   }
}