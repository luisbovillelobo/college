
/* Codigo de Cesar
 * de longitud N
 */

#include <stdio.h>

void main()
{
    const int N = 5;
    int c;

    while((c = getchar()) != EOF)
        if(c >= 'a' && c <= 'z')
        {
            c += N;
            putchar(c <= 'z' ? c : c - 26);
        }
        else if(c >= 'A' && c <= 'Z')
             {
                 c += N;
                 putchar(c <= 'Z' ? c : c - 26);
             }
             else
                putchar(c);
}
