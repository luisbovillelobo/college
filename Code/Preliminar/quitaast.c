
#include <stdio.h>

/*
     Quitar asteriscos consecutivos
     excepto uno de ellos   
 */

void main()
{
   int ant, act;
  
   ant = 'z'; /* cualquier cosa menos un '*' */

   while((act = getchar()) != EOF)
   {
     if(ant != '*' || act != '*')
                putchar(act);
     ant = act;
   }
}