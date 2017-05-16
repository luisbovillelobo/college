
#include <stdio.h>
#include <math.h>

/******** Tipos y prototipos de funcion *****************************/

typedef double (* FUNCION) (double); /* puntero a funcion */

void Bolzano (FUNCION, double, double, double *, double *);

/********************************************************************/

void main()
{
   FUNCION F;
   double inf,sup;

   /*  F cualquier funcion con prototipo
       double F (double), por ejemplo sin
    */

   F = sin;

   /*  Sabemos que sin(x) tiene un cero
       en el intervalo [2,4]
    */

   Bolzano(F,2,4,&inf,&sup);

   /*  [inf,sup] es el intervalo con la raiz
       buscada, el error permitido es menor que EPS.
       Comprobar que se aproxima a PI
    */

   printf("Extremo inferior = %20.18lf\n",inf);
   printf("Extremo superior = %20.18lf\n",sup);
}

/********************************************************************/

void Bolzano (FUNCION F, double a, double b,
                         double * c, double * d)
{
   const double EPS = 0.000000000001;   /* error permitido */
   double valor, puntomedio;

   while(fabs(a - b) >= EPS)
   {
      puntomedio = (a + b)/2;

      valor = F(puntomedio);

      if(valor == 0)  /* ¡ Es una raiz ! */
      {
         *c = *d = puntomedio;
         return;              /* Mision cumplida, retornar */
      }

      if(valor * F(a) > 0)  /* F(a) y valor tienen el mismo signo */
           a = puntomedio;
      else b = puntomedio; /* ... y si no, lo tienen valor y F(b) */
   }

   /*
       Devolver el intervalo [c,d] que contiene
       la raiz buscada con tolerancia < EPS
    */

   *c = a;
   *d = b;
}
