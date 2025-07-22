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
void procesar ();
void fim();
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
void procesar ()
{
    limpatl();
    printf("\nEstamos processando os dados informados...\n");
    Sleep(1000);
    limpatl();
    printf("\n\n\nAguarde...\n\n");
    Sleep(1500);
    limpatl();
    printf("\n\nProcessamento concluido!");
    Sleep(1000);
}
//==========================
void fim()
{
    limpatl();
    printf("\nFinalizando o progama...");
    Sleep(800); //pausa a tela por 800 milegundos...
    printf("\n\nAcabou...Tchau...Obrigado...\n\n");
}
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

    printf("\nInforme seu sexo F (Feminino) M (Masculino) ...: ");
    fflush(stdin);
    gets(sexo);

    printf("\nInforme seu peso ...: ");
    fflush(stdin);
    scanf("%f", &peso);

    //PROSESAR DADOS 
    procesar();

    //FIM DO PROGAMA
    fim();
    return 0;
}