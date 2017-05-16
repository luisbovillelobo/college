
#include <stdio.h>

#define N 4

int critico (int [][N], int, int);
float mediac (int [][N], int *, int *);

void main()
{
   int A[N][N] = {1,3,-2,0,1,4,0,-1,1,5,-1,3,-2,-5,-1,6};
   int i, j;

   float media;

   for(i = 0; i < N; i++)
     for(j = 0; j < N; j++)
           if(critico(A,i,j))
               printf("Pto. critico : %d %d\n",i,j);
   media = mediac(A, &i, &j);

   if(media != 0)
   {
       printf("Media = %f\n", media);
       printf("Maximo = %d, Pos =[%d,%d]\n",A[i][j],i,j);
   }
   else printf("No hay elementos criticos\n");

}

int critico (int A[N][N], int i, int j)
{
   int k, suma = 0;

   for(k = 0; k < N; k++)
   {
       if(k != j) suma += A[i][k];
       if(k != i) suma += A[k][j];
   }
   return suma == A[i][j];
}

float mediac (int A[N][N], int * fil, int * col)
{
    float media = 0.0;
    int  i, j, cont = 0, hayc = 0;

    *fil = -1; *col = -1;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
          if(critico(A,i,j))
          {
             if(hayc == 0)
              {
                  hayc = 1;
                  *fil = i;
                  *col = j;
              }
              else if(A[i][j] > A[*fil][*col])
                   {
                       *fil = i;
                       *col = j;
                   }
              media += A[i][j];
              cont++;
          }
          printf("cont = %d\n",cont);
     return hayc ? media/cont : 0;
}
