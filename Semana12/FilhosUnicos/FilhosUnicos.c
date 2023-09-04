#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct No
{
    int chave;
    struct No *pai;
    struct No *direita;
    struct No *esquerda;
};

struct Arvore
{
    struct No *raiz;
};

struct Arvore * criaArvore();
struct No * criaNo(int);
void inserir(struct Arvore *, struct No *);
int contarFilhosUnicos(struct No *);
int find(struct No *, int);
int abs(int);
int max(int, int);
void inOrder(struct No *);

int main()
{
    struct Arvore *arvore = criaArvore();
    struct No *no;
    int chave, nos;

    scanf("%d", &nos);
    for(int i = 0; i < nos; i++)
    {
        scanf("%d", &chave);
        if(!find(arvore->raiz, chave))
            inserir(arvore, criaNo(chave));
    }

    //inOrder(arvore->raiz);
    //printf("\n");
    int total = (arvore->raiz != NULL) ? contarFilhosUnicos(arvore->raiz) - 1: 0;
    printf("%d\n", total);
    return 0;
}

struct Arvore * criaArvore()
{
    struct Arvore *t = (struct Arvore*) malloc(sizeof(struct Arvore));

    if(t != NULL)
    {
        t->raiz = NULL;
    }
    return t;
}

struct No * criaNo(int chave)
{
    struct No * no = (struct No*) malloc(sizeof(struct No));

    if(no != NULL)
    {
        no->chave = chave;
        no->esquerda = NULL;
        no->direita = NULL;
        no->pai = NULL;
    }
    return no;
}

void inserir(struct Arvore *t, struct No *novo)
{
    struct No *pai = NULL, *filho = t->raiz;

    while(filho != NULL)
    {
        pai = filho;
        if(filho->chave < novo->chave)
        {
            filho = filho->direita;
        }
        else
        {
            filho = filho->esquerda;
        }
    }

    if(pai != NULL) // inserindo no folha
    {
        novo->pai = pai;
        if(pai->chave > novo->chave) // filho da esquerda
        {
            pai->esquerda = novo;
        }
        else // filho da direita
        {
            pai->direita = novo;
        }
    }
    else // inserindo no raiz
    {
        t->raiz = novo;
    }
}

int abs(int x)
{
    if (x >= 0)
        return x;

    return -1 * x;
}

int max(int a, int b)
{
    return (a+b + abs(a-b))/2;
}

int contarFilhosUnicos(struct No *no)
{
    int ae = 0, ad = 0;
    ae = (no->esquerda != NULL) ? calcularAltura(no->esquerda) : 0;
    ad = (no->direita != NULL) ? calcularAltura(no->direita) : 0;

    return 1 + max(ae, ad);
}

int find(struct No *node, int x)
{
    if(node == NULL)
        return 0;

    if(node->chave == x)
        return 1;

    if(node->chave > x)
        return find(node->esquerda, x);

    return find(node->direita, x);
}

void inOrder(struct No *r)
{
    if(r != NULL)
    {
        inOrder(r->esquerda);
        printf("%d ", r->chave);
        inOrder(r->direita);
    }
}