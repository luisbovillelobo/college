
#include <stdio.h>

#define N 8

void write (int [N][N]);
void mcdt (int [N][N]);

void main()
{
    int A[N][N];
    int i, j, p = 1;

    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            A[i][j] = p++;
    write(A);
    mcdt(A);
    printf("\n*****************\n");
    write(A);

}

void mcdt (int A[N][N])
{
    int i, j, temp;

    for(i = 0; i < N/2; i++)
    {
        for(j = 0; j < N/2; j++)
        {
            temp = A[i][j];
            A[i][j] = A[j + N/2][i + N/2];
            A[j + N/2][i + N/2] = temp;
        }
        for(j = N/2; j < N; j++)
        {
            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
}

void write (int A[N][N])
{
    int i, j;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
            printf("%3d ", A[i][j]);
        printf("\n");
    }
}
