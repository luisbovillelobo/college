
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 500

/********** Prototipos de funcion *******************/

void cargar (int []);
int  pintar (int []);
void insertionsort (int [], int);

/****************************************************/

void main()
{
    int A[N];

    srand(time(NULL));

    cargar(A);

    printf("\n\nArray sin ordenar:  ");
    pintar(A);

    insertionsort(A, N);

    printf("\n   Array ordenado:  ");
    pintar(A);
}

/****************************************************/

void insertionsort (int A[], int n)
{
   int i, j;

   for(j = 1; j < n; j++)
   {
       int valor = A[j];
       i = j - 1;

/*        Desplaza elementos de A[0..j-1] que son
          mayores que valor una posición más de la
          que ocupan actualmente
*/
       while(i >= 0 && A[i] > valor)
       {
           A[i + 1] = A[i];
           i--;
       }
       A[i + 1] = valor;
   }
}

/****************************************************/

void cargar (int A[])
{
   int i, num, sig;

   for(i = 0; i < N; i++)
      {
         num = rand() % 150;
         A[i] = num;
      }
}

/****************************************************/

int pintar (int A[])
{
    int i;

    for(i = 0; i < N; i++) printf(" %d ", A[i]);
    printf("\n\n");
}




