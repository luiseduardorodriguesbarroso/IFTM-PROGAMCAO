/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: 08/08/2025
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
#define tam 5
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
void pouse ();
void processar ();




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
void processar ()
{
    limpartl();
    printf("\nProcessando os dados obtidos... \n\n");
    Sleep(850);
    limpartl();

}
//===============================================================
void recebervt (int a[tam],int b[tam])
{
    int i=0;
    printf("\nInforme o valor do vetor A... \n");
    for(i=0;i<tam;i++)
    {
        printf("Informe o valor do vetor na pocicao [%d]...: ",i);
        fflush(stdin);
        scanf("%d",&a[i]);
    }
    processar();    //carrega mensagem de processamento de dados...
    printf("\nInforme os valores do vetor B....\n");
    for(i=0;i<tam;i++)
    {
        printf("Informe o valor do vetor na pocicao [%d]...: ",i);
        fflush(stdin);
        scanf("%d",&b[i]);
    }
}
//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int a[tam], b[tam],c[tam];
    
    //INICIALIZAR VARIAVEIS
    
    
    
    //FINALIZAR PROGRAMA
    printf("\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}