
#include <stdio.h>

#define N 100

/********** Prototipos de funcion *******************/

void Cargar (int []);
int  Pintar (int []);

void MergeSort (int [], int, int);
void Merge (int [], int, int, int);

/****************************************************/

void main()
{
    int A[N];

    srand(time(NULL));

    Cargar(A);

    printf("\n\nArray sin ordenar:  ");
    Pintar(A);

    MergeSort(A, 0, N - 1);

    printf("\n   Array ordenado:  ");
    Pintar(A);
}

/****************************************************/

void MergeSort (int A[], int inf, int sup)
{
    int centro;

    if(inf < sup)
    {
        centro = (inf + sup)/2;
        MergeSort(A, inf, centro);
        MergeSort(A, centro + 1, sup);
        Merge(A, inf, centro, sup);
    }
}

void Merge (int A[], int inf, int med, int sup)
{
    int i, j, k, index;
    int temp[sup - inf + 1];

    i = inf; j = med + 1;

/*   index = 0;
 *
 *   while(i <= med && j <= sup)
 *   {
 *         if(A[i] <= A[j])
 *         {
 *             temp[index] = A[i];
 *             i++;
 *         }
 *         else
 *         {
 *             temp[index] = A[j];
 *             j++;
 *         }
 *         index++;
 *   }
 */
    for(index = 0; i <= med && j <= sup; index++)
             temp[index] = A[i] <= A[j] ? A[i++] : A[j++];

    if(i > med)
        for(k = j; k <= sup; k++)
            temp[index++] = A[k];
    else
        for(k = i; k <= med; k++)
            temp[index++] = A[k];

    for(index = 0, k = inf; k <= sup; k++, index++)
            A[k] = temp[index];
}

/****************************************************/

void Cargar (int A[])
{
   int i, num, sig;

   for(i = 0; i < N; i++)
      {
         num = rand() % N;
         A[i] = num;
      }
}

/****************************************************/

int Pintar (int A[])
{
    int i;

    for(i = 0; i < N; i++) printf(" %d ", A[i]);
    printf("\n\n");
}




