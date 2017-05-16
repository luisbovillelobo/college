#include <stdio.h>

int codigo (int);

void main()
{
   int nrp;

   while(scanf("%d",&nrp) != EOF)
       if(nrp % 100 != codigo(nrp/100))
           printf("\nCodigo erroneo: %d\n",nrp);
}

int codigo (int numemp)
{
   return numemp % 7 * 11 + 2;
}

