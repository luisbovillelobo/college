#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int lanzarDado();
void visualizarDado (int);

void main()
{
    int k;

    srand(time(NULL));
    printf("\nLanzando dado...\n");
    k = lanzarDado();
    printf("\nHa salido un %d\n\n",k);
    visualizarDado(k);
}

int lanzarDado()
{
    return rand() % 6 + 1;
}

void visualizarDado (int n)
{
    switch(n)
    {
        case 1:
            printf("   \n * \n   \n");
            break;
        case 2:
            printf("*   \n   \n   *\n");
            break;
        case 3:
            printf("*   \n  * \n    *\n");
            break;
        case 4:
            printf("*   *\n   \n*   *\n");
            break;
        case 5:
            printf("*   *\n  *  \n*   *\n");
            break;
        case 6:
            printf("*   *\n*   *\n*   *\n");
            break;
        default:
            break;
    }
}

