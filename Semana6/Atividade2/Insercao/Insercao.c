#include <stdio.h>
#include <stdlib.h>

void insere(int*,int);
void print(int*, int);
int main()
{
    int n, *vetor;
    scanf("%d", &n);
    vetor = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i < n ; i++)
        scanf("%d", &vetor[i]);

    insere(vetor, n-1);
    print(vetor,n);
    free(vetor);

    return 0;
}

//função que insere o valor da ultima posicão no lugar correto
void insere(int *v,int n)
{

    int chave = v[n], iChave = n-1;
    int i = n-1;

    while(i >= 0 && v[i] > chave)
    {
        //anterior armazena o atual
        v[i+1] = v[i];
        iChave = i;
        i--;
        print(v,n+1);
    }
    v[iChave] = chave;

}


void print(int *vetor, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
        printf("%d%s", vetor[i], ((i == tamanho-1) ? "\n" : " "));
}
