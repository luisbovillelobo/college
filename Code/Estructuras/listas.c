
#include <stdio.h>

#define MAXELEM 100

/*********** Tipos y prototipos de funcion **********************/

typedef int TElemento;

typedef struct {
           int       NElem;
           TElemento Datos [MAXELEM];
        } TLista;

typedef struct {
           int       NElem;
           TElemento Datos [2 * MAXELEM];
        } TDosLista;

void Inicializar (TLista *);
void CargarLista (FILE * fp, TLista *);
int Insertar (TElemento, TLista *);
int Eliminar (TElemento, TLista *);
void Imprimir (const TLista *);
void Mezclar (const TLista *, const TLista *, TDosLista *);

/****************************************************************/

void Mezclar (const TLista * L1, const TLista * L2, TDosLista * Res)
{
   int i = 0, j = 0;

   Res->NElem = 0;

   while(i < L1->NElem && j < L2->NElem)
     if(L1->Datos[i] < L2->Datos[j])
	    Res->Datos[Res->NElem++] = L1->Datos[i++];
     else if(L1->Datos[i] > L2->Datos[j])
                 Res->Datos[Res->NElem++] = L2->Datos[j++];
          else {
                  Res->Datos[Res->NElem++] = L1->Datos[i++];
                  j++;
               }

   while(i < L1->NElem)
          Res->Datos[Res->NElem++] = L1->Datos[i++];

   while(j < L2->NElem)
          Res->Datos[Res->NElem++] = L2->Datos[j++];
}

/****************************************************************/

void CargarLista (FILE * fp, TLista * L)
{
   TElemento x;

   Inicializar(L);

   while(fscanf(fp,"%d",&x) != EOF)
                Insertar(x,L);
}

/****************************************************************/

void Inicializar (TLista * L)
{
   L->NElem = 0;
}

/****************************************************************/

/*  Inserta x en orden,
    NO se permiten repeticiones
 */

int Insertar (TElemento x, TLista * L)
{
   int j, k = 0;

   if(L->NElem == MAXELEM)
             return -1;         /* Lista llena, volver       */

   while(k < L->NElem)
     if(L->Datos[k] < x)        /* Avanzar, buscar hueco     */
              k++;
     else if(x == L->Datos[k])
               return -2;       /* Elemento repetido, volver */
          else
          {    /* hacer sitio para insertar, desplazar a la derecha */

             for(j = L->NElem - 1; j >= k; j--)
                       L->Datos[j + 1] = L->Datos[j];

             break; /* fin de while */
          }

   L->Datos[k] = x;
   ++L->NElem;

   return k;  /* Elemento insertado correctamente */
}

/****************************************************************/

int Eliminar (TElemento x, TLista * L)
{
   int k;

   if(L->NElem == 0)
             return -1;     /* Lista vacia, elemento no encontrado */

   for(k = 0; k < L->NElem; k++)
      if(L->Datos[k] > x)   /* No puede estar en la lista */
               break;
      else if(L->Datos[k] == x)
      {
         for(k++; k < L->NElem; k++)
               L->Datos[k - 1] = L->Datos[k];
         L->NElem--;

         return k;  /* Encontrado y borrado, posicion antigua */
      }

   return -1; /* Elemento no econtrado */
}

/****************************************************************/

void Imprimir (const TLista * L)
{
   int k;

   for(k = 0; k < L->NElem; printf("%d ",L->Datos[k++]));
   printf("\n");
}

/****************************************************************/

void main()
{
   FILE * fp;
   TLista  L1, L2;
   TDosLista R;

   if((fp = fopen("numeros.txt","r")) == NULL)
          return;

   CargarLista(fp,&L1);

   fclose(fp);

   if((fp = fopen("numeros2.txt","r")) == NULL)
          return;

   CargarLista(fp,&L2);

   fclose(fp);

   Imprimir(&L1);
   Imprimir(&L2);

   Eliminar(12, &L1);
   Imprimir(&L1);

   Insertar(-3, &L1);
   Imprimir(&L1);

   Mezclar(&L1,&L2,&R);
   Imprimir((TLista *) &R);

   if((fp = fopen("numeros.txt","r")) == NULL)
          return;

   CargarLista(fp,(TLista *) &R);

   fclose(fp);

   Imprimir((TLista *) &R);

}