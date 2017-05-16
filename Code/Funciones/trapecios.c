
#include <stdio.h>
#include <math.h>

typedef double (* Funcion) (double);

double trapecios (Funcion, double, double, int);
double cos2x (double);

double trapecios (Funcion f, double a, double b, int N)
{
    int k;
    double h = (b - a) / N;
    double s = (f(a) + f(b)) / 2;

    for(k = 1; k < N; k++) s += f(a + k * h);
    return h * s;
}
double cos2x (double x)
{
    return cos(2 * x);
}
void main()
{
    printf("\nLa integral de cos(x) es = %lf",trapecios(cos,0,1,120));
    printf("\nLa integral de cos(2x) es = %lf",trapecios(cos2x,0,1,120));
    printf("\nLa integral de exp(x) es = %lf",trapecios(exp,0,1,120));
}
