/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    2 SEMESTRE 2025
    Prof. Rafael Orbolato
    Data: 05/02/2026
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


//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpa_tl();
void Processo();
int lerint();


//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpa_tl()
{
    system("clear");//Vai limpar a minha tela
}
//===============================================================
void Processo ()
{
    limpa_tl();
    printf("\n Processando... \n");
    sleep(1);
    limpa_tl();
}
//===============================================================
int lerint()
{
    int numero;
    char vt[255]; // Meu vetor onde eu vou converter texto para numero 
    //Lendo valor...
    fgets(vt,255,stdin);
    sscanf(vt,"%d",&numero);
    return numero;
}
//===============================================================
void lerstring(char nome[], int tamanho)
{
    fgets(nome,tamanho, stdin);
    //Vamos remover o \n que o fgets adiciona
    nome[strcmp(nome, "\n")]='\0';
}
//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int x,y,z,soma;
    char Usuario[255];

    //INICIALIZAR VARIAVEIS
    printf("\n Informe seu nome...: ");
    lerstring(Usuario, 255);

    printf("\n Informe o valor para X...:");
    x = lerint();

    printf("\n Informe o valor para Y...:");
    y = lerint();

    printf("\n Informe o valor para Z...:");
    z = lerint();

    //CALCULO DA SOMA DAS VARIAVEIS 
    soma = x+y+z;
    Processo();
    printf("\n Olá,%s",Usuario);
    printf("\n Soma das variaveis e: %d",soma);

    //FINALIZAR PROGRAMA
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}