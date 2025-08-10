/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: 09/08/2025
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
void processar ();
void pouse ();
receber_nomes (char aluno[tam]);


//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
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
void pouse ()
{
    Sleep(200);
}
//===============================================================
receber_nomes (char aluno[tam])
{
    int i=0;
    for(i=0;i<tam;i++)
    {
        printf("\nInforme o nome do aluno [%d] ...: ",i);
        fflush(stdin);
        gets(aluno);
    }
}
//===============================================================
void receber_notas (int n1[tam],int n2[tam],int n3[tam],int n4[tam],int md[tam],char aluno[tam])
{
    
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int n1[tam],n2[tam],n3[tam],n4[tam],md[tam]; //TODOS MEUS VETORES 
    char aluno[tam];
    //INICIALIZAR VARIAVEIS
    
    
    
    //FINALIZAR PROGRAMA
    printf("\n\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}