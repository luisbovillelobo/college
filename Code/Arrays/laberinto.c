
#include <stdio.h>
#include <stdlib.h>

#define N 5

/*********** Tipos y prototipos de funcion ***********************/

typedef int Tablero [N][N];

void escribir (Tablero, FILE *);
int enborde (int, int);
int adyac (int, int, int, int);
int camino (FILE *, Tablero);

/*****************************************************************/

void escribir (Tablero T, FILE * fs)
{
   int i, j;

   for(i = 0; i < N; i++)
   {
     for(j = 0; j < N; j++)
       fprintf(fs," %c", T[i][j] ? 'X' : '*');

     fprintf(fs,"\n");
   }
}

/*****************************************************************/

int enborde (int i, int j)
{
   return i == 0 || i == N - 1 || j == 0 || j == N - 1;
}

/*****************************************************************/

int adyac (int i, int j, int r, int s)
{
   return abs(i - r) <= 1 && abs(j - s) <= 1;
}

/*****************************************************************/

int camino (FILE * fe, Tablero T)
{
   int i, j, r, s;

   fscanf(fe,"%d %d",&i,&j);

   T[i][j] = 1;

   if(enborde(i,j) == 0)
            return 1;
   r = i;
   s = j;

   while(fscanf(fe,"%d %d",&r,&s) != EOF)
     if(T[r][s])
          return 2;
     else if(adyac(i,j,r,s))
              {
                 T[r][s] = 1;
                 i = r;
                 j = s;
              }
              else return 3;

   if(enborde(r,s) == 0)
             return 4;

   return 0;
}

/*****************************************************************/

void main()
{
   Tablero Tabla = <%0%>;
   FILE * fent, * fsal;


   if((fent = fopen("lab.txt","r")) == NULL)
   {
      puts("Error fichero de entrada");
      return;
   }

   if((fsal = fopen("salab.txt","w")) == NULL)
   {
      puts("Error fichero de salida");
      return;
   }

   switch(camino(fent,Tabla))
   {
       case 0: printf("\n Hay camino correcto\n");
               escribir(Tabla,fsal);
               break;
       case 1: printf("\n ** Error, camino no empieza en borde\n");
               break;
       case 2: printf("\n ** Error, casilla repetida\n");
               break;
       case 3: printf("\n ** Error, casilla no adyacente\n");
               break;
       case 4: printf("\n ** Error, camino no termina en borde\n");
               break;
   }

   fclose(fent);
   fclose(fsal);
}

