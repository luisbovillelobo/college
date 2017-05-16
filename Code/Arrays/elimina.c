
#include <stdio.h>

void Elimina (char [], FILE *);

void main()
{
   FILE * fp = fopen("datos.txt","r");
   char * str = "mrhza";

   Elimina(str,fp);

   fclose(fp);
}

void Elimina (char str[], FILE * fp)
{
    int  k;
    char car;

    while(fscanf(fp,"%c",&car) != EOF)
    {
        for(k = 0; str[k]; k++)
            if(str[k] == car)
                break;
        if(str[k] == '\0')
            printf("%c",car);
    }
}
