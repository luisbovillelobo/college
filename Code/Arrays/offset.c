#include <stdio.h>

void main()
{
    int a = 0xAABBCCDD;
    char  b = 0xEE;      /* probar unsigned char */
    int c = 0x11223344;
    int  * p = NULL;

    p = (int  *) &b;
    printf(" &a = 0x%p - a = 0x%X\n",&a,a);
    printf(" &b = 0x%p - b = 0x%X\n",&b,b);
    printf(" &c = 0x%p - c = 0x%X\n",&c,c);
    printf("\n p = 0x%p - *p = 0x%X\n",p,*p);
}
