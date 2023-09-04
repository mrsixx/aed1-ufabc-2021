#include <stdio.h>

long soma(int,int);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%ld\n", soma(a,b));
    return 0;
}

long soma(int a,int b)
{
    if(b == 0)
        return a;
    return 1 + soma(a, b-1);
}
