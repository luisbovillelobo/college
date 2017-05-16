
#include <stdio.h>
#include <ctype.h>

/* consonantes contiguas
 * en un texto de letras
 * minusculas y blancos
 */

int consonante (int);

void main()
{
    int ant, act, cont;

    ant = cont = 0;

    while((act = getchar()) != EOF)
        if(consonante(act))
        {
            if(ant == act - 1)
                cont++;
            ant = act;
        }
    printf("\nNumero de parejas contiguas = %d\n",cont);
}

int consonante (int c)
{
    int vocal = c == 'a' || c == 'e' ||
                c == 'i' || c == 'o' || c =='u';

    return vocal == 0 && islower(c);
}
