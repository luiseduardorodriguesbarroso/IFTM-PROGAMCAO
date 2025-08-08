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
#define tam 20
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
void recebervl_ab (int a[tam],int b[tam]);
void mostrarvt_ab (int a[tam], int b[tam]);
void vt_c (int a[tam], int b[tam], int c[tam]);
void pouse();
void processo ();
//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================
void recebervl_ab (int a[tam],int b[tam])
{
    int i=0;
    printf("\nInforme os valores do vetor a: \n\n");
    for(i=0;i<tam;i++)
    {
        printf("Informe o valor do vetor na posicao [%d]...: ",i);
        fflush(stdin);
        scanf("%d",&a[i]);
    }
    processo();
    printf("\nInforme os valores do vetor B: \n\n");
    for(i=0;i<tam;i++)
    {
        printf("Informe o valor do vetor na posicao [%d]...: ",i);
        fflush(stdin);
        scanf("%d",&b[i]);
    }
    processo();
}
//===============================================================
void mostrarvt_ab (int a[tam], int b[tam])
{
    int i=0;
    printf("\nvetor A...:\n"); 
    pouse();
    for(i=0;i<tam;i++)
    {
        printf("%6d",a[i]);
    }
    printf("\nvetor B...:\n");
    pouse();
    for(i=0;i<tam;i++)
    {
        printf("%6d",b[i]);
    }
}
//===============================================================
void vt_c (int a[tam], int b[tam], int c[tam])
{
    printf("\nVetor C...:\n");
    pouse();
    int i=0;
    for(i=0;i<tam;i++)
    {
        c[i] = a[i] + b[i];
        printf("%6d",c[i]);
    }
}
//===============================================================
void pouse ()
{
    Sleep(200);
}
//===============================================================
void processo ()
{
    limpartl();
    printf("\n\nProcessando dados...\n\n");
    Sleep(750);
    limpartl();
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int a[tam],b[tam],c[tam];
    
    //INICIALIZAR VARIAVEIS
    limpartl();
    recebervl_ab(a,b);
    limpartl();
    mostrarvt_ab(a,b);
    vt_c(a,b,c);
    
    
    //FINALIZAR PROGRAMA
    printf("\n\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}