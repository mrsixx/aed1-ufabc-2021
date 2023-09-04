#include <stdio.h>
#include <stdlib.h>

void insertionsort(int*, int);
void imprimir(int*, int);
int main()
{
    int n, *vetor;
    scanf("%d", &n);
    vetor = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    //ordeno
    insertionsort(vetor, n);
    //imprimo
    imprimir(vetor, n);
    //printf("\n");

    free(vetor);
    return 0;
}

void imprimir(int *vetor, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d%c", vetor[i], ((i < n-1) ? ' ' : '\n'));
}

void insertionsort(int *v, int n)
{
    int chave, j;
    for(int i = 1; i < n; i++)
    {
        chave = v[i];
        j = i-1;
        while(j >= 0 && v[j] > chave)
        {
            v[j+1] = v[j];
            v[j] = chave;
            j--;
        }
    }
}