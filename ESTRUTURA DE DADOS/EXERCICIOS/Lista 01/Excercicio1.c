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
int lerint ();
void vrfc_primo(int x);

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
int lerint ()
{
    int numero;
    fgets(vt, 255, stdin);
    sscanf(vt,"%d",&numero);
    return numero;
}
//===============================================================
void vrfc_primo(int x)
{
    int eh_primo = 1; // 1 significa VERDADEIRO (assumimos que é primo)

    if (x <= 1) 
    {
        eh_primo = 0; // 0 e 1 não são primos
    }
    else 
    {
        for (int i = 2; i <= x / 2; i++) 
        {
            if (x % i == 0) // Se achar UM divisor, já não é primo
            {
                eh_primo = 0;
                break; // Para o loop
            }
        }
    }
    if (eh_primo == 1)
    {
        printf("\n %d e primo ", x); 
    }
    else
    {
        printf("\n %d nao e primo ", x); 
    }
}
//===============================================================

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
    printf("\n Informe um numero...: ");
    x = lerint();

    vrfc_primo(x);
   
    //FINALIZAR PROGRAMA
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}