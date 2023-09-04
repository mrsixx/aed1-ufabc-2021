#include <stdio.h>


long int fibonacci(int);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%ld\n", fibonacci(n));
    return 0;
}

long int fibonacci(int n)
{
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;


    return fibonacci(n -2) + fibonacci(n -1);
}