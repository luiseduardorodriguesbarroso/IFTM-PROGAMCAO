/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    2 SEMESTRE 2025
    Prof. Rafael Orbolato
    Data: 15/02/2026
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

char vt[255]; // Minha variavel global para receber dados via texto...
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpa_tl();
int lerint ();


//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpa_tl()
{
    system("clear");//Vai limpar a minha tela
}
//===============================================================
int lerint ()
{
    int numero;
    fgets(vt, 255, stdin);
    sscanf(vt,"%d",&numero);
    return numero;
}
//===============================================================
int vrfc_primo()
{

}
//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int x;
   

    //INICIALIZAR VARIAVEIS
    printf("\n Informe um numero...: ");
    x = lerint();

    printf("\n %d",x);

    //CALCULO DA SOMA DAS VARIAVEIS 
   
    //FINALIZAR PROGRAMA
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}