
#include <stdio.h>

#define MAXDISK 50
#define MAXCAR  40

/*********** Tipos y prototipos de funcion *******************/

typedef char String40 [MAXCAR + 1]; /* 40 validos + '\0' */

struct TDisco {
          int      ventas;
          String40  album;
          String40  autor;
       };

struct TLista {
          int NElem;
          struct TDisco Datos[MAXDISK];
       };

int  MaxVentas (struct TLista *);
int  LeerUnDisco (FILE *, struct TDisco *);
void InsertaFinal (struct TDisco *, struct TLista *);

/*************************************************************/

void main()
{

   FILE * fp;
   int    index;
   struct TDisco UnDisco;
   struct TLista ListaDiscos;

   if((fp = fopen("discos.txt","r")) == NULL)
   {
      printf("** Error en el fichero discos.txt\n");
      return;
   }

   ListaDiscos.NElem = 0;

   while(LeerUnDisco(fp,&UnDisco))
                InsertaFinal(&UnDisco,&ListaDiscos);
   fclose(fp);

   index = MaxVentas(&ListaDiscos);

   if(index != -1)
       printf("\n Ventas = %d \n Album = %s \n Autor = %s",
                   ListaDiscos.Datos[index].ventas,
                   ListaDiscos.Datos[index].album,
                   ListaDiscos.Datos[index].autor);
}

/*************************************************************/

int LeerUnDisco (FILE * fp, struct TDisco * disco)
{
   // printf("\nStatus = %d\n",feof(fp));
   return fscanf(fp,"%d %s %s",&disco->ventas,
                                disco->album,disco->autor) != EOF;
}

/*************************************************************/

void InsertaFinal (struct TDisco * disco, struct TLista * L)
{
   if(L->NElem == MAXDISK) return;

   L->Datos[L->NElem++] = *disco;
}

/*************************************************************/

int MaxVentas (struct TLista * L)
{
   int Mventas, k, index = 0;

   if(L->NElem == 0) return -1;

   Mventas = L->Datos[index].ventas;

   for(k = 1; k < L->NElem; k++)
        if(L->Datos[k].ventas > Mventas)
        {
           Mventas = L->Datos[k].ventas;
           index = k;
        }
   return index;
}

