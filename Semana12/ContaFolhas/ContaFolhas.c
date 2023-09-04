#include <stdio.h>
#include <stdlib.h>
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
int calcularFolhas(struct No *);
int find(struct No *, int);

void inOrder(struct No *);

int main()
{
    struct Arvore *arvore = criaArvore();
    int chave, n, ret;

    ret = scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        ret = scanf("%d", &chave);
        if(!find(arvore->raiz, chave))
            inserir(arvore, criaNo(chave));
    }

    //inOrder(arvore->raiz);
    //printf("\n");
    int total = (arvore->raiz != NULL) ? calcularFolhas(arvore->raiz): 0;
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

int calcularFolhas(struct No *no)
{
    if(no == NULL)
        return 0;
    if(no->esquerda == NULL && no->direita == NULL)
        return 1;

    return calcularFolhas(no->esquerda) + calcularFolhas(no->direita);
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