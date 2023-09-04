#include <stdio.h>
#include <stdlib.h>

void alocar_vetor(int*, int);
void ler_vetor(int*, int);
int soma_vetor(int*, int);
void print_vetor(int*, int);
int main()
{

    int n, *vetor, soma;
    scanf("%d", &n);

    alocar_vetor(&vetor, n);
    print_vetor(vetor, n);
    ler_vetor(&vetor, n);
    print_vetor(vetor, n);
    soma = soma_vetor(&vetor, n);

    printf("%d\n", soma);

    free(vetor);
    return 0;
}

void print_vetor(int* vetor, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", vetor[i]);

    printf("\n");
}

void alocar_vetor(int* vetor, int n)
{
    vetor = (int *) malloc(sizeof(int) * n);

    if(vetor != NULL)
    {

        for(int i = 0; i < n; i++)
        {
            *(vetor + i) = 0;
        }
    }
}
void ler_vetor(int* vetor, int n)
{
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &vetor[n]);
    }
}

int soma_vetor(int* vetor, int n)
{
    int soma = 0;
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", vetor[i]);
        soma += vetor[i];
    }
    return soma;
}