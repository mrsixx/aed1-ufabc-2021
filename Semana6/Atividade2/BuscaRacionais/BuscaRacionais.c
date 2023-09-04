#include <stdio.h>
#include <stdlib.h>

typedef struct tRacional
{
    int num, dem;
} Racional;

Racional racional(int,int);
Racional reduz(Racional);
void print(Racional);
int mdc(int,int);
int abs(int);
void ler_racionais(Racional*, int);
void ordenar(Racional*, int);
int equal(Racional, Racional);
int colecao_contem(Racional*,Racional, int);

int main()
{
    int num, dem, qtd;
    scanf("%d", &qtd);//recebo o tamanho do vetor
    Racional *colecao = (Racional*)malloc(sizeof(Racional) * qtd);

    if(colecao != NULL)
    {
        //recebo n racionais
        ler_racionais(colecao, qtd);

        //enquanto houver buscas
        while(scanf("%d %d", &num, &dem) != EOF)
        {
            Racional valor = racional(num, dem);
            if(colecao_contem(colecao, valor, qtd))
                printf("S\n");
            else
                printf("N\n");
        }
        //libero o vetor
        free(colecao);
    }

    return 0;
}

int colecao_contem(Racional *colecao, Racional valor, int tamanho)
{
    for(int i = 0; i < tamanho; i++)
        if(equal(valor, colecao[i]))
            return 1;
    return 0;
}

//função construtora de um racional
Racional racional(int a,int b)
{
    //Racional x = {a,b};
    return reduz((Racional){a,b});
}

//função para printar um racional
void print(Racional x)
{
    printf("%d %d\n", x.num, x.dem);
}

//função responsável por reduzir um numero racional
Racional reduz(Racional x)
{
    int n = x.num, d = x.dem;
    int mdComum = mdc(abs(n), abs(d));
    for(int i = mdComum; i > 0; i--)
    {
        if(n % i == 0 && d % i == 0)
        {
            n /= i;
            d /= i;
        }
    }
    Racional reduzido = {n,d};
    return reduzido;
}
//função que calcula o mdc pelo método de euclides
int mdc(int a,int b)
{
    if(b == 0)
        return a;

    return mdc(b, a%b);
}
//função que calcula o valor absoluto de um numero
int abs(int x)
{
    if(x < 0)
        return -1*x;

    return x;
}


void ler_racionais(Racional *colecao, int tamanho)
{
    int num, dem;
    //recebo n racionais
    for(int i = 0; i < tamanho; i++)
    {
        //recebo o racional
        scanf("%d %d", &num, &dem);
        //incluo no vetor
        colecao[i] = racional(num, dem);
    }
}

int equal(Racional a, Racional b)
{
    return (a.num == b.num) && (a.dem == b.dem);
}