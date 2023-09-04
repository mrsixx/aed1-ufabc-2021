#include <stdio.h>
#include <stdlib.h>

typedef struct tItem{
    int value;
} Item;

typedef struct tStack{
    Item *itens;
    int size, count;
} Stack;

Stack criar(int);
void destruir(Stack);

Item newItem(int);
void add(Stack*, int);
void del(Stack*);
void print(Stack,char);
int empty(Stack);
int full(Stack);


int main()
{
    int n,x;
    char cmd;
    scanf("%d", &n);
    Stack pilha = criar(n);
    while(scanf("%c", &cmd) != EOF)
    {
        switch(cmd)
        {
            case 'E'://empilha
                scanf("%d", &x);
                add(&pilha, x);
                break;
            case 'D'://desempilha
                del(&pilha);
                break;
            case 'T'://topo p/ base
            case 'B'://base p/ stopo
                print(pilha, cmd);
                break;
        }
    }
    destruir(pilha);
    return 0;
}

Stack criar(int n)
{
    Stack p;
    p.itens = (Item*) malloc(n * sizeof(Item));
    p.size = n;
    p.count = 0;
    return p;
}
Item newItem(int v)
{
    Item i;
    i.value = v;
    return i;
}
void add(Stack *p, int x)
{
    if(!full(*p))
    {
        p->count++;
        p->itens[p->count-1] = newItem(x);
    }
}
void del(Stack *p)
{
    Item it;
    if(!empty(*p))
    {
        it = p->itens[p->count-1];
        p->count--;
    }
}
void print(Stack p, char cmd)
{
    if(empty(p))
        return;

    switch(cmd)
    {
        case 'B':
            for(int i = 0; i < p.count; i++)
                printf("%d\n", p.itens[i].value);
            break;
        case 'T':
            for(int i = p.count -1; i >= 0; i--)
                printf("%d\n", p.itens[i].value);
            break;
    }
}
void destruir(Stack p)
{
    free(p.itens);
}
int empty(Stack p)
{
    return p.count == 0;
}
int full(Stack p)
{
    return p.count == p.size;
}

