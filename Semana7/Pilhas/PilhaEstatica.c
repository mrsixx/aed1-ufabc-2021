#include <stdio.h>
#include <stdlib.h>

typedef struct Item
{
    int chave;
} Item;

typedef struct Stack
{
    Item *itens;
    int tamanho;
    int topo;
} Stack;

Stack criaPilha(int);
Item criarItem(int);
int pilhaVazia(Stack);
int pilhaCheia(Stack);
void empilhar(Stack*, Item);
Item desempilhar(Stack*);
void mostrarPilhaBaseTopo(Stack);
void mostrarPilhaTopoBase(Stack);

int main()
{
    Stack s;
    int n, chave;
    char op;
    scanf("%d", &n);
    s = criaPilha(n);

    while(scanf("\n%c", &op) != EOF)
    {
        switch(op)
        {
            case 'E':
                scanf("%d", &chave);
                empilhar(&s, criarItem(chave));
                break;
            case 'D':
                if(!pilhaVazia(s))
                    printf("Item %d desempilhado\n", desempilhar(&s).chave);
                break;
            case 'B':
                mostrarPilhaBaseTopo(s);
                break;
            case 'T':
                mostrarPilhaTopoBase(s);
                break;
        }
    }
    free(s.itens);
    return 0;
}



Stack criaPilha(int n)
{
    Stack p;
    p.itens = (Item*) malloc(n*sizeof(Item));
    p.tamanho = n;
    p.topo = -1;
    return p;
}

Item criarItem(int chave)
{
    Item it;
    it.chave = chave;
    return it;

}
int pilhaVazia(Stack p)
{
    return p.topo == -1;
}
int pilhaCheia(Stack p)
{
    return p.topo == p.tamanho -1;

}

void empilhar(Stack *p, Item i)
{
    if(!pilhaCheia(*p))
    {
        p->topo++;
        p->itens[p->topo] = i;
    }

}
Item desempilhar(Stack *p)
{
    Item it;
    if(!pilhaVazia(*p))
    {
        it = p->itens[p->topo];
        p->topo--;
    }
    return it;
}
void mostrarPilhaBaseTopo(Stack p)
{
    for(int i = 0; i <= p.topo; i++)
        printf("%d%s", p.itens[i].chave, (i < p.topo ? " " : "\n"));
}

void mostrarPilhaTopoBase(Stack p)
{
    for(int i = p.topo; i >= 0; i--)
        printf("%d%s", p.itens[i].chave, (i > 0 ? " " : "\n"));

}