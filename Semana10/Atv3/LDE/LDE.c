#include <stdio.h>
#include <stdlib.h>

typedef struct tItem{
  int value;
  struct tItem *next;
} Item;

typedef struct tList {
    Item *first;
    int count;
} List;

List *newList();
void destroyList(List*);
Item *newItem(int);
void insert(List*, int);
void apagar(List*,int);
int find(List*, int);
void print(List*);

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
                if(!find(l,x))
                    insert(l,x);
                break;
            case 'R':
                scanf("%d", &x);
                if(find(l,x))
                    apagar(l,x);
                break;
            case 'B':
                scanf("%d", &x);
                printf("%s\n", find(l,x) ? "SIM": "NAO");
                break;
            case 'L':
                print(l);
                break;
        }
    }

    destroyList(l);
    return 0;
}



List *newList()
{
    List *l = (List*)malloc(sizeof(List));
    l->first = NULL;
    l->count = 0;

    return l;
}
Item *newItem(int x)
{
    Item *i = (Item*)malloc(sizeof(Item));
    i->next = NULL;
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
        free(anterior);
    }
    free(l);
}

void insert(List *l, int x)
{
    //encontro a posição de inserção
    Item *anterior = NULL, *atual = l->first;
    int achei = 0;
    while(atual != NULL && !achei)
    {
        if(atual->value > x)
        {
            achei = 1;
        }
        else
        {
            anterior = atual;
            atual = atual->next;
        }
    }

    Item *i = newItem(x);
    //inserir no começo
    if(anterior == NULL)
        l->first = i;
    else//inserir no meio e no fim
        anterior->next = i;

    i->next = atual;
}
void apagar(List *l, int x)
{
    //encontro a posição de inserção
    Item *anterior = NULL, *atual = l->first;
    int achei = 0;
    while(atual != NULL && !achei)
    {
        if(atual->value < x)
        {
            anterior = atual;
            atual = atual->next;
        }
        else
        {
            if(atual->value > x)
                atual = NULL;

            achei = 1;
        }
    }

    if(atual != NULL)
    {

        //apagar do começo
        if(anterior == NULL)
            l->first = atual->next;
        else//apagar do meio e no fim
            anterior->next = atual->next;

        free(atual);
    }

}
int find(List *l, int x)
{
    //encontro a posição de inserção
    Item *anterior = NULL, *atual = l->first;
    while(atual != NULL)
    {
        if(atual->value < x)
        {
            anterior = atual;
            atual = atual->next;
        }
        else
        {
            if(atual->value > x)
                return 0;

            return 1;
        }
    }
    return 0;

}

void print(List *l)
{
    Item *atual;
    for(atual = l->first; atual != NULL; atual = atual->next)
    {
        printf("%d%s", atual->value, atual->next != NULL ?" ":"\n");
    }
}