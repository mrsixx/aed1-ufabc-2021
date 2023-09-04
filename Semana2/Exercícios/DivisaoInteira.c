#include <stdio.h>

int divisaoInteira(long int, long int);

int main()
{
    long int a,b;
    scanf("%ld %ld", &a, &b);
    printf("%d\n", divisaoInteira(a,b));
    return 0;
}


int divisaoInteira(long int a, long int b)
{
    if(a < b)
        return 0;
    return divisaoInteira(a-b, b) + 1;
}