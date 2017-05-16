#include <stdio.h>
  
int f (int, int);

void main()
{
   int a,b;

      do
         scanf("%d %d", &a, &b);
      while(a <= 0 || b <= 0);

      printf("El valor es %d\n",f(a,b));
}

int f (int a, int b)
{
   return a % b ? f(b,a % b) : b;
}
