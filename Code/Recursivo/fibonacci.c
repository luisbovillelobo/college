#include <stdio.h>

long int fib (int n)
{
   if(n > 1)
        return fib(n - 1) + fib(n - 2);
   else return 1;
}

void main()
{
   int i, n;

   scanf("%d", &n);

   for(i = 0; i <= n; i++)
      printf("fib(%d) = %ld\n", i, fib(i));
}
