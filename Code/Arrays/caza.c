#include <stdio.h>
#include <time.h>

#define N  6
#define M 10

/*************** Prototipos de funcion ***************/

int caza (int [], int [], int, int *);
void cargar (int [], int []);

/*****************************************************/

void main()
{
    int A[N],B[N];
    int k,intentos;

    srand(time(NULL));

    cargar(A,B);

    printf("\n Array A =");
    for(k = 0; k < N; printf("%4d",A[k++]));
    printf("\n Array B =");
    for(k = 0; k < N; printf("%4d",B[k++]));

    k = rand() % N;
    printf("\n\n *** Posicion inicial del conejo = %d.",k);
    printf("\n *** Numero de intentos permitidos = %d.\n",M);

    k = caza(A,B,k,&intentos);

    if(k != -1)
      printf("\n *** Conejo atrapado en casilla = %d, intentos = %d.\n\n",k,intentos);
    else
      printf("\n *** El conejo escapo.\n\n");
}

/*****************************************************/

int caza (int A[], int B[], int k, int * nint)
{
    *nint = 0;

    while(*nint < M) /* intentos de caza, maximo M */
    {
        ++*nint;

        // printf("\n Posicion conejo = %2d, B[%d] = %d\n",k,k,B[k]);
        // printf(" Intento numero  = %2d, A[%d] = %d\n",*nint,k,A[k]);

        if(k == B[k])   /* el zorro atrapo al conejo, retornar */
              return k;

        k += A[k];      /* brinco del conejo */

        if(k < 0)       /* corregir posicion por la circularidad */
              k += N;
        else if(k >= N)
                   k -= N;
    }
    return -1;  /* M intentos acumulados, el conejo escapa */
}

/*****************************************************/

void cargar (int A[], int B[])
{
    int i,num;

    for(i = 0; i < N; i++)
    {
        B[i] = rand() % N;

        while((num = rand() % N) == 0);

        A[i] = rand() % 2 ? num : -num;
    }
}
