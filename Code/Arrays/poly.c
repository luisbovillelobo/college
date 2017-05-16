
#include <stdio.h>
#include <math.h>

#define N 20

/*********** Tipos y prototipos de funcion ***********************/

typedef int POL[N + 1];

void leerpol (POL);
void escpol (POL);
void sumapol (POL, POL, POL);
void multmon (int, int, POL);
void multpol (POL, POL, POL);

/*****************************************************************/

void leerpol (POL p)
{
   int ex;
  
   for(ex = 0; ex <= N; p[ex++] = 0);

   for(;;)
   {
      printf("Exponente = ");
      scanf("%d", &ex);

      if(ex >= 0) 
      {
         printf("Coeficiente = ");
         scanf("%d",&p[ex]);
      }
      else return;
   }
   
}

/*****************************************************************/

void escpol (POL p)
{
   int i;

   if(p[0]) printf("%d",p[0]);
   
   for(i = 1; i <= N; i++)
     if(p[i])
     {
	 printf("%c",p[i] > 0 ? '+' : '-');
	 if(abs(p[i]) != 1) printf("%d",abs(p[i]));
	 if(i == 1)
              printf("x");
         else
              printf("x^%d",i);
     } 
   printf("\n");
}

/*****************************************************************/

void sumapol (POL p, POL q, POL r)
{
   int ex;

   for (ex = 0; ex <= N; ex++)
            r[ex] = p[ex] + q[ex];
}

/*****************************************************************/

void multmon (int co, int ex, POL p)
{
   int i, j;
   
   for(i = 0; i <= N && p[i] == 0; i++);
   for(j = N; j >= 0 && p[j] == 0; j--);

   while(j >= i)
   {
     p[j + ex] = co * p[j];
     j--;
   }
   for(j = i; j <= i + ex - 1; p[j++] = 0);
}

/*****************************************************************/

void multpol (POL p, POL q, POL r)
{
   POL s;
   int i, j;
	   
   for(i = 0; i <= N; r[i++] = 0);
	
   for(i = 0; i <= N; i++)
     if(p[i])
     {
        for(j = 0; j <= N; j++) s[j] = q[j];
        multmon(p[i],i,s);
	sumapol(r,s,r);
     }
}

/*****************************************************************/

void main()
{
   POL p, q, r;

   leerpol(p);
   printf("p(x) = ");
   escpol(p);

   leerpol(q);
   printf("q(x) = ");
   escpol(q);

   multpol(p,q,r);
   printf("p(x) * q(x) = ");
   escpol(r);
}

