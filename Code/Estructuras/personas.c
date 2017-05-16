
#include <stdio.h>

#define MAXCAR 30
#define MAXNOM 15

/*********** Tipos y prototipos de funcion *******************/

struct Persona {
            int  Edad;
            int  Peso;
            char Nombre[MAXCAR + 1];
       };

struct Lista {
          int NElem;
          struct Persona Datos[MAXNOM];
       };

int   LeerPersona (FILE *, struct Persona *);
int   Inicio (struct Persona *, struct Lista *);
float MediaPeso (struct Lista *);

/*************************************************************/

void main()
{
   FILE * fp;
   struct Persona Per;
   struct Lista Valores;

   if((fp = fopen("persona.txt","r")) == NULL)
   {
      printf("** Error en el fichero persona.txt\n");
      return;
   }

   Valores.NElem = 0;

   while(LeerPersona(fp,&Per))
       if(Inicio(&Per,&Valores))
            break;

   fclose(fp);

   printf("\nPeso Medio = %f\n",MediaPeso(&Valores));
}

/*************************************************************/

int LeerPersona (FILE * fp, struct Persona * Per)
{
   if(fscanf(fp,"%d %d %s",&Per->Edad,
                           &Per->Peso,Per->Nombre) != EOF)
            return 1;

   return 0; /* Error o EOF */
}

/*************************************************************/

int Inicio (struct Persona * Per, struct Lista * L)
{
   int k;

   if(L->NElem == MAXNOM) return 1;

   if(L->NElem == 0)
        L->Datos[L->NElem++] = *Per;
   else
        if(Per->Edad < L->Datos[0].Edad &&
                  Per->Peso < L->Datos[0].Peso)
        {
            for(k = L->NElem; k; k--)
                 L->Datos[k] = L->Datos[k - 1];

            L->Datos[0] = *Per;
            L->NElem++;
        }
   return 0;
}

/*************************************************************/

float MediaPeso (struct Lista * L)
{
   int   k, cont = 0;
   float pesomed = 0;

   for(k = 0; k < L->NElem; k++)
      if(L->Datos[k].Edad <= 25)
      {
         cont++;
         pesomed += L->Datos[k].Peso;
         printf("Nombre = %s\n",L->Datos[k].Nombre);
         printf("Edad   = %d\n",L->Datos[k].Edad);

      }
   return cont ? pesomed/cont : 0;
}

/*************************************************************/



