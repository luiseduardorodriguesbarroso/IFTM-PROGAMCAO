/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: 29/08/2025
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
void receber_vt (int vt[tam]);



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
    Sleep(200);
}
//===============================================================
void receber_vt (int vt[tam])
{
    int i;
    for (i=0;i<tam;i++)
    {
        printf("\nInforme o valor do vetor na posicao[%d]: ",i);
        fflush(stdin);
        scanf("%d", &vt[i]);
    }
    limpartl();
    printf("\n\nValor Informado dos vetores...\n");//mostra os valores informado acima do meu vt...
    pouse();//pausa de 200 milísegundos...
    for (i=0;i<tam;i++)//vai corer o meu vt mostrarndo todos os seus valores recebidos...
    {
        printf("%6d",vt[i]);
    }
}
//===============================================================
void comparar (int vt[tam])
{
    int i = 0,maior = 0,menor = 0;
    for (i=0;i<tam;i++)
    {
        
    } 
    for (i=0;i<tam;i++)
    {

    }
}
//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int vt[tam];
    
    //INICIALIZAR VARIAVEIS
    receber_vt(vt);
    
    
    //FINALIZAR PROGRAMA
    printf("\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}