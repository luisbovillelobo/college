#include <stdio.h>

#define N 10

/*
     Determinar si una cadena es capicua
 */

/******* Prototipos de funcion ****************************/

int capicua (const char *);
int capicua2 (const char []);

/**********************************************************/

void main()
{
   int  i;
   char cadena[N];

   for(i = 0; i < N; i++)
         scanf("%c",&cadena[i]);

   if(capicua2(cadena))
        printf("\n Cadena capicua");
   else printf("\n Cadena no capicua");
}

/**********************************************************/

int capicua (const char * A)
{
   const char * s = A, * t = &A[N - 1];

   while(s <= t && *s == *t)
   {
      s++;
      t--;
   }
   return s > t;
}

/**********************************************************/

int capicua2 (const char A[])
{
   int i = 0, j = N - 1;

   for( ; i <= j && A[i] == A[j]; i++, j--);

   return i > j;
}