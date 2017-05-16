#include <stdio.h>

int srt (int);

void main()
{
    int i;

    for(i = 1; i <= 99999999; i++)
    {
        if(srt(i) == 1) printf("%d ",i);
    }
}

int srt (int k)
{
    int temp = k;
    int cifras = 0;

    if(temp <= 0)
         return -1;

    while(temp)
    {
        temp /= 10;
        cifras++;
    }

    if(cifras % 2)
         return -2;

    cifras /= 2;

    for(temp = 1; cifras; cifras--)
           temp *= 10;

    temp = k / temp + k % temp;

    return temp * temp == k;
}
