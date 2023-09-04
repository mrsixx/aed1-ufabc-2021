#include <stdio.h>
#include <stdlib.h>

typedef struct tLista{
    int *values, size, count;
} List;

List newList(int);
void print(List);
void add(List*, int);
void del(List*, int);
int empty(List);
int full(List);
int find(List, int);
int buscaBin(int*, int, int, int);
int main()
{
    int q, n;
    char cmd;
    scanf("%d", &q);
    //crio uma lista
    List l = newList(q);

    //recebo q comandos e processo
    for(int i = 0; i < q; i++)
    {
        scanf("\n%c %d", &cmd, &n);
        switch(cmd)
        {
            case 'I':
                add(&l, n);
                break;
            case 'E':
                del(&l, n);
                break;
            default:
                break;
        }
    }
    //imprimo a lista remanescente
    print(l);
    //libero o array
    free(l.values);
    return 0;
}


List newList(int n)
{
    List l;
    l.values = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        l.values[i] = 0;

    l.size = n;
    l.count = 0;
    return l;
}
void print(List l)
{
    for(int i = 0; i < l.count; i++)
        printf("%d\n", l.values[i]);

}
void add(List *l, int num)
{
    if(!full(*l) && find(*l, num) < 0)
    {
        int i;
        for(i = 0; i < l->count; i++)
        {
            if(l->values[i] < num)
                continue;
            else
                break;
        }

        for(int j = l->count-1; j >= i; j--)
            l->values[j+1] = l->values[j];

        l->values[i] = num;
        l->count++;

    }
}
void del(List *l, int num)
{
    if(!empty(*l))
    {
        int pos = find(*l, num);
        //printf("encontrado na posição %d\n", pos);
        if(pos > -1)//se encontrou
        {
            //percorro a lista do fim pro começo
            for(int i = pos; i < l->count - 1; i++)
            {
                l->values[i] = l->values[i + 1];//trocando
            }
            l->count--;
        }
    }

}
int empty(List l)
{
    return l.count == 0;
}
int full(List l)
{
    return l.count == l.size;
}

int find(List l, int x)
{
    return buscaBin(l.values, x, 0, l.count-1);
}

int buscaBin(int *l, int x, int e, int d)
{
    int meio = (e+d)/2;
    if(x == l[meio])
        return meio;

    if(e > d)
        return -1;

    if(x < l[meio])//esta a esquerda
        return buscaBin(l, x, e, meio-1);
    //esta a direita
    return buscaBin(l,x, meio+1, d);

}