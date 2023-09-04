#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int*,int);
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
    int trocas = bubbleSort(v,n);
    print(v,n);
    printf("Trocas: %d\n", trocas);


    free(v);
}

int bubbleSort(int *v,int n)
{
    int i, j, aux, trocas = 0;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(v[j] > v[j+1])
            {
                swap(v,j,j+1);
                print(v, n);
                trocas++;
            }
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