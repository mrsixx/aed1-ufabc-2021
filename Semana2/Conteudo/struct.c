#include <stdio.h>

typedef struct tPonto{
    int x, y;
} Ponto;

void printPonto(Ponto pt);
int main()
{
    Ponto a, b;
    a.x = 0;
    a.y = 0;

    b.x = 10;
    b.y = 5;

    printPonto(a);
    printPonto(b);
    return 0;
}


void printPonto(Ponto pt)
{
    printf("(%d, %d)", pt.x, pt.y);
}
