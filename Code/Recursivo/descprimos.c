#include <stdio.h>

void f (int, int); /*  Escribe la descomposicion
                       en factores primos
                    */
void main()
{
   int x;

   scanf("%d",&x);
   f(x,2);
}

void f (int num, int div)
{
   if(num > 1)
      if(num % div == 0)
      {
         printf ("%d\n",div);
         f(num/div,div);
      }
      else f(num,div + 1);
}