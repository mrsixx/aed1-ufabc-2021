#include <stdio.h>
#include <stdlib.h>

int *alocar_vetor(int n);
int buscar_no_vetor(int*, int, int);
int main()
{
    int n, m, x;
    scanf("%d", &n);
    int *vetor = alocar_vetor(n);
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        if(buscar_no_vetor(vetor, x, n))
            printf("ACHEI");
        else
            printf("NAO ACHEI");

        printf("\n");
    }


    free(vetor);
    return 0;
}

int buscar_no_vetor(int *vetor, int valor, int fim)
{
    if(fim < 0)
        return 0;

    if(vetor[fim] == valor)
        return 1;

    return buscar_no_vetor(vetor, valor, fim-1);
}


int *alocar_vetor(int n)
{
    int *vetor = (int*)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    return vetor;
}