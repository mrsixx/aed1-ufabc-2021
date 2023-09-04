#include <stdio.h>

int catalan(int);
int main()
{
    int n;
    do
    {

        scanf("%d", &n);
        if(n >= 0)
            printf("%d\n", catalan(n));
    }while(n >= 0);


    return 0;
}

int catalan(int n)
{
    if(n == 0)
        return 1;

    return ((((4*n) - 2)) / ((float)(n + 1))) * catalan(n-1);
}