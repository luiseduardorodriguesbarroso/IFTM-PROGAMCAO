/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: 24/08/2025
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
#define tam 10

//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
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
        printf("%6d",vt[i]);
    }    
}
//===============================================================
void maior_vt(int vt[tam])
{
    int metade = tam / 2;
    int maior = vt[metade]; // Começa com o 21º valor como referência
    int i = metade + 1;
    for (i = i; i < tam; i++)
    {
        if (vt[i] > maior)
        {
            maior = vt[i];
        }
    }
    printf("\nO maior valor entre os %d ultimos e: %d\n",metade, maior);
}
//===============================================================
void menor_vt(int vt[tam])
{
    int i;
    int metade = tam / 2;
    int menor = vt[0]; // Começa com o primeiro valor como referência
    int limite = metade;   // Vamos comparar os 20 primeiros
    for (i = 1; i < limite; i++)
    {
        if (vt[i] < menor)
        {
            menor = vt[i];
        }
    }
    printf("\nO menor valor entre os %d primeiros e: %d\n", limite, menor);
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int vt[tam];
    
    //INICIALIZAR VARIAVEIS
    receber_vl(vt);
    mostra_vl(vt);
    maior_vt(vt);
    menor_vt(vt);

    //FINALIZAR PROGRAMA
    printf("\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}