/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    3º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2026
    Prof. Rafael Orbolato
    Data: 00/00/0000
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
typedef struct cadastro
{
    char nome[255];
    int idade;
    char sexo[50];
    char cpf[15];
    float altura;

} cadastro;
//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==================== PROTOTIPOS ===============================
//===============================================================
void limpa_tl();
void cadastroluiz ();
void mostarcadastro (char nome[255],int idade,char cpf[15],char sexo[50], float altura);


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
void cadastroluiz ()
{
    cadastro luiz; //Cadastro teste do Luiz
    luiz.idade = 19;
    luiz.altura = 1.85;
    strcpy(luiz.cpf,"123.456.789-10");
    strcpy(luiz.sexo,"Masculino");
    strcpy(luiz.nome, "Luis Henrique Leao Camargo");

    cadastro camila; //Cadastro teste da Camila
    camila.idade = 29;
    camila.altura = 1.65;
    strcpy(camila.cpf,"735.456.000-37");
    strcpy(camila.sexo, "Femenino");
    strcpy(camila.nome,"Camila Alves Jardin Santos");

    mostarcadastro(luiz.nome,luiz.idade,luiz.sexo,luiz.cpf,luiz.altura); //Mostra o cadastro do Luiz
    mostarcadastro(camila.nome,camila.idade,camila.sexo,camila.cpf,camila.altura); //Mostra o cadastro da Camila 
}
//===============================================================
void mostarcadastro (char nome[255],int idade,char cpf[15],char sexo[50], float altura)
{
    printf("\nNome:%s \nIdade:%d \nSexo:%s \nCPF:%s \nAltura:%.2fcm\n",nome,idade,sexo,cpf,altura);
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
    cadastroluiz(); 

    //FINALIZAR PROGRAMA
    printf("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}