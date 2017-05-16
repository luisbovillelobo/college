#include <stdio.h>
#include <stdlib.h>

#define N 5

int homogenea (int [][N], int);

void main()
{
    int A[N][N] = {2,2,-4,1,0,0,-7,1,2,5,1,-1,2,
                   0,0,-2,0,-1,1,1,1,-6,-2,-1,-2};

    if(homogenea(A,4))
         printf("\nYes, it is\n");
    else printf("\nFault, try it again\n");
}

int homogenea (int A[N][N], int p)
{
    int j,k,top,ant,act;

    top = A[0][0];
    ant = abs(top);

    for(k = 1; k < N; k++)
    {
        top += A[0][k] + A[k][0];
        act = 0;

        for(j = 1; j < k; j++)
              act += A[k][j] + A[j][k];

        act = abs(top + act + A[k][k]);

        if(abs(ant - act) > p) return 0;

        ant = act;
    }

    return 1;
}
