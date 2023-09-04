#include <stdio.h>
#include <stdlib.h>

void quicksort(int*, int, int);
int particiona(int*, int, int);
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
    quicksort(vetor, 0, n-1);
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

void quicksort(int *vetor, int e, int d)
{
    int p;

    if(e < d)
    {
        p = particiona(vetor, e, d);
        quicksort(vetor, e, p-1);
        quicksort(vetor, p+1, d);
    }
}


int particiona(int *v, int e, int d)
{
    int pm, aux;

    for(int i = e, pm = e-1; i < d; i++)
    {
        if(v[i] < v[d])
        {
            pm++;
            aux = v[i];
            v[i] = v[pm];
            v[pm] = aux;
        }
    }
    aux = v[d];
    v[d] = v[pm+1];
    v[pm+1] = aux;

    return pm+1;
}