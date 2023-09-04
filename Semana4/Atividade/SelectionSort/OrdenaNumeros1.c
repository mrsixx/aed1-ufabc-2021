#include <stdio.h>
#include <stdlib.h>

void selectionnsort(int*, int);
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
    selectionnsort(vetor, n);
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

void selectionnsort(int *v, int n)
{
    int iMin,aux;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1, iMin = i; j < n;j++)
        {
            if(v[j] < v[iMin])
            {
                iMin = j;
            }
        }
        aux = v[iMin];
        v[iMin] = v[i];
        v[i] = aux;
    }
}