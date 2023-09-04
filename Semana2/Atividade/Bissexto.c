#include <stdio.h>

int eh_bissexto(int);
int main()
{
    int ano;
    scanf("%d", &ano);
    if(eh_bissexto(ano))
        printf("ANO BISSEXTO");
    else
        printf("ANO NAO BISSEXTO");

    printf("\n");
    return 0;
}


int eh_bissexto(int ano)
{
    if(ano % 400 == 0)
        return 1;

    if(ano % 4 == 0 && ano % 100 != 0)
        return 1;

    return 0;
}