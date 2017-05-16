#include <stdio.h>

union Uclase {
         char    * svalor;
         long int  ivalor;
      };

void main ()
{
   union Uclase clase;

   printf("%d\n",sizeof(union Uclase));

   clase.svalor = "123";

   printf("%s\n",clase.svalor);
   printf("%ld\n",clase.ivalor);
   printf("%ld\n",clase.svalor);
   printf("%p\n",clase.svalor);
   printf("%lx\n",clase.ivalor);
   printf("%p\n",clase.ivalor);
   printf("%02x%02x%02x%02x\n",*clase.svalor,*(clase.svalor + 1),
                               *(clase.svalor + 2),*(clase.svalor + 3));
}

