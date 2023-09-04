#include <stdio.h>

typedef struct tStrut{
    int dia, mes, ano;
} Data;

int eh_ano_bissexto(Data);
int eh_data_valida(Data);
int dias_mes(Data);
Data ler_data();

int main()
{
    Data dt = ler_data();
    if(eh_data_valida(dt))
    {
        printf("DATA VALIDA");
    }
    else
    {
        printf("DATA INVALIDA");
    }

    printf("\n");
    return 0;
}

int dias_mes(Data dt)
{
    if(dt.mes == 2)
    {
        return (eh_ano_bissexto(dt)) ? 29 : 28;
    }

    //31 28|29 31 30 31 30 31 31 30 31 30 31
    int meses31[] = {1,3,5,7,8,10,12};//6 meses
    for(int i = 0; i <= 6; i++)
    {
        if(meses31[i] == dt.mes)
        {
            return 31;
        }

    }

    return 30;

}

int eh_data_valida(Data dt)
{
    if(dt.mes < 1 || dt.mes > 12)
    {
        return 0;
    }

    if(dt.dia < 1 || dt.dia > dias_mes(dt))
    {
        return 0;
    }

    if(dt.ano < 1582)
    {
        return 0;
    }

    return 1;
}

Data ler_data()
{
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    Data dt = {dia,mes,ano};
    return dt;
}

int eh_ano_bissexto(Data data)
{
    int ano = data.ano;
    if(ano % 400 == 0)
    {
        return 1;
    }

    if(ano % 4 == 0 && ano % 100 != 0)
    {
        return 1;
    }


    return 0;
}
