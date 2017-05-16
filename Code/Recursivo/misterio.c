#include <stdio.h>

void Misterio (void);

/*
    ¿Que hace este programa?
 */

void main()
{
   Misterio();
}

void Misterio()
{
   int c;

   c = getchar();

   if(c != '\n') Misterio();
  
   printf("%c",c);
}