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
#define tam 50
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
void pouse ();
void processar ();
void recebervt (int a[tam]);
void mostrarvt (int a[tam],int b[tam]);

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
void recebervt (int a[tam])
{
    int i=0;
    for(i=0;i<tam;i++)
    {
        printf("Informe o valor do vetor na pocicao [%d]...: ",i);
        fflush(stdin);
        scanf("%d",&a[i]);
    }
    processar();
}
//===============================================================
void mostrarvt (int a[tam],int b[tam])
{
    int i=0;
    printf("\nVetor A ...\n");
    for(i=0;i<tam;i++)
    {
        printf("%6d",a[i]);
        pouse();
    }
    printf("\nVetor B ...\n");
    for(i=0;i<tam;i++)
    {
        b[i] = a[i]  + 5;
        printf("%6d",b[i]);
        pouse();
    }
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int a[tam], b[tam];
    
    //INICIALIZAR VARIAVEIS
    limpartl();
    recebervt(a);
    mostrarvt(a,b);
    
    
    //FINALIZAR PROGRAMA
    printf("\n\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}