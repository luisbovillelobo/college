
#include <stdio.h>

/******** Tipos y prototipos de funcion ********/

typedef int (* FUNCION) (int);

int doble (int);
int triple (int);
void funp (FUNCION, int);

/***********************************************/

void main()
{
   FUNCION F;
   int x = 6;

   F = doble;

   funp(F,x);

   funp(triple,x + 1);

   F = triple;
   printf("%d\n",F(9));

   F = doble;
   printf("%d\n",F(F(x)));
}

/***********************************************/

void funp (FUNCION g, int x)
{
   printf("%d\n",g(x));
}

/***********************************************/

int doble (int x)
{
  return 2 * x;
}

/***********************************************/

int triple (int x)
{
  return 3 * x;
}
