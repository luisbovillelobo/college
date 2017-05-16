#include <stdio.h>
#include <math.h>

/****************************************************/

struct Punto {
         double coX, coY;
       };

struct Punto Inic (double, double);

struct Punto Inic (double x, double y)
{
    struct Punto p;

    p.coX = cos(x);
    p.coY = sin(y);

    return p;
}

void main()
{
    double x, y;
    struct Punto S;

    scanf("%lf %lf",&x,&y);
    S = Inic(x,y);
    printf("\ncoX = %lf, coY = %lf\n",S.coX,S.coY);

}
