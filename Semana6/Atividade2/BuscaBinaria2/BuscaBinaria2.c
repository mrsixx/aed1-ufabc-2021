#include <stdio.h>
#include <stdlib.h>

int vetor_contem(int*,int, int);
int busca_binaria(int*, int, int, int);
void imprimir_slice_vetor(int*, int, int);
int main()
{
    int tamanho = 0, valor, *vetor;
    scanf("%d", &tamanho);
    //leio o vetor
    vetor = (int*)malloc(tamanho * sizeof(int));
    for(int i = 0; i < tamanho; i++)
        scanf("%d", &vetor[i]);

    while(scanf("%d", &valor) != EOF)
    {
        if(vetor_contem(vetor, valor, tamanho))
            printf("VALOR %d LOCALIZADO NA COLECAO\n", valor);
        else
            printf("VALOR %d NAO LOCALIZADO NA COLECAO\n",valor);
    }


    //libero o vetor
    free(vetor);
    return 0;
}


int vetor_contem(int *vetor, int valor, int tamanho_vetor)
{
    return busca_binaria(vetor, 0, tamanho_vetor-1, valor);
}


int busca_binaria(int* vetor, int e, int d, int valor)
{
    if(e > d)//se não estiver no vetor
        return 0;

    int meio = (e+d)/2;

    if(valor < vetor[meio])//o valor pode estar à esquerda (procuro no subvetor a esquerda)
    {
        imprimir_slice_vetor(vetor, meio, d);//imprimo o vetor descartado
        return busca_binaria(vetor, e, meio-1, valor);//busco à esquerda
    }

    if(vetor[meio] < valor)//o valor pode estar à direita (procuro no subvetor a direita)
    {

        imprimir_slice_vetor(vetor, e, meio);//imprimo o vetor descartado
        return busca_binaria(vetor, meio+1, d, valor);//busco à direita
    }

    //se não está nem a direita nem a esquerda, eu encontrei
    return 1;
}

void imprimir_slice_vetor(int *vetor, int de, int ate)
{
    for(int i = de; i <= ate;i++)
        printf("%d%s", vetor[i], (i == ate ? "\n": " "));
}