
#include <stdio.h>

#define MAXART 80
#define MAXCAR 25

/*********** Tipos y prototipos de funcion *******************/

typedef char String25 [MAXCAR + 1]; /* array de 25 char validos + '\0' */

typedef struct {
           int      CodArt;  /* Un articulo con codigo y nombre */
           String25 NomArt;
        } TipoArticulo;

typedef TipoArticulo TVector [MAXART]; /* Array de articulos */

typedef struct {
           int     NElem;
           TVector Datos;   
        } TipoLista;     /* Lista de articulos, NElem es el indice */


int  LeerArticulo (FILE *, TipoArticulo *);
void InsertarFinal (TipoArticulo *, TipoLista *);
void PintarLista (TipoLista *);

/*************************************************************/

void main()
{
   FILE * fp;
   TipoArticulo Art;
   TipoLista ListaArt;

   if((fp = fopen("fichart.txt","r")) == NULL)
   {
      printf("** Error en el fichero fichart.txt\n");
      return;
   }

   ListaArt.NElem = 0;
 
   while(LeerArticulo(fp,&Art))
                 InsertarFinal(&Art,&ListaArt);
   fclose(fp);
   
   PintarLista(&ListaArt);
}

/*************************************************************/

int LeerArticulo (FILE * fp, TipoArticulo * Art)
{
   char car;
   int  k = 0;

   if(fscanf(fp,"%d",&Art->CodArt) != EOF)
   {
      do
        fscanf(fp,"%c",&car);      /* saltar blancos */
      while(car == ' ');

      while(k < MAXCAR && car != '*')
      {
         Art->NomArt[k++] = car;
         fscanf(fp,"%c", &car);
      }
      
      Art->NomArt[k] = '\0';   /* finalizar string */

      return 1;
    }
    return 0;
}

/*************************************************************/

void InsertarFinal (TipoArticulo * Art, TipoLista * L)
{
   if(L->NElem < MAXART)
       L->Datos[L->NElem++] = *Art;
}

/*************************************************************/

void PintarLista (TipoLista * L)
{
   int k;

   for(k = 0; k < L->NElem; k++)
         printf("%d - %s\n",L->Datos[k].CodArt,
                            L->Datos[k].NomArt);        
}


