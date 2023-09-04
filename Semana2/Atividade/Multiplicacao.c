#include <stdio.h>

long multiplicacao(int,int);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%ld\n", multiplicacao(a,b));
    return 0;
}

long multiplicacao(int a,int b)
{
    if(b == 0)
        return 0;

    return a + multiplicacao(a, b-1);
}