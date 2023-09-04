#include <stdio.h>
#include <stdlib.h>

int selectionSort(int*,int);
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
    int trocas = selectionSort(v,n);
    print(v,n);
    printf("%d\n", trocas);

    free(v);
}

int selectionSort(int *v, int n)
{
    int i, j, iMin, aux, trocas = 0;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1, iMin = i; j<n; j++)
        {
            if(v[j] < v[iMin])
            {
                iMin = j;
                trocas++;
            }
        }
        swap(v,iMin, i);
        print(v,n);
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