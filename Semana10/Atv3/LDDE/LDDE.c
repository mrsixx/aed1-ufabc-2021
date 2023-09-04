#include <stdio.h>
#include <stdlib.h>

typedef struct tItem{
  int value;
  struct tItem *next, *prev;
} Item;

typedef struct tList {
    Item *first, *last;
} List;

List *newList();
void destroyList(List*);
Item *newItem(int);
void insert(List*, int);
void apagar(List*,int);
Item *find(List*, int);
void print(List*, char);


int isEmpty(List*);
int main()
{
    List *l = newList();
    char cmd; int x;
    while(scanf("\n%c", &cmd)!= EOF)
    {
        switch(cmd)
        {
            case 'I':
                scanf("%d", &x);
                Item *i = find(l,x);
                if(i==NULL)
                    insert(l,x);
                break;
            case 'E':
                scanf("%d", &x);
                apagar(l,x);
                break;
            case 'M':
            case 'R':
                print(l, cmd);
                break;
        }
    }

    //destroyList(l);
    return 0;
}



List *newList()
{
    List *l = (List*)malloc(sizeof(List));
    l->first = NULL;
    l->last = NULL;

    return l;
}
Item *newItem(int x)
{
    Item *i = (Item*)malloc(sizeof(Item));
    i->next = NULL;
    i->prev = NULL;
    i->value = x;
    return i;
}
void destroyList(List *l)
{
    Item *anterior = NULL, *atual = l->first;
    while(atual != NULL)
    {
        anterior = atual;
        atual = atual->next;
        if(anterior->prev != NULL)
            free(anterior->prev);

        if(anterior != NULL)
           free(anterior);
    }
    free(l);
}

void insert(List *l, int x)
{
    //encontro a posição de inserção
    Item *atual = l->first;
    int achei = 0;
    while(atual != NULL && atual->value < x)
    {
        atual = atual->next;
    }

    Item *i = newItem(x);
    if(atual == NULL)
    {
        if(isEmpty(l))//inicio
        {
            l->first = i;
            l->last = i;
        }
        else //ultimo
        {
            l->last->next = i;
            i->prev = l->last;
            l->last = i;
        }
    }
    else//meio ou inicio nao vazia
    {
        i->prev = atual->prev;
        i->next = atual;

        if(atual->prev != NULL)//meio
            atual->prev->next = i;
        else
            l->first = i;

        atual->prev = i;
    }
}
void apagar(List *l, int x)
{
    //encontro a posição de inserção
    Item *atual = find(l,x);
    if(atual != NULL)
    {
        if(atual->prev != NULL) // removendo meio ou ultimo
        {
            if(atual->next != NULL) // meio
            {
                atual->prev->next = atual->next;
                atual->next->prev = atual->prev;
            }
            else // ultimo
            {
                atual->prev->next = atual->next;
                l->last = atual->prev;
            }
        }
        else // removendo primeiro
        {
            if(atual->next != NULL)
                atual->next->prev = atual->prev;
            else
                l->last = atual->next;

            l->first = atual->next;
        }
    }
    if(atual != NULL)
        free(atual);
}

Item *find(List *l, int x)
{
    //encontro a posição de inserção
    Item *atual;
    for(atual = l->first; atual != NULL && atual->value < x; atual= atual->next)
    {

    }
    if(atual != NULL && atual->value != x)
        atual = NULL;
    return atual;

}

void print(List *l, char cmd)
{
    Item *atual;
    switch(cmd)
    {
        case 'M':
           for(atual = l->first; atual != NULL; atual = atual->next)
                    printf("%d ", atual->value);
            printf("\n");
            break;
        case 'R':
            for(atual = l->last; atual != NULL; atual = atual->prev)
                printf("%d ", atual->value, atual->prev != NULL ?" ":"\n");

            printf("\n");

            break;
    }

}

int isEmpty(List *l)
{
    return l->first == NULL && l->last == NULL;
}