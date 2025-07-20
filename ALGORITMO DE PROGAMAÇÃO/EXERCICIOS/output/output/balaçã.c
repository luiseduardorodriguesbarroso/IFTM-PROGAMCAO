#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
//==========================
void limpatl();
void pouse();
//==========================
void limpatl()
{
    system("cls");
}
//==========================
void pouse()
{
    Sleep(200);
}
//==========================

//==========================

//==========================

//==========================

//==========================

//==========================
int main ()
{
    limpatl();
    //VARIAVEIS 
    int idade;
    char sexo[20],nome[80];
    float peso;

    //RECEBER DADOS 
    printf("\n          SEJA BEM VINDO AO PROGAMA SAUDE +          \n");

    printf("\nInforme seu nome ...: ");
    fflush(stdin);
    gets(nome);
    
    printf("\nInforme sua idade ...:");
    fflush(stdin);
    scanf("%d", &idade);

    printf("\nInforme seu sexo (Masculino ou Feminino) ...: ");
    fflush(stdin);
    gets(sexo);

    printf("\nInforme seu peso ...: ");
    fflush(stdin);
    scanf("%f", &peso);

    //PROSESAR DADOS 
    

    //FIM DO PROGAMA
    limpatl();
    printf("\nFinalizando o progama...");
    Sleep(800); //pausa a tela por 800 milegundos...
    printf("\n\nAcabou...Tchau...Obrigado...\n\n");
    return 0;
}