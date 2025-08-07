/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: 06/08/2025
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
#include <windows.h>
#define TAM 10
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();





//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================
void recebervl (int vt [TAM],int i)
{
    for(i=0;i<TAM;i++);
    {
        printf("\nInforme o valor do vetor na posicao[%d]...: ",i);
        fflush(stdin);
        scanf("%d",&vt[i]);
    }
}
//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int vt[TAM];
    int i;
    //INICIALIZAR VARIAVEIS
    
    
    
    //FINALIZAR PROGRAMA
    limpartl();
    printf("\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}
