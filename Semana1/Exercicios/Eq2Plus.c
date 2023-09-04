#include <stdio.h>
#include <math.h>



int eq2plus(float a, float b, float c, float* x1, float* x2);

int main()
{
    float a, b, c, x1 = 0, x2 = 0;
    scanf("%f %f %f", &a, &b, &c);
    //calculo o delta
    int raizes = eq2plus(a,b,c,&x1,&x2);

    switch(raizes)
    {
        case 2:
            printf("%.4f %.4f", x1, x2);
            break;
        case 1:
            printf("%.4f", x1);
            break;
        default:
            printf("nao ha raiz real");
            break;
    }

    printf("\n");
    return 0;
}



int eq2plus(float a, float b, float c, float* x1, float* x2)
{

    //se todos os coeficientes forem nulos
    if(pow(a,2) + pow(b,2) + pow(c,2) == 0)
        return 0;

    //calculo do delta
    float delta = pow(b,2) -4 * a * c;//b^2-4ac

    //delta nulo: 1 raiz real
    if(delta == 0)
    {
        *x1 = -b / (2*a);
        return 1;
    }

    //delta positivo: 2 raizes reais
    if(delta > 0)
    {
        *x1 = (-b + pow(delta, 0.5)) / (2*a);
        *x2 = (-b - pow(delta, 0.5)) / (2*a);
        return 2;
    }

    return 0;


}