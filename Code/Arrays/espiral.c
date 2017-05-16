
#include <stdio.h>

#define N 6

void espiral (char [][N]);

void main()
{
    int i, j;
    char car = 0x21;
    char A[N][N];

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
             printf("%3c",A[i][j] = car++);
        printf("\n");
    }
    printf("\n\nRecorrido en espiral de la matriz:\n\n");

	espiral(A);

	printf("\n\n*** FIN\n");
}

void espiral (char A[][N])
{
    int k, i = 0, j = N - 1;

    while(i <= j)
    {
        for(k = i; k <= j; k++) printf("%2c",A[i][k]);
        for(k = i + 1; k <= j; k++) printf("%2c",A[k][j]);
        for(k = j - 1; k >= i; k--) printf("%2c",A[j][k]);
        for(k = j - 1; k > i ; k--) printf("%2c",A[k][i]);

        i++; j--;
    }
}
