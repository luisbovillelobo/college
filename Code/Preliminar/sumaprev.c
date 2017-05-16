
#include <stdio.h>

/*  Busca (si existe) el primer numero de la
    entrada estandar que es suma de todos
    los numeros anteriormente leidos. Si lo
    encuentra lo imprime puesto que es la
    solucion buscada, pero hay un error. ¿Cual?
 */

void main()
{
   int  num,  suma = 0;
   char encontrado = 0;

   while(scanf("%d", &num) != EOF && ! encontrado)
     if(suma == num)
              encontrado = 1;
     else suma += num;

   if(encontrado)
        printf("\nHay solucion = %d.\n",num);
   else printf("\nNo hay solucion.\n");
}
