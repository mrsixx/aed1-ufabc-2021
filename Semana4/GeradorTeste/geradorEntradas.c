#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(int argc, char** argv)
{
    int t = atoi(argv[1]);
    srand(time(NULL));
    for(int k = 0; k < t; k++)
    {
        int n = (rand() % 9999) + 2;//max 10000, min 2
        printf("%d\n", n);

        for(int i = 0; i < n; i++)
        {
            printf("%d%s",rand()%INT_MAX, (i < n-1 ? " " : (k<t-1?"\n":"")));
        }
    }
    return 0;
}