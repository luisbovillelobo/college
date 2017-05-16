
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 12

/********** Prototipos de funcion *******************/
void cargar (int []);
int  pintar (int []);

void quicksort (int [], int, int);
int particion (int [], int, int);


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
    int p;

    if(inf < sup)
    {
        p = particion(A,inf,sup);

        printf("\npivote = %d, A[%d] = %d ==> ", p, p, A[p]);
        pintar(A);
        quicksort(A,inf,p - 1);
        quicksort(A,p + 1,sup);
    }
}

/****************************************************/

int particion (int A[], int inf, int sup)
{
    int pivot, i, j, temp;

    pivot = A[inf];
    i = inf;
    j = sup + 1;

    for(;;)
    {
        do
            ++i;
        while (A[i] <= pivot && i <= sup);

        do
            --j;
        while (A[j] > pivot);

        if(i >= j) break;

        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }

    temp = A[inf];
    A[inf] = A[j];
    A[j] = temp;

    return j;
}

/****************************************************/

void cargar (int A[])
{
   int i, num, sig;

   for(i = 0; i < N; i++)
      {
         num = rand() % 100;
         sig = rand();
         A[i]= (sig % 2) ? num : -num;
      }
}

/****************************************************/

int pintar (int A[])
{
    int i;

    for(i = 0; i < N; i++) printf(" %d ", A[i]);
    printf("\n\n");
}




