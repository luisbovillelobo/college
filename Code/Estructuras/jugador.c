
#include <stdio.h>

#define MAXCAR 30
#define MAXJUG 20

/*********** Tipos y prototipos de funcion *******************/

typedef char String30 [MAXCAR + 1];

struct TJugador {
           int       Goles;
           String30  Nombre;
           String30  Equipo;
       };

struct TLista {
           int NElem;
           struct TJugador Datos[MAXJUG];
       };

int  LeerUnJugador (FILE *, struct TJugador *);
void InsertaFinal (struct TJugador *, struct TLista *);
void Eliminar (struct TLista *);
void PintarLista (struct TLista *);

/*************************************************************/

void main()
{
   FILE * fp;
   struct TJugador UnJugador;
   struct TLista ListaJugadores;

   if((fp = fopen("jugador.txt","r")) == NULL)
   {
      printf("** Error en el fichero jugador.txt\n");
      return;
   }

   ListaJugadores.NElem = 0;

   while(LeerUnJugador(fp,&UnJugador))
                InsertaFinal(&UnJugador,&ListaJugadores);
   fclose(fp);

   PintarLista(&ListaJugadores);

   Eliminar(&ListaJugadores); 

   PintarLista(&ListaJugadores);
}

/*************************************************************/

int LeerUnJugador (FILE * fp, struct TJugador * Jugador)
{
   if(fscanf(fp,"%d %s %s",&Jugador->Goles,
                            Jugador->Nombre,Jugador->Equipo) != EOF)
       return 1; /* OK, cargado dato */

   return 0; /* Error o EOF */
}

/*************************************************************/

void InsertaFinal (struct TJugador * Jugador, struct TLista * L)
{
   if(L->NElem == MAXJUG) return;

   L->Datos[L->NElem++] = *Jugador;
}

/*************************************************************/

void Eliminar (struct TLista * L)
{
   int k, MinGoles, index = 0;

   if(L->NElem == 0) return;
     
   MinGoles = L->Datos[index].Goles;
   
   for(k = 1; k < L->NElem; k++)
        if(L->Datos[k].Goles < MinGoles)
        {
           MinGoles = L->Datos[k].Goles;
           index = k;
        }
   for(k = index + 1; k < L->NElem; k++)
         L->Datos[k - 1] = L->Datos[k];
   L->NElem--;       
}

/*************************************************************/

void PintarLista (struct TLista * L)
{
   int k;

   for(k = 0; k < L->NElem; k++)
   {
      printf("Goles  = %d\n",L->Datos[k].Goles);
      printf("Nombre = %s\n",L->Datos[k].Nombre);
      printf("Nombre = %s\n",L->Datos[k].Equipo);
   }
   printf("*****************************\n");
}



