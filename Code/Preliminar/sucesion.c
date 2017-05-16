
#include <stdio.h>

void main()
{

    int num1, num2, pos = 1;

    scanf("%d", &num1);
    if(num1 == 0)
    {
        printf("\nSecuencia vacia");
        return;
    }
    while(scanf("%d", &num2) && num2 != 0)
    {
        pos++;
        if(num1 >= num2)
        {
            printf("\nSecuencia no ordenada, valor = %d, pos = %d", num2,pos);
            return;
        }
        num1 = num2;
    }
    printf("\nSecuencia Ordenada");
}
