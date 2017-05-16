
#include <stdio.h>

/*********** Tipos y prototipos de funcion ***********************/

int escondida (char [], char [], int *, int *);

/*****************************************************************/

int main()
{
  char * palabra = "melocoton";
  char * texto = "cxcvcxmmmvsdfedllhjoco tjtrj3bbboxbbbbbbonb";
  char * cuent = "12345678901234567890123456789012345678901234567890";
  int primera,ultima;

  if(escondida(palabra,texto,&primera,&ultima))
  {
      printf("\nPrimera posicion = %d", primera);
      printf("\nUltima  posicion = %d", ultima);
  }
  else printf("\nLa palabra no esta escondida\n");
}

int escondida (char pal[], char txt[], int * prim, int * ult)
{
    int i = 0, k;                                 /* pal y txt tienen al menos un caracter */

    for(k = 0; txt[k] && pal[i] != txt[k]; k++);  /* Localizar el primer caracter de pal   */

    if(txt[k] == 0) return 0;   /* Mala suerte, el primer caracter no estaba en el texto   */

    *prim = *ult = k + 1;       /* Actualizar las posiciones pedidas */

    for(i++; pal[i]; i++)       /* Seguir buscando los siguientes caracteres en el texto   */
    {
        for(k = *ult; txt[k] && pal[i] != txt[k]; k++);

        if(txt[k] == 0) break; /* Otra vez mala suerte, falta algun caracter de la palabra */

        *ult = k + 1;
    }

    return pal[i] == 0;     /* Solo se puede retornar 1 si se ha procesado toda la palabra */
}
