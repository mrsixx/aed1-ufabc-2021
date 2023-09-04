#include <stdio.h>

long int potencia(int, int);

int main()
{
    int a, n;
    scanf("%d %d", &a, &n);
    printf("%ld\n", potencia(a,n));
    return 0;
}


long int potencia(int a, int n)
{
    if(n == 0)
        return 1;

    return a * potencia(a, n-1);
}