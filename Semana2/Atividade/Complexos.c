#include <stdio.h>

typedef struct tComplex{
    int r,i;
} Complexo;

Complexo complexo(int, int);
Complexo soma(Complexo, Complexo);
Complexo sub(Complexo, Complexo);
Complexo mult(Complexo, Complexo);
Complexo div(Complexo, Complexo);
void print(Complexo);
Complexo conjugado(Complexo);
int abs(int);
int main()
{
    int a,b,c,d;
    char op, i;

    while(scanf("%d %d %c %c %d %d %c", &a,&b,&i, &op, &c,&d,&i) != EOF)
    {
        Complexo c1 = complexo(a,b), c2 = complexo(c,d);

        switch(op)
        {
            case '+':
                print(soma(c1,c2));
                break;
            case '-':
                print(sub(c1,c2));
                break;
            case '*':
                print(mult(c1,c2));
                break;
            case '/':
                print(div(c1,c2));
                break;
        }

        //printf("%d %d%c %c %d %d%c\n", a,b,i, op, c,d,i);

    }
}


Complexo soma(Complexo c1, Complexo c2)
{
    int r = c1.r + c2.r;
    int i = c1.i + c2.i;

    return complexo(r,i);
}

Complexo sub(Complexo c1, Complexo c2)
{
    int r = c1.r - c2.r;
    int i = c1.i - c2.i;

    Complexo complex = {r,i};

    return complexo(r,i);
}

Complexo mult(Complexo c1, Complexo c2)
{
    int a,b,c,d;
    a = c1.r;
    b = c1.i;
    c = c2.r;
    d = c2.i;

    return complexo(a*c-b*d,a*d+b*c);
}

Complexo div(Complexo c1, Complexo c2)
{
    Complexo conjug = conjugado(c2);
    Complexo numerador = mult(c1,conjug);
    Complexo denominador = mult(c2,conjug);

    int r = numerador.r / denominador.r;
    int i = numerador.i / denominador.r;

    return complexo(r,i);
}

Complexo conjugado(Complexo c)
{
    return complexo(c.r, (-1)*c.i);
}



Complexo complexo(int r, int i)
{
    Complexo complex = {r,i};
    return complex;
}

void print(Complexo c)
{
    char op = (c.i < 0) ? '-': '+';
    printf("%d %c%di\n", c.r, op, abs(c.i));
}

int abs(int x)
{
    if(x < 0)
        return -1 * x;

    return x;
}