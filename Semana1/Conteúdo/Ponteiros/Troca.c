#include <stdio.h>

void troca(long int *a, long int *b);

int main()
{
    long a, b;
    scanf("%ld %ld", &a, &b);

    troca(&a, &b);

    printf("%ld %ld\n", a, b);
    return 0;
}

void troca(long int *a, long int *b)
{
    long int tmp = *a;
    *a = *b;
    *b = tmp;
}