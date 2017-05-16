
#include <stdio.h>

/******** Prototipos de funcion ************************************/

int creciente (int *);

/*******************************************************************/

/*
    Devuelve 1 si la secuencia de enteros
    de la entrada estandar es ESTRICTAMENTE
    creciente; devuelve 0 en otro caso junto
    con el entero que provoco el fallo (donde
    la secuencia dejo de ser creciente).
    Si la entrada es vacia, retorna -1.
 */

int creciente (int * fallo)
{
   int dato;

   if(scanf("%d",&dato) == EOF)
   {
      puts("\nSecuencia de entrada vacia");
      return -1;
   }

   while(scanf("%d",fallo) != EOF) /* fallo es un puntero, no poner & */        
     if(dato < *fallo)
            dato = *fallo;
     else
            return 0; /* dato >= *fallo */

   return 1; /* OK, secuencia estrictamente creciente */
}

/*******************************************************************/

void main()
{
   int resultado, donde;

   resultado = creciente(&donde); /* es la direccion, usar & */

   if(resultado == -1) return; /* secuencia vacia, abandonar */
 
   if(resultado)
         
       puts("\nLa secuencia es estrictamente creciente");
   
   else
   {
      puts("\nLa secuencia NO es estrictamente creciente");
      printf("y se rompe en el numero = %d.",donde);
   }
}
          