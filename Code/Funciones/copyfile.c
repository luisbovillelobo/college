
#include <stdio.h>

int main ()       /* copia de ficheros */
{
    char car;
    FILE * fent, * fsal;

    if((fent = fopen("entrada.txt","r")) == NULL)
    {
        puts("Error fichero entrada");
        return -1;
    }
    if((fsal = fopen("salida.txt","w")) == NULL)
    {
        puts("Error fichero salida");
        return -1;
    }

    while(fscanf(fent,"%c",&car) != EOF)
        fprintf(fsal,"%c",car);

    fclose(fent);
    fclose(fsal);
    return 0;
}
