#include <stdio.h>

long subtracao(int,int);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%ld\n", subtracao(a,b));
    return 0;
}

long subtracao(int a,int b)
{
    if(b == 0)
        return a;
    return -1 + subtracao(a, b-1);
}
