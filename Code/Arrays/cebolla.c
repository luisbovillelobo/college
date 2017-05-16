
#include <stdio.h>

#define N 6

int cebolla (int [][N]);

void main()
{
    int i, j;
    int A[N][N] = {1,1,1,1,1,1,1,4,4,4,4,1,
                   1,4,8,8,4,1,1,4,8,8,4,1,
                   1,4,4,4,4,1,1,1,1,1,1,1};

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
             printf("%3d",A[i][j]);
        printf("\n");
    }
	printf("\nCebolla = %d\n",cebolla(A));
}

int cebolla (int A[][N])
{
    int k, valor;
    int i = 0, j = N - 1;

    while(i < N/2)
    {
        valor = A[i][i];

        for(k = i + 1; k <= j; k++)
            if(A[i][k] != valor || A[k][i] != valor ||
               A[j][k] != valor || A[k][j] != valor)
                    return 0;
        i++; j--;
    }
    return 1;
}
