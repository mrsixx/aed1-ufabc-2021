#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct No
{
    int chave, nivel;
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
int find(struct No *, int);
int abs(int);
int max(int, int);
void inOrder(struct No *, int);

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
    scanf("%d", &nos);
    inOrder(arvore->raiz, nos);
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

        novo->nivel = pai->nivel+1;
    }
    else // inserindo no raiz
    {
        t->raiz = novo;
        novo->nivel = 0;
    }
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

void inOrder(struct No *r, int lvl)
{
    if(r != NULL)
    {
        inOrder(r->esquerda, lvl);
        if(r->nivel == lvl)
            printf("%d\n", r->chave);
        inOrder(r->direita, lvl);
    }
}