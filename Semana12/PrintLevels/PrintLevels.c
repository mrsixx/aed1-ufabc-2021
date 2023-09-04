#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct No
{
    int chave, nivel;
    struct No *pai;
    struct No *direita;
    struct No *esquerda;
} No;

typedef struct Arvore
{
    struct No *raiz;
} Arvore;

struct Arvore * criaArvore();
struct No * criaNo(int);
void inserir(struct Arvore *, struct No *);
int find(struct No *, int);
int abs(int);
int max(int, int);
void printLargura(struct No *);

typedef struct Item
{
    struct No *chave;
    struct Item *proximo;
} Item;

typedef struct Fila
{
    struct Item *inicio;
    struct Item *final;
} Fila;

struct Fila * criaFila();
struct Item * criaItem(struct No *);
int filaVazia(struct Fila *);
void enfileirar(struct Fila *, struct No *);
struct Item * desenfileirar(struct Fila *);

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
    printLargura(arvore->raiz);
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

void printLargura(struct No *node)
{

    Fila *f = criaFila();
    enfileirar(f, node);

    while (!filaVazia(f))
    {
        Item *it = desenfileirar(f);
        No *n = it->chave;
        //imprimo
        printf("%d\n", n->chave);
        //enfilero o filhos
        if (n->esquerda != NULL)
            enfileirar(f, n->esquerda);

        if (n->direita != NULL)
            enfileirar(f, n->direita);

        free(it);
    }
}







struct Fila * criaFila()
{
    struct Fila *f = (struct Fila*) malloc(sizeof(struct Fila));
    if(f != NULL)
    {
        f->inicio = NULL;
        f->final = NULL;
    }
    return f;
}

struct Item * criaItem(No *node)
{
    struct Item *it = (struct Item *) malloc(sizeof(struct Item));
    if(it != NULL)
    {
        it->chave = node;
        it->proximo = NULL;
    }
    return it;
}

int filaVazia(struct Fila *f)
{
    return f->inicio == NULL && f->final == NULL;
}

void enfileirar(struct Fila *f, No *node)
{
    struct Item *novo = criaItem(node);
    if(filaVazia(f))
    {
        f->inicio = novo;
    }
    else
    {
        f->final->proximo = novo;
    }
    f->final = novo;
}

struct Item * desenfileirar(struct Fila *f)
{
    struct Item *it = f->inicio;

    if(!filaVazia(f))
    {
        if(f->inicio == f->final)
        {
            f->final = NULL;
        }
        f->inicio = f->inicio->proximo;
    }
    return it;
}
