#include <stdio.h>
#include <stdlib.h>

int esta_ordenado_crescente(int*, int);
int esta_ordenado_decrescente(int*, int);
int main()
{
    int tamanho = 0, *vetor;
    while(scanf("%d", &tamanho) != EOF)
    {
        vetor = (int*)malloc(tamanho * sizeof(int));
        for(int i = 0; i < tamanho; i++)
            scanf("%d", &vetor[i]);

        if(esta_ordenado_crescente(vetor, tamanho))
            printf("S\n");
        else if(esta_ordenado_decrescente(vetor, tamanho))
            printf("S\n");
        else
            printf("N\n");

        free(vetor);

    }
    return 0;
}


int esta_ordenado_crescente(int *vetor, int tamanho)
{
    if(tamanho <= 1)//vetores unitarios sempre estão ordenados
        return 1;

    int ultimo = tamanho-1, penultimo = tamanho-2;//estará ordenado se o penultimo elemento for menor que o ultimo elemento e se todo o vetor antes do ultimo elemento estiver ordenado
    return vetor[penultimo] <= vetor[ultimo] && esta_ordenado_crescente(vetor, tamanho-1);
}

int esta_ordenado_decrescente(int *vetor, int tamanho)
{
    if(tamanho == 1)//vetores unitarios sempre estão ordenados
        return 1;

    int ultimo = tamanho-1, penultimo = tamanho-2;//estará ordenado se o penultimo elemento for menor que o ultimo elemento e se todo o vetor antes do ultimo elemento estiver ordenado
    return vetor[penultimo] >= vetor[ultimo] && esta_ordenado_decrescente(vetor, tamanho-1);
}