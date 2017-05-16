
#include <stdio.h>

void main()
{
   unsigned char a[] = "12345678";
   unsigned int * p;

   p = a;
   printf("%X\n",*(p + 1));
   printf("%s\n",(char *) p + 1);
   printf("%s", p + 1);

}
