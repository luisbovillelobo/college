#include<stdio.h>
#include<math.h>

float calcularDistancia (float, float, float, float);

void main()
{
    float x1,y1,x2,y2;

    printf("Introduzca las coordenadas del primer punto: ");
    scanf("%f%f",&x1,&y1);
    printf("Introduzca las coordenadas del segundo punto: ");
    scanf("%f%f",&x2,&y2);
    printf("\nLa distancia es: %.2f",calcularDistancia(x1,y1,x2,y2));
}

float calcularDistancia(float x1, float y1, float x2, float y2)
{
    return sqrt(pow((x2-x1),2) + pow((y2-y1),2));
}
