#include <stdio.h>

typedef struct tData{
    int dia, mes, ano;
} Data;

Data ler_data();
void print_data(Data);
Data proximo_dia(Data);
int ultimoDiaDoMes(int,int);
int ano_bissexto(int);

int main()
{
    Data data = ler_data();//leio a data
    print_data(proximo_dia(data));
    return 0;
}

Data ler_data()
{

    int d,m,y;
    scanf("%d %d %d", &d,&m,&y);
    Data dt = {d,m,y};

    return dt;
}

void print_data(Data dt)
{
    printf("%d %d %d\n", dt.dia, dt.mes, dt.ano);
}

Data proximo_dia(Data dt)
{
    int d = dt.dia, m = dt.mes, y = dt.ano;
    if(d == ultimoDiaDoMes(m,y))
        d = 1;
    else
        d += 1;

    if(d == 1)//caso a data tenha excedido o limite, pulo pro próximo mes
        m += 1;

    if(m > 12)//se passamos de dezembro, voltamos pra janeiro
        m =1;

    if(dt.mes == 12 && d == 1)//se estamos em dezembro e amanhã for dia primeiro, então amanhã será um novo ano
        y += 1;

    Data dtAnterior = {d,m,y};
    return dtAnterior;
}

int ultimoDiaDoMes(int m, int y)
{
    if(m == 2)
        return (ano_bissexto(y)) ? 29 : 28;

    int meses_31[] = {1,3,5,7,8,10,12};
    int qtd_meses = sizeof(meses_31) / sizeof(int);

    for(int i = 0; i < qtd_meses; i++)
        if(meses_31[i] == m)
            return 31;

    return 30;
}
int ano_bissexto(int y)
{
    if(y % 400 == 0)
        return 1;
    if(y % 4 == 0 && y % 100 != 0)
        return 1;

    return 0;
}