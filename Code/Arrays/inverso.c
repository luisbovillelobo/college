#include <stdio.h>

#define N 7

/*
     Invertir un vector
 */

/******* Prototipos de funcion ****************************/

void inverso (int []);

/**********************************************************/

void main()
{
   int i;
   int vector[] = {1,2,3,4,5,6,7};

   inverso(vector);

   for(i = 0; i < N; printf("%d ",vector[i++]));
}

/**********************************************************/

void inverso (int A[])
{
   int temp;
   int i = 0, j = N - 1;

   while(i < j)
   {
      temp = A[i];
      A[i++] = A[j];
      A[j--] = temp;
   }
}