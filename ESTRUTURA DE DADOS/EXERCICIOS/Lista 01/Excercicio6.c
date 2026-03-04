/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    3º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2026
    Prof. Rafael Orbolato
    Data: 23/02/2026
*/
//===============================================================
//===============================================================
//======== LOCAL PARA DECLARAR AS INCLUDES E VARS GLOBAIS =======
//===============================================================
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

char vt[255]; // Minha variavel global para receber dados via texto...
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpa_tl();
int lerint();
void processando();
void pouse();
//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpa_tl()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
//===============================================================
int lerint()
{
    int lernumeroint;
    fgets(vt,255,stdin);
    sscanf(vt,"%d",&lernumeroint);
    return lernumeroint;
}
//===============================================================
void processando()
{
    limpa_tl();
    printf("\n\n\n Processando....Aguarde.... ");
    #ifdef _WIN32
    Sleep(500); //pausa a tela por 500 milesegundos...
    #else
    usleep(500000); //pausa a tela no linux e mac por 500000 MICROsegundos...
    #endif
    limpa_tl();
}
//===============================================================
void pouse()
{
    #ifdef _WIN32
    Sleep(500); //pausa a tela por 500 milesegundos...
    #else
    usleep(500000); //pausa a tela no linux e mac por 500000 MICROsegundos...
    #endif
}
//===============================================================
int dia_da_semana(int dia, int mes, int ano)
{
    int f = ano + dia + 3 * (mes - 1) - 1;
    if (mes < 3) ano--;
    else f -= (int)(0.4 * mes + 2.3);
    f += (int)(ano/4) - (int)((ano/100 + 1) * 0.75);
    f %= 7;
    return f;
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    limpa_tl();
    //CRIAR VARIAVEIS
    int dia,mes,ano;

    //INICIALIZAR VARIAVEIS

    //recebendo o dia do mes 
    do
    {
        printf("\n Informe Dia (1 a 31)...: ");
        dia = lerint();

        if (dia > 31 || dia < 1)
        {
            printf("\n ERRO! Dia Invalido.\n\n ");
        }
    } while (dia < 1 || dia > 31);

    //Recebendo o mes...
    do
    {
        printf("\n Informe o Mes (1 a 12)...: ");
        mes = lerint();

        if (mes < 1 || mes > 12)
        {
            printf("\n ERRO! Mes Invalido.\n\n ");
        }
    } while (mes < 1 || mes > 12);

    //Recebendo o ano...
    do
    {
        printf("\n Informe Ano (1 a 2026)...: ");
        ano = lerint();

        if (ano < 1 || ano > 2026)
        {
            printf("\n ERRO! Ano Invalido.\n\n ");
        }
    } while (ano < 1 || ano > 2026);

    processando(); //processando dados obtidos...

    //Mostrar o ressultado do calculo
    if (dia_da_semana(dia,mes,ano) == 0)
    {
        printf("\n A data %d/%d/%d caiu em um(a): Domingo",dia,mes,ano);
    }
    else if (dia_da_semana(dia,mes,ano) == 1)
    {
        printf("\n A data %d/%d/%d caiu em um(a): Segunda-feira",dia,mes,ano);
    }
    else if(dia_da_semana(dia,mes,ano) == 2)
    {
        printf("\n A data %d/%d/%d caiu em um(a): Terca-feira",dia,mes,ano);
    }
    else if (dia_da_semana(dia,mes,ano) == 3)
    {
        printf("\n A data %d/%d/%d caiu em um(a): Quarta-feira",dia,mes,ano);
    }
    else if (dia_da_semana(dia,mes,ano) == 4)
    {
        printf("\n A data %d/%d/%d caiu em um(a): Quinta-feira",dia,mes,ano);
    }
    else if (dia_da_semana(dia,mes,ano) == 5)
    {
        printf("\n A data %d/%d/%d caiu em um(a): Sexta-feira",dia,mes,ano);
    }
    else
    {
        printf("\n A data %d/%d/%d caiu em um(a): Sabado",dia,mes,ano);
    }
    //FINALIZAR PROGRAMA
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}