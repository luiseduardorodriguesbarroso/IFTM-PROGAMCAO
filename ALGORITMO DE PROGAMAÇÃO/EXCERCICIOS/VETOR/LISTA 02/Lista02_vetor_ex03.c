/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: 28/09/2025
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
#include <windows.h>

//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
void mfaturamento ();
void processar();

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================
void mfaturamento ()
{
    processar();
    //VARIAVEIS PARA CALCULAR O FATURAMENTO 
    int produto = 0;
    int quantidade = 0;
    int faturamento = 0;
    int preco = 0;
    //RECEBER VALORES
    printf("Informe o numero do produto...: ");
    fflush(stdin);
    scanf("%d",&produto);

    printf("Informe a quantidade de produtos vendidos...: ");
    fflush(stdin);
    scanf("%d",&quantidade);

    printf("Informe o preco do produto...: ");
    fflush(stdin);
    scanf("%d",&preco);

    //CAUCULO DO FATURAMENTO 
    faturamento = (quantidade * preco) + faturamento;
    //MOSTRAR FATURAMENTO
    limpartl();
    Sleep(200);
    printf("\nSeu faturamento atual e de ...: %d\n\n",faturamento);
}
//===============================================================
void processar()
{
    limpartl();
    printf("\n\nCaregando planilha de faturamento...");
    Sleep(900);
    limpartl();
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int opc;
    
    //INICIALIZAR VARIAVEIS
    while(opc !=2)
    {
        printf("\n-----PLANILHA DE FATURAMENTO-----");
        printf("\n1- Calcular faturamento");
        printf("\n2- Finalizar progama");
        printf("\nInforme uma das opcoes abaixo...: ");
        fflush(stdin);
        scanf("%d",&opc);

        if (opc == 1)
        mfaturamento();
        else if (opc > 2 || opc < 1)
        {
            limpartl();
            printf("\nErro!Informe uma das opcoes do menu...\n\n");
            Sleep(750);
        }
    }
    
    //FINALIZAR PROGRAMA
    limpartl();
    printf("\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}