
#include <stdio.h>



void main()
{
    int status, x;

    while(1)
    {
        status = scanf("%d",&x);
        printf("\n*** status = %d, x = %d\n",status,x);

        if(status == 0)
        {
            printf("\n*** Error de lectura, x = %d\n",x);
            fflush(stdin);
        }
    }
}
