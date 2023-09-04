#include <stdio.h>


struct tRacional
{
    int num, dem;
};

struct tRacional racional(int,int);
struct tRacional negativo(struct tRacional);
struct tRacional soma(struct tRacional,struct tRacional);
struct tRacional sub(struct tRacional, struct tRacional);
struct tRacional mult(struct tRacional,struct tRacional);
struct tRacional div(struct tRacional,struct tRacional);
struct tRacional reduz(struct tRacional);
struct tRacional inverso(struct tRacional);
void print(struct tRacional);

int mdc(int,int);
int abs(int);

int main()
{
    int n1, d1, n2,d2;
    char op;
    struct tRacional res;
    while(scanf("%d %d %c %d %d", &n1, &d1, &op, &n2, &d2) != EOF)
    {
        switch(op)
        {
            case '+':
                res = soma(racional(n1,d1), racional(n2,d2));
                break;
            case '*':
                res = mult(racional(n1,d1), racional(n2,d2));
            break;
            case '-':
                res = sub(racional(n1,d1), racional(n2,d2));
            break;
            case '/':
                res = div(racional(n1,d1), racional(n2,d2));
            break;
        }
        print(res);
    }
    /*struct tRacional x = racional(3,6);
    struct tRacional y = racional(3,6);
    print(x);
    print(y);
    print(sub(x,y));*/
    return 0;
}

struct tRacional racional(int a,int b)
{
    struct tRacional x = {a,b};
    return x;
}

struct tRacional soma(struct tRacional x,struct tRacional y)
{
    int d = x.dem * y.dem;
    int n = (d/ x.dem * x.num) + (d/y.dem*y.num);
    return reduz(racional(n,d));
}

struct tRacional sub(struct tRacional x, struct tRacional y)
{
    return reduz(soma(x, negativo(y)));
}

struct tRacional mult(struct tRacional x,struct tRacional y)
{
    int n = x.num * y.num, d = x.dem * y.dem;
    return reduz(racional(n,d));
}

struct tRacional div(struct tRacional x,struct tRacional y)
{
    return reduz(mult(x,inverso(y)));
}


void print(struct tRacional x)
{
    printf("%d %d\n", x.num, x.dem);
}

struct tRacional inverso(struct tRacional x)
{

    struct tRacional y = {x.dem,x.num};
    return y;
}

struct tRacional negativo(struct tRacional x)
{

    struct tRacional y = {(-1*x.num),x.dem};
    return y;
}

struct tRacional reduz(struct tRacional x)
{
    int n = x.num, d = x.dem;
    int mdComum = mdc(abs(n), abs(d));
    for(int i = mdComum; i > 0; i--)
    {
        if(n % i == 0 && d % i == 0)
        {
            n /= i;
            d /= i;
        }
    }
    struct tRacional reduzido = {n,d};
    return reduzido;
}



int mdc(int a,int b)
{
    if(b == 0)
        return a;

    return mdc(b, a%b);
}

int abs(int x)
{
    if(x < 0)
        return -1*x;

    return x;
}