#include <stdio.h>
#include <stdlib.h>


typedef struct Item
{
    int chave;
} Item;

typedef struct Queue
{
    Item *itens;
    int tamanho;
    int inicio, fim;
} Queue;

Queue criaFila(int);
Item criarItem(int);
void enfileirar(Queue*, int);
Item desenfileirar(Queue*);
int filaVazia(Queue);
int filaCheia(Queue);
void mostrarFila(Queue);

int main()
{
    Queue q;
    int n, chave;
    char op;
    scanf("%d", &n);
    q = criaFila(n);

    while(scanf("\n%c", &op) != EOF)
    {
        switch(op)
        {
            case 'E':
                scanf("%d", &chave);
                enfileirar(&q,chave);
                break;
            case 'D':
                if(!filaVazia(q))
                    //printf("Item %d desenfileirado\n", desenfileirar(&q).chave);
                break;
            case 'M':
                mostrarFila(q);
                break;
        }
    }
    return 0;
}



Queue criaFila(int n)
{
    Queue q;
    q.itens = (Item*) malloc(n * sizeof(Item));
    q.tamanho = n;
    q.inicio = -1;
    q.fim = -1;
    return q;
}
Item criarItem(int chave)
{
    Item i = {chave};
    return i;
}
void enfileirar(Queue *q, int chave)
{
    if(filaCheia(*q))
        return;

    if(filaVazia(*q))
        q->inicio++;

    q->fim++;
    q->itens[q->fim] = criarItem(chave);

}

Item desenfileirar(Queue *q)
{
    Item it;
    if(!filaVazia(*q))
    {
        it = q->itens[q->inicio];
        if(q->inicio != q->fim)
        {
            q->inicio++;
        }
        else
        {
            q->inicio = -1;
            q->fim = -1;
        }
    }

    return it;
}

int filaVazia(Queue q)
{
    return (q.inicio == -1 && q.fim == -1) || q.inicio > q.fim;
}
int filaCheia(Queue q)
{
    return q.fim == q.tamanho -1;
}

void mostrarFila(Queue q)
{
    if(!filaVazia(q))
        for(int i = q.inicio; i <= q.fim; i++)
            printf("%d%s", q.itens[i].chave, i < q.fim ? " ": "\n");
}