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
float transformarFahrenheit(float x);
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
float transformarFahrenheit(float x)
{
    float celsius;
    celsius = (x-32)*(5.0/9.0);//5.0 e 9.0 pq em c quando vc divide 2 inteiros  o computador entende que o resultado tem que ser inteiro tambem e ele iguinora o resto 
    return celsius;
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
    printf("\n Informe a temperatura em Fahrenheit...: ");
    x = lerfloat();

    //Mostrar ressultado
    printf("\n\n A temperatura em graus celsius e: %.2f",transformarFahrenheit(x));

    //FINALIZAR PROGRAMA
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}