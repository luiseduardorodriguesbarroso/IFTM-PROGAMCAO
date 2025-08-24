/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: 23/08/2025
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
#define tam 6 

//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
void pouse ();
void receber_vl (int vt[tam]);
void mostra_vl (int vt[tam]);
void maior_vt (int vt[tam]);
void menor_vt (int vt[tam]);

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================
void pouse ()
{
    sleep(200);//Pausa a tela por 0,2 segundos...
}
//===============================================================
void receber_vl (int vt[tam])
{
    int i=0;
    limpartl();
    for (i=0;i<tam;i++)
    {
        printf("\nInforme o valor do vetor na posicao [%d]",i);
        fflush(stdin);
        scanf("%d",&vt[i]);
    }    
}
//===============================================================
void mostra_vl (int vt[tam])
{
    int i=0;
    limpartl();
    printf("\nTodos os valores do vetor informadas...\n");
    for (i=0;i<tam;i++)
    {
        print("%6d",vt[i]);
        pouse();
    }    
}
//===============================================================
void maior_vt (int vt[tam])
{
    
}
//===============================================================
void menor_vt (int vt[tam])
{
    
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int vt[tam];
    
    //INICIALIZAR VARIAVEIS
    
    
    
    //FINALIZAR PROGRAMA
    printf("\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}