#include <stdio.h>

typedef struct tData{
    int dia, mes, ano;
} Data;

Data ler_data();
void print_data(Data);
Data dia_anterior(Data);
int ultimoDiaDoMes(int,int);
int ano_bissexto(int);

int main()
{

    Data data = ler_data();//leio a data
    print_data(dia_anterior(data));
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

Data dia_anterior(Data dt)
{
    int d = dt.dia, m = dt.mes, y = dt.ano;

    if(d == 1 && m == 1)//se hoje é 01/01, ontem foi ano passado
        y -= 1;


    if(d == 1)//se hoje é dia primeiro, preciso voltar pro mes passado
    {
        if(m == 1)//se estavamos em janeiro
            m = 12;//voltamos pra dezembro
        else
            m -= 1;//se não apenas voltamos um mês
    }

    //se for o primeiro dia do mes
    if(d == 1)
        d = ultimoDiaDoMes(m,y);//ultimo dia do novo mes
    else
        d -= 1;//se não apenas volto um dia


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