
#include <stdio.h>

void expandir (char [], char []);

void main()
{
   char A[500];
   char * cadena = "ABCDEF01234567";

   expandir(cadena,A);
   printf("Salida : %s\n",A);
}

void expandir (char A[], char B[])
{
    int i, j, k;

    for(j = 0, k = 0; A[k]; k++)
        if(A[k] >= '0' && A[k] <= '9')
           for(i = '1'; i <= A[k]; i++)
                B[j++] = A[k];
        else
        {
           B[j++] = '1';
           B[j++] = A[k] - 'A' + '0';
        }
    B[j] = '\0';
}
