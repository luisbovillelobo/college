#include <stdio.h>

#define N 5

int LRL (int [][N]);

void main()
{
    int A[N][N] = {{1,2,2,2,2},{4,1,1,1,1},{6,3,4,4,4},{2,5,6,6,6},{7,2,3,6,7}};

    printf("\nEs LRL = %d \n",LRL(A));
}

int LRL (int S[N][N])
{
    int c,k;

    for(c = 0; c < N - 1; c++)        /* Nº columna c = 0,1,2,...,N – 2     */
        for(k = 0; k < N; k++)        /* indice k,  0 <= k <= N – 1         */
        {
            if(S[k][c] > S[k][c + 1]) /* Fallo, la matriz no puede ser LRL  */
                return 0;
            if(S[k][c] < S[k][c + 1]) /* La columna c es menor que la c + 1 */
                break;                /* k encontrado, probar siguiente par */
            if(k == N - 1)
                return 0;
        }
    return 1;
}

