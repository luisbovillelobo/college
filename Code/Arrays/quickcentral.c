
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 11500

/********** Prototipos de funcion *******************/

void cargar (int []);
int  pintar (int []);
void quicksort (int [], int, int);

/****************************************************/

void main()
{
    int A[N];

    srand(time(NULL));

    cargar(A);

    printf("\n\nArray sin ordenar:  ");
    pintar(A);

    quicksort(A, 0, N - 1);

    printf("\n   Array ordenado:  ");
    pintar(A);
}

/****************************************************/

void quicksort (int A[], int inf, int sup)
{
    int i = inf;
    int j = sup;
    int pivot = A[(inf + sup)/2];

    while(i <= j)
    {
        while(A[i] < pivot) i++;
        while(A[j] > pivot) j--;
        if(i <= j)
        {
           int temp = A[i];
               A[i++] = A[j];
               A[j--] = temp;
        }
    }

    if(inf < j) quicksort(A,inf,j);
    if(i < sup) quicksort(A,i,sup);
}

/****************************************************/

void cargar (int A[])
{
   int i, num, sig;

   for(i = 0; i < N; i++)
      {
         num = rand() % N;
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




