
#include <stdio.h>
#include <ctype.h>

void generar (char [], char []);

void main()
{
    char A[500];
    char * cadena = "1633102";

    generar(cadena,A);
    printf("Salida : %s\n",A);
}

void generar (char A[], char B[])
{
    int i, j, k, p;

    for(j = 0, k = 0; A[k]; k++)
        if(A[k] >= '1' && A[k] <= '3')
            for(p = '1'; p <= A[k]; p++)
            {
                i = k + p - '0';
                if(A[i] == '\0')
                    break;
                B[j++] = A[i];
            }
        else
            B[j++] = islower(A[k]) ?
                        toupper(A[k]) : tolower(A[k]);
    B[j] = '\0';
}
