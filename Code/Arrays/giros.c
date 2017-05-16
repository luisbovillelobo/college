#include <stdio.h>

#define N 5

int esgiro (int [], int [], int *);

void main()
{
  int A[] = {1,2,3,4,5};
  int B[] = {1,2,3,4,5};
  int tamgiro;

  if(esgiro(A,B,&tamgiro))
       printf("Es giro, tamgiro = %d.\n",tamgiro);
  else printf("No hay giro, tamgiro = %d.\n",tamgiro);
}

int esgiro (int A[], int B[], int * tamgiro)
{
   int i, k, girado = 0;

   i = 0;

   while(! girado && i < N)
      if(A[0] == B[i])
      {
         *tamgiro = i;
         girado = 1;
      }
      else i++;

   if(girado)
   {
      k = 1; i = ++i % N;

      while(girado && k < N)
         if(A[k] == B[i])
         {
            k++;
            i = ++i % N;
         }
         else girado = 0;
   }

   if(! girado) *tamgiro = -1;

   return girado;
}
