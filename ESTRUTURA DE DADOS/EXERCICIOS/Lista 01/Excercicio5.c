/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    2 SEMESTRE 2025
    Prof. Rafael Orbolato
    Data: 17/02/2026
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
int lerint();
float TansformarFahrenheit(float x);
float TansformarCelsius(float y);
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
int lerint()
{
    int numero;
    fgets(vt,255,stdin);
    sscanf(vt,"%d",&numero);
    return numero;
}
//===============================================================
float TansformarFahrenheit(float x)
{
    float Fahrenheit;
    Fahrenheit = ((x * 1.8 )+ 32);
    return Fahrenheit;
}
//===============================================================
float TansformarCelsius(float x)
{
    float celsius;
    celsius = (x - 32)*(5.0/9.0);
    return celsius;
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    limpa_tl();
    //CRIAR VARIAVEIS
    int opc = -1;
    float x,y;

    //INICIALIZAR VARIAVEIS
    while (opc != 0 && opc != 1)
    {
        printf("\n\n------------ MENU PRINCIPAL ------------");
        printf("\n 0- Usar a formula de Celsius para Fahrenheit");
        printf("\n 1- Usar a formula de Fahrenheit para Celsius");
        printf("\n Informe qual opcao deseja usar (0 ou 1)...: ");
        opc = lerint();

        if (opc > 1 || opc < 0)
        {
            limpa_tl();
            printf("\n Informe uma das opcoes do menu principal...\n");
        }
        else if (opc == 0)
        {
            limpa_tl();
            printf("\n Informe a temperatura...: ");
            x = lerfloat();

            printf("\n\n A temperatura em Fahrenheit e: %.2f", TansformarFahrenheit(x));
        } 
        else
        {
            limpa_tl();
            printf("\n Informe a temperatura...: ");
            x = lerfloat();

            printf("\n\n A temperatura em Celsius e: %.2f",TansformarCelsius(x));
        }  
    }
    

    //FINALIZAR PROGRAMA
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}