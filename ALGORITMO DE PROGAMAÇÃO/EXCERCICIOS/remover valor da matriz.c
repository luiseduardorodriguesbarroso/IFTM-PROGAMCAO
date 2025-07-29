/*==============================================================
    CURSO: ENGENHARIA DE COMPUTACAO
    Nome: LUÍS EDUARDO RODRIGUES BARROSO
    1° PERIODO - ALGORITMO DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    Data: 03/06/2025
*/
//===============================================================
//======== LOCAL PARA DECLARAR AS INCLUDES E VARS GLOBAIS =======
//===============================================================

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpatl ();
void carregar ();
void finalizar ();

//===============================================================
void carregar ()
{
    limpatl();
    printf("\n\n\nCaregando.... \n\n");
    Sleep(1500); //pouse de 1,5 segundos...
    limpatl();
}
//===============================================================
void limpatl ()
{
    system("cls");
}
//===============================================================
void finalizar ()
{
    printf("\n\nAcabou...Tchau...Obriado... \n\n");
}
//===============================================================
//===============================================================
int main()
{
    int opc;

    while(opc == 3)
    {
        printf("\n---------- MENU PRINCIPAL ----------");
        printf("\n1- Remover valor da matriz... ");
        printf("\n2 Adicionar valor na matriz... ");
        printf("\n3- Finalizar progama... ");
        printf("\nINfrome uma das opcoes do menu acima ...: ");
        fflush(stdin);
        scanf("%d",&opc);

        if(opc > 3 || opc < 1)
        {
            carregar();
            printf("\nErro! inaforme uma das opcoes do menu ...\n\n");
        }  else if (opc == 3)
        {
            carregar();
            finalizar();
        }  else if (opc == 1)
        {
            
        } 
    }
}