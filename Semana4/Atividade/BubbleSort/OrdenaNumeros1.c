#include <stdio.h>
#include <stdlib.h>

void bubblesort(int*, int);
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
    bubblesort(vetor, n);
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

void bubblesort(int *v, int n)
{
    int i, j, aux;
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(v[j] > v[j+1])
            {
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}