
#include <stdio.h>

void main(void)
{
   int a,b;

   do
       scanf("%d %d",&a,&b);
   
   while(a <= 0 || b <= 0);

   printf("El mcd de %d y %d es: ",a,b);

   while(a != b)
   {
     while(a > b) a -= b;
     while(b > a) b -= a;
   }
    
   printf("%d",a);
}

