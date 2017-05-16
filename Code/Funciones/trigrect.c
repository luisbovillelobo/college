
#include <stdio.h>

void pintartrig (int);

void main()
{
   int base;

   do
      scanf("%d",&base);
   while(base < 1);

   pintartrig(base);
}

void pintartrig (int b)
{
   int i,k;

   for(i = 1; i <= b; i++)
   {
      for(k = 1; k <= i; k++) printf("* ");
      printf("\n");
   }
}
