/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    DATA: 06/08/2025
*/
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
//============== LOCAL PARA DECLARAR OS PROTÓTIPOS ==============
//===============================================================
void limpartl();
void recebervl(int vt[TAM]);
void mostrarvl(int vt[TAM]);

//===============================================================
//========== LOCAL PARA CRIAR OS MÓDULOS DAS FUNÇÕES ============
//===============================================================
void limpartl()
{
    system("cls"); // Limpa a tela no Windows
}

//---------------------------------------------------------------
void recebervl(int vt[TAM])
{
    int i;
    for(i = 0; i < TAM; i++)
    {
        printf("\nInforme o valor do vetor na posicao [%d]...: ", i);
        scanf("%d", &vt[i]);
    }
}

//---------------------------------------------------------------
void mostrarvl(int vt[TAM])
{
    int i;
    printf("\nValores armazenados no vetor:\n\n");
    for(i = 0; i < TAM; i++)
    {
        printf("Posicao [%d] = %d\n", i, vt[i]);
    }
}

//===============================================================
//==================== CÓDIGO PRINCIPAL =========================
//===============================================================
int main()
{
    //====== DECLARAR VARIÁVEIS ======
    int vt[TAM];

    //====== RECEBER E MOSTRAR VALORES ======
    limpartl();
    recebervl(vt);
    limpartl();
    mostrarvl(vt);
    
    //====== FINALIZAR PROGRAMA ======
    printf("\n\nFinalizando programa...\n");
    Sleep(500); // pausa de 0,5s
    printf("\n\nAcabou... Tchau... Obrigado...\n\n");
    return 0;
}