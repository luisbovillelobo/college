#include <stdio.h>

struct ejemplo
{
    int   x;
    int   y;
    int * z;
};

struct ejemplo fun (int i, int j)
{
    struct ejemplo e1;
    int k;

    /* asignar algunos valores */
    e1.x = i;
    e1.y = j;
    k = i * j;
    e1.z = &k; // k se destruira al final de la funcion

    printf("\nfun: direccion de e1 es 0x%X\n", &e1);
    printf("e1.x = %d\n", e1.x);
    printf("e1.y = %d\n", e1.y);
    printf("e1.z = 0x%X\n", e1.z);
    printf("*e1.z = %d\n", *e1.z);

    return e1; // retorna una copia de e1, no la variable local e1
}

void main()
{
    struct ejemplo e2;

    e2 = fun(5,7);

    printf("\nmain: direccion de e2 es 0x%X\n", &e2); // diferentes direcciones de memoria
    printf("e2.x = %d\n", e2.x); // el mismo valor
    printf("e2.y = %d\n", e2.y); // el mismo valor
    printf("e2.z = 0x%X\n", e2.z); // el mismo valor
    printf("*e2.z = %d\n", *e2.z); // k se destruyo, por tanto la memoria se reutiliza
}
