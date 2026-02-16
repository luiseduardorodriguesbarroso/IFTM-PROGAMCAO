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
float lerfloat();
float tranformador_de_temperatura(float x);
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
float lerfloat()
{
    float numero;
    fgets(vt,255,stdin);
    sscanf(vt,"%f",&numero);
    return numero;
}
//===============================================================
float tranformador_de_temperatura(float x)
{
    float Fahrenheit;
    //Tranformando graus celcius em Fahrenheit
    Fahrenheit = ((x * 1.8) +32);
    return Fahrenheit;
}
//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    limpa_tl();
    //CRIAR VARIAVEIS
    float x;
    //INICIALIZAR VARIAVEIS
    printf("\n Informe a temperatura...: ");
    x = lerfloat();

    //MOSTRAR RESSULTADO 
    printf("\n\n A temperatura em Fahrenheit e: %.2f ",tranformador_de_temperatura(x));
    //FINALIZAR PROGRAMA
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}