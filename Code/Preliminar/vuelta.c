
#include <stdio.h>

/*
     Escribe un numero al reves,
     utiliza descomposicion decimal
 */

void main()
{
   long int num, vnum = 0;

   scanf("%ld", &num);

   while(num > 0)
   {
      vnum = vnum * 10 + num % 10;
      num /= 10;
   }
   printf("%ld\n",vnum);
}
