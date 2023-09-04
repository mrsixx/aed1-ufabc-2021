#include <stdio.h>
#include <stdlib.h>
#define MAX 15
int main()
{
    int n,k;
    scanf("%d",&k);
    char *buf = (char*)malloc(sizeof(char)*k+1);
    for(int i = 0; i < k+1; i++)
        scanf("%c",&buf[i]);

    for(int i = 0; i < k+1; i++)
        printf("[%c]\n",buf[i]);

    free(buf);
    return 0;
}