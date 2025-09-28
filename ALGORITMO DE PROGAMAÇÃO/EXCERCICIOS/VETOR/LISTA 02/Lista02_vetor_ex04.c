/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: 28/09/2025
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
#define tam 3
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl();
void receber();
void processar();
void caregar();
void calculando();
void mostrarvt(int a[tam],int b[tam], int c[tam]);
//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================
void receber()
{
    //VARIAVEIS 
    int a[tam],b[tam],c[tam];
    //RECEBER VALORES 
    caregar();
    for (int i=0; i<tam;i++)   
    {
        printf("\nInforme o valor do vetor A [%d]",i);
        fflush(stdin);
        scanf("%d",&a[i]);
    }
    processar();
    for (int i=0; i<tam;i++) 
    {
        printf("\nInforme o valor do vetor B [%d]",i);
        fflush(stdin);
        scanf("%d",&b[i]);   
    }
    calculando();
    mostrarvt(a,b,c);
}
//===============================================================
void processar()
{
    limpartl();
    printf("Processando...");
    Sleep(950);
    limpartl();
}
//===============================================================
void caregar()
{
    limpartl();
    printf("Caregando...");
    Sleep(500);
    limpartl();
}
//===============================================================
void calculando ()
{
    limpartl();
    printf("Calculando o vetor C... ");
    Sleep(1000);
    limpartl();
}
//===============================================================
void mostrarvt(int a[tam],int b[tam], int c[tam])
{
    printf("\n----- Vetor A -----\n");
    for(int i=0;i<tam;i++)
    {
        printf("%5d",a[i]);
        Sleep(50);
    }
    printf("\n----- Vetor B -----\n");
    for(int i=0;i<tam;i++)
    {
        printf("%5d",b[i]);
        Sleep(50);
    }
    printf("\n----- Vetor C -----\n");
    for(int i=0;i<tam;i++)
    {
        c[i] = a[i] + b[i];
        printf("%5d",c[i]);
        Sleep(50);
    }
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CHAMANDO AS FUNÇÕES
    receber();

    //FINALIZAR PROGRAMA
    printf("\n\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}