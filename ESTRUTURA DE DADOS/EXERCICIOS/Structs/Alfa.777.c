/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    3º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2026
    Prof. Rafael Orbolato
    Data: 03/04/2026
*/
//===============================================================
//===============================================================
//======== LOCAL PARA DECLARAR AS INCLUDES E VARS GLOBAIS =======
//===============================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>
#include <assert.h>
#include <windows.h>
//===============================================================
//==============         VARIAVEIS GLOBAIS         ==============
//===============================================================



//===============================================================
//==============              STRUCTS              ==============
//===============================================================
typedef struct dados_cadastrais 
{
    char nome[250];
    char CPF[20];
    int idade;
    char sexo[20];
    char email[250];
    char dt_nascimento[20];
}cadastro;
//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==================== PROTOTIPOS ===============================
//===============================================================
void limpa_tl();
void faca_cad ();
void mostrar_cad (char nome,int idade,char sexo,char CPF,char dt_nascimento,char email);


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
void faca_cad ()
{
    struct dados_cadastrais x;

    printf("\n Nome: ");
    fgets(x.nome,250,stdin);
    
    printf("\n Idade: ");
    scanf("%s", &x.idade);

    printf("\n Sexo: ");
    fgets(x.sexo,20,stdin);

    printf("\n CPF: ");
    fgets(x.CPF,20,stdin);
    
    printf("\n Data de nascimento: ");
    fgets(x.dt_nascimento,20,stdin);
    
    printf("\n E-mail: ");
    fgets(x.email,250,stdin);

    mostrar_cad(x.nome,x.idade,x.sexo,x.CPF,x.dt_nascimento,x.email);
}
//===============================================================
void mostrar_cad (char nome,int idade,char sexo,char CPF,char dt_nascimento,char email)
{
    printf("\n Nome:%s \n Idade:%d  \n Sexo:%s \n CPF:%s \nData de nascimento:%s \n E-mail:%s ");
}
//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    limpa_tl(); //Limpa a tela para uma melhor amostragem 

    faca_cad();


    //FINALIZAR PROGRAMA
    printf("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}