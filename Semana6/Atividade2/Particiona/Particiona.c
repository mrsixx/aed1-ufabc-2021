#include <stdio.h>
#include <stdlib.h>

int particiona(int*, int, int,int);
void troca(int*,int,int);
int main()
{
    int *vetor, pivo, tamanho;
    scanf("%d %d", &tamanho, &pivo);
    vetor = (int*)malloc(sizeof(int) * tamanho);
    if(vetor != NULL)
    {
        for(int i = 0; i < tamanho; i++)
            scanf("%d", &vetor[i]);

        if(pivo < tamanho)
            particiona(vetor, 0, tamanho-1,pivo);

        for(int i = 0; i < tamanho; i++)
            printf("%d\n", vetor[i]);
    }
    return 0;
}
int particiona(int *v, int e, int d, int posPivo)
{
    int pivo, i, j;
    pivo = v[posPivo];
    i = e-1;
    for(j = e; j < d-1; j++)
    {
       if(v[j] < pivo)
        {
            troca(v, ++i, j);
        }
    }
    troca(v, i+1, posPivo);
    troca(v, posPivo, d);
    return i+1;
}
void troca(int *vetor, int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}