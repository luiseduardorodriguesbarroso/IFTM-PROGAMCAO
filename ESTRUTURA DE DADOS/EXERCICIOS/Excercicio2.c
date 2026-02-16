/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    2 SEMESTRE 2025
    Prof. Rafael Orbolato
    Data: 16/02/2026
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
int lerint();
int vld_bisexto(int x);
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
    int numero;
    fgets(vt,255,stdin);
    sscanf(vt,"%d",&numero);
    return numero;
}
//===============================================================
int vld_bisexto(int x)
{
    if(x % 4 == 0 && x % 100 != 0 || x % 400 == 0)
        return 1;
     else
        return 0;    
}
//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    limpa_tl();
    //CRIAR VARIAVEIS
    int x;
   
    //INICIALIZAR VARIAVEIS
    printf("\n Informe o ano...: ");
    x=lerint();
   
    //VALIDANDO DADOS
    vld_bisexto(x); //vaçida se x e bisexto ou não e me retorna 1 ou 0
    
    //RESULTADO FINAL
    if (vld_bisexto(x) == 1) //verifica se e verdadeiro o que minha função respondeu
        printf("\n %d e um ano bisexto ",x);
    else 
        printf("\n %d nao e um ano bisexto",x);

    //FINALIZAR PROGRAMA
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}