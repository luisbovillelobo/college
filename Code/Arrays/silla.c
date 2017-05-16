
#include <stdio.h>

#define N 3

/********* Tipos y prototipos de funcion *************************/

typedef int MATRIZ [N][N];

void LeerMatriz (MATRIZ);
void EscMatriz (MATRIZ);
int Maximo (const int, MATRIZ);
int HayMin (const int, const int, MATRIZ);
int Silla (MATRIZ, int *, int *);

/*****************************************************************/

void LeerMatriz (MATRIZ A)
{
   int i,j;

   for(i = 0; i < N; i++)
      for(j = 0; j < N; j++)
            scanf("%d", &A[i][j]);
}

/*****************************************************************/

void EscMatriz (MATRIZ B)
{
   int i,j;

   for(i = 0; i < N; i++)
   {
      for(j = 0; j < N; j++)
           printf("%d ", B[i][j]);
      printf("\n");
   }
}

/*****************************************************************/

int Maximo (const int i, MATRIZ A)
{
   int j, k;

   for(j = 0,k = 1; k < N; k++)
     if(A[i][j] <= A[i][k])
     {
        if(A[i][j] == A[i][k])
           for(k++; k < N; k++)
             if(A[i][k] > A[i][j])
                     break;
        j = k;
     }
   return j;
}

/*****************************************************************/

int HayMin (const int i, const int j, MATRIZ A)
{
   int k;

   for(k = 0; k < N; k++)
     if(k != i && A[k][j] <= A[i][j])
                   return 0;
   return 1;
}

/*****************************************************************/

int Silla (MATRIZ A, int * fil, int * col)
{
   *fil = 0;

   while(*fil < N)
   {
      *col = Maximo(*fil,A);
      if(*col < N && HayMin(*fil,*col,A))
                     return 1;
      *fil += 1;
   }
   return 0;
}

/*****************************************************************/

void main(void)
{
   MATRIZ A;
   int fil, col;

   LeerMatriz(A);
   EscMatriz(A);

   if(Silla(A, &fil, &col))
      printf("Hay punto de silla [%d,%d] = %d\n",fil,col,A[fil][col]);
   else
      printf("No existe punto de silla\n");
}
