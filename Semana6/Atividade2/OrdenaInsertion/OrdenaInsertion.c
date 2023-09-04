#include <stdio.h>
#include <stdlib.h>

int insertionSort(int*,int);
void print(int*, int);
void swap(int*,int,int);
int main()
{
    int *v, n, i;

    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    print(v,n);
    int trocas = insertionSort(v,n);
    print(v,n);
    printf("Trocas:%d\n", trocas);
    if(trocas == 0)
        printf("MELHOR CASO\n");
    else if(trocas == (n*(n-1)/2))
        printf("PIOR CASO\n");
    else
        printf("CASO ALEATORIO\n");

    free(v);
}

int insertionSort(int *v,int n)
{
    int chave, j, trocas = 0;
    for(int i = 1; i < n; i++)
    {
        chave = v[i];
        j = i-1;
        while(j >= 0 && v[j] > chave)
        {
            v[j+1] = v[j];
            v[j] = chave;
            j--;
            print(v, n);
            trocas++;
        }
    }

    return trocas;
}

void print(int *vetor, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
        printf("%d%s", vetor[i], ((i == tamanho-1) ? "\n" : " "));
}

void swap(int *v,int i,int j)
{
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}