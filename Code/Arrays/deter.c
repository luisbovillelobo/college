
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#define  N  6

/*********** Tipos y prototipos de funcion ***************************/

typedef double MATRIZ [N][N];
typedef enum {FALSE,TRUE} BOOLEAN;

void Inicializar (MATRIZ);
void Escribir (MATRIZ);
int BuscarNoNulo (MATRIZ, const int);
void CambCol (MATRIZ, const int, const int);
void SumaFila (MATRIZ, const double, const int, const int);
void HacerCeros (MATRIZ, int *);

/*********** Variables globales **************************************/

FILE * Output;

/*********************************************************************/

void Inicializar (MATRIZ M)
{
  int i, j, num;

   for(i = 0; i < N; i++)
      for(j = 0; j < N; j++)
      {
         num = rand() % 3;
         M[i][j] = (num % 2) ? num : -num;
      }
}

/*********************************************************************/

void Escribir (MATRIZ M)
{
   int i, j;

   for(i = 0; i < N; i++)
   {
      for(j = 0; j < N; j++)
            fprintf(Output,"%10.5lf",M[i][j]);

      fprintf(Output,"\n");
   }

   fprintf(Output,"\n");
}

/*********************************************************************/

int BuscarNoNulo (MATRIZ M, const int f)
{
   int c;

   fprintf(Output,"** Entra buscar no nulo, fila = %d\n",f);

   for(c = f + 1; c < N; c++)
         if(M[f][c])
                 break;
   return c;
}

/*********************************************************************/

void CambCol (MATRIZ M, const int c1, const int c2)
{
   int f;
   double aux;

   fprintf(Output,"** Entra cambiar columna %d y %d\n",c1,c2);

   for(f = 0; f < N; f++)
   {
      aux = M[f][c1];
      M[f][c1] = M[f][c2];
      M[f][c2] = aux;
   }
}

/*********************************************************************/

void SumaFila (MATRIZ M, const double piv, const int f1, const int f2)
{
   int c;

   fprintf(Output,"** Entra sumar fila, pivote = %10.5lf\n",piv);

   for(c = f1; c < N; c++)
              M[f2][c] += piv * M[f1][c];
}

/*********************************************************************/

void HacerCeros (MATRIZ M, int * signo)
{
   int i, f, c;
   double  piv;
   BOOLEAN parar = FALSE;

   *signo = 1;

   for(i = 0; ! parar && i < N; i++)
   {
      if(M[i][i] == 0)
      {
         c = BuscarNoNulo(M,i);
         Escribir(M);

         if(c == N)
                 parar = TRUE;
         else {
                 CambCol(M,i,c);
                 Escribir(M);
              }

         *signo = -*signo;
      }

      if(parar)
           fprintf(Output,"*** Fila nula !!!\n");
      else for(f = i + 1; f < N; f++)
                if(M[f][i])
                {
                   piv = -M[f][i]/M[i][i];
                   SumaFila(M,piv,i,f);
                }

      Escribir(M);
   }
}

/*********************************************************************/

void main()
{
   MATRIZ   M;
   double det;
   int j, signo;

   if((Output = fopen("Salida.txt","w")) == NULL)
   {
       printf("*** Error en fichero de salida\n");
       return;
   }

   srand(time(NULL));

   Inicializar(M);
   Escribir(M);

   HacerCeros(M,&signo);

   det = 1;
   for(j = 0; j < N; j++) det *= M[j][j];

   fprintf(Output,"*** Determinante = %10.5lf\n",signo * det);

   fclose(Output);
}
