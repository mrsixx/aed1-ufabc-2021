#include <stdio.h>


void div_resto(int dividendo, int divisor, int* quociente, int* resto);
int main()
{
    int a, b, c, d;

    scanf("%d %d", &a, &b);

    div_resto(a,b,&c, &d);


    printf("%d %d\n", c, d);
    return 0;
}


void div_resto(int dividendo, int divisor, int* quociente, int* resto)
{
    *quociente = dividendo / divisor;
    *resto = dividendo % divisor;
}