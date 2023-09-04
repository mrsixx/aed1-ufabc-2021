#include <stdio.h>
#include <stdlib.h>
typedef struct tData{
    int dia, mes, ano;
} Data;

Data ler_data();
void print_data(Data);
Data proximo_dia(Data);
Data dia_anterior(Data);
int ultimoDiaDoMes(int,int);
int ano_bissexto(int);
int eh_data_valida(Data);


int main()
{
    int n, k;
    char* cmd;
    scanf("%d", &n);
    //n testes
    for(int i = 0; i < n; i++)
    {
        Data dt = ler_data(), dtTemp;
        //me preparo para ler k comandos
        scanf("%d", &k);
        cmd = (char*)malloc(sizeof(char) * (k+1));
        //leio k comandos
        if(cmd != NULL) {
            for(int j = 0; j < k+1; j++)
                scanf("%c", &cmd[j]);
            //para cada comando, executo a ação
            for(int j = 0; j < k+1; j++)
            {
                //printf("[%c]\n",cmd[j]);
                switch(cmd[j])
                {
                    case '>':
                        dtTemp = proximo_dia(dt);
                        break;
                    case '<':
                        dtTemp = dia_anterior(dt);
                        break;
                    default:
                        dtTemp.dia = 0;
                        dtTemp.mes = 0;
                        dtTemp.ano = 0;
                        break;
                }

                if(eh_data_valida(dtTemp))
                    dt = dtTemp;
            }

    	}

        //imprimo a data
        print_data(dt);
    	free(cmd);
    }
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
    printf("%d/%d/%d\n", dt.dia, dt.mes, dt.ano);
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
int eh_data_valida(Data dt)
{
    if(dt.mes < 1 || dt.mes > 12)
    {
        return 0;
    }

    if(dt.dia < 1 || dt.dia > ultimoDiaDoMes(dt.mes, dt.ano))
    {
        return 0;
    }

    if(dt.ano < 0)
    {
        return 0;
    }

    return 1;
}