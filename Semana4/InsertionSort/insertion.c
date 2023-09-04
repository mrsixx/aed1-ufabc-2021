#include <stdio.h>
#include <stdlib.h>

void insertionSort(int*,int);
int main()
{
    int *v, n, i;

    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    insertionSort(v,n);

    for(i = 0; i < n; i++)
        printf("%d%s", v[i], (i == n-1)? "\n": " ");


    free(v);
}

void insertionSort(int *v,int n)
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