#include <stdio.h>
#include <stdlib.h>

struct Item
{
    int chave;
    struct Item *anterior;
};

struct Pilha
{
    struct Item *topo;
};

struct Pilha * criaPilha();
struct Item * criaItem(int);
int pilhaVazia(struct Pilha *);
void empilhar(struct Pilha *, struct Item *);
struct Item * desempilhar(struct Pilha *);
void mostrarPilhaTopoBase(struct Pilha *);


int main()
{
    struct Pilha *pilha = criaPilha();
    struct Item *it;
    int chave;
    char op;

    while(scanf("\n%c", &op) != EOF)
    {
        switch(op)
        {
            case 'E':
                scanf("%d", &chave);
                empilhar(pilha, criaItem(chave));
                break;
            case 'D':
                it = desempilhar(pilha);
                if(it != NULL)
                {
                    printf("[%d]\n", it->chave);
                    free(it);
                }
                break;
            case 'M':
                mostrarPilhaTopoBase(pilha);
                break;
        }
    }
    free(pilha);
    return 0;
}

struct Pilha * criaPilha()
{
    struct Pilha *p = (struct Pilha *) malloc(sizeof(struct Pilha));
    if(p != NULL)
    {
        p->topo = NULL;
    }
    return p;
}

struct Item * criaItem(int chave)
{
    struct Item *it = (struct Item *) malloc(sizeof(struct Item));
    if(it != NULL)
    {
        it->chave = chave;
        it->anterior = NULL;
    }
    return it;
}

int pilhaVazia(struct Pilha *p)
{
    return p->topo == NULL;
}

void empilhar(struct Pilha *p, struct Item *novo)
{
    novo->anterior = p->topo;
    p->topo = novo;
}

struct Item * desempilhar(struct Pilha *p)
{
    struct Item *it = p->topo;
    if(!pilhaVazia(p))
    {
        p->topo = p->topo->anterior; // p->topo = it->anterior;
    }
    return it;
}

void mostrarPilhaTopoBase(struct Pilha *p)
{
    struct Item *it = p->topo;

    while(it != NULL)
    {
        printf("%d%s", it->chave, it->anterior!=NULL?" ":"\n");
        it = it->anterior;
    }
}

void mostrarPilhaBaseTopo(struct Pilha *p)
{
    struct Pilha *tmpPilha = criaPilha();
    struct Item *it = p->topo;

    while(it != NULL)
    {
        empilhar(tmpPilha, criaItem(it->chave));
        it = it->anterior;
    }

    while(!pilhaVazia(tmpPilha))
    {
        it = desempilhar(tmpPilha);
        printf("%d%s", it->chave, pilhaVazia(tmpPilha)?"\n":" ");
        free(it);
    }
    free(tmpPilha);
}