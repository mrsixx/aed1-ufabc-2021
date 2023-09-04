#include <stdio.h>
#include <stdlib.h>

typedef struct tItem{
    int value;
} Item;

typedef struct tQueue{
    Item *itens;
    int size;
    int start, end;
} Queue;

Queue criar(int);
Item newItem(int);
void add(Queue*, int);
void del(Queue*);
void print(Queue);
void destruir(Queue);
int empty(Queue);
int full(Queue);


int main()
{
    int n,x;
    char cmd;
    scanf("%d", &n);
    Queue fila = criar(n);
    while(scanf("%c", &cmd) != EOF)
    {
        switch(cmd)
        {
            case 'E':
                scanf("%d", &x);
                add(&fila, x);
                break;
            case 'D':
                del(&fila);
                break;
        }
    }
    destruir(fila);
    return 0;
}
Queue criar(int n)
{
    Queue f;
    f.itens = (Item*) malloc(n * sizeof(Item));
    f.size = n;
    f.start = 0;
    f.end = 0;
    return f;
}
Item newItem(int v)
{
    Item i;
    i.value = v;
    return i;
}
void add(Queue *f, int x)
{
    if(!full(*f))
    {
        f->itens[f->end] = newItem(x);
        f->end = (f->end+1)%f->size;
    }
}
void del(Queue *f)
{
    Item it;
    if(!empty(*f))
    {
        it = f->itens[f->start];
        f->start = (f->start+1)%f->size;
        printf("%d\n", it.value);
    }
}
void print(Queue f)
{
    if(empty(f))
        return;

    for(int i = 0; i <= f.end; i++)
        printf("%d\n", f.itens[i].value);

}
void destruir(Queue f)
{
    free(f.itens);
}
int empty(Queue f)
{
    return (f.start == f.end);
}
int full(Queue f)
{
    return (f.end+1)%f.size == f.start;
}

