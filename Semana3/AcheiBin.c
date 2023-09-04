#include <stdio.h>
#include <stdlib.h>

int *alocar_vetor(int n);
int buscar_no_vetor(int*, int, int, int);
int main()
{
    int n, m, x;
    scanf("%d", &n);
    int *vetor = alocar_vetor(n);
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d",&x);
        if(buscar_no_vetor(vetor, x, 0, n))
            printf("ACHEI");
        else
            printf("NAO ACHEI");

        printf("\n");
    }


    free(vetor);
    return 0;
}

int buscar_no_vetor(int *vetor, int valor, int inicio, int fim)
{
    int meio = (fim - inicio) / 2;

    if(vetor[meio] == valor)
        return 1;


    if(inicio > fim)
        return 0;


    if(vetor[meio] < valor)
        return buscar_no_vetor(vetor, valor, inicio, meio-1);

    return buscar_no_vetor(vetor, valor, meio + 1, fim);

}


int *alocar_vetor(int n)
{
    int *vetor = (int*)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++)
        scanf("%d", &vetor[i]);

    return vetor;
}