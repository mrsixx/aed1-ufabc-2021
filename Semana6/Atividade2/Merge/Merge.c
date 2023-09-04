#include<stdio.h>
#include<stdlib.h>

void mergeSort(int*,int, int, int);
void print(int*, int);
void swap(int*,int,int);
void intercala(int*, int, int, int);
int main()
{
    int *v, n, i;

    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    print(v,n);
    mergeSort(v,0,n-1, n);
    print(v,n);

    free(v);
}

void mergeSort(int *vetor, int inicio, int fim, int n)
{
    int meio;
    if(inicio < fim)
    {
        meio = (inicio + fim)/2;
        mergeSort(vetor, inicio, meio, n);
        mergeSort(vetor, meio+1, fim, n);
        print(vetor,n);
        intercala(vetor, inicio, meio+1, fim);
    }
}

void intercala(int *vetor, int inicio, int meio, int fim)
{
    int *v;
    int max_e = meio -1 , tamanho = fim - inicio + 1, i, j, iV;
    v = (int*) malloc((tamanho)* sizeof(int));


    for(i = inicio, j = meio, iV = 0; i <= max_e && j <= fim; iV++)
    {
        if(vetor[i] < vetor[j])
            v[iV] = vetor[i++];
        else
            v[iV] = vetor[j++];
    }

    for(;i<=max_e; iV++, i++)
        v[iV] = vetor[i];

    for(;j<=fim; iV++, j++)
        v[iV] = vetor[j];

    for(i=inicio, j=0; i<=fim; i++, j++)
        vetor[i] = v[j];

    free(v);
}

void print(int *vetor, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
        printf("%d%s", vetor[i], ((i == tamanho-1) ? "\n" : " "));
}
