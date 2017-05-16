
#include <stdio.h>

void main()
{
   const int R =  1;
   const int N = 10;
   int x = 0, y = 0;
   int  valor, cont = 0;

   while(scanf("%d", &valor) != EOF)
   {
       cont++;
       switch(valor)
       {
           case 1: x++;
                   break;
           case 2: y++;
                   break;
           case 3: x--;
                   break;
           case 4: y--;
                   break;
       }
       if(x * x + y * y > R * R)
       {
           printf("\n La particula salio del circulo\n");
           return;
       }
       if(cont == N)
       {
           printf("\n La particula NO salio del circulo\n");
           return;
       }
   }
   printf("\n Datos insuficientes\n");
}
