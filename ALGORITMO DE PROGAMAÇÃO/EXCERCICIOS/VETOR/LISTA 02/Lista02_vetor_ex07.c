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
#define TAM 10 // Vetor com 10 posições
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
void montarVetorAutomatico();

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================
void montarVetorAutomatico()
{
    //VARIAVEIS 
    int vetor[TAM];
    int i; // Contador para o laço

    // Variáveis para controlar os números a serem inseridos
    int numeroParAtual = 6;   // Começa em 6 para os índices pares
    int numeroImparAtual = 1; // Começa em 1 para os índices ímpares

    //=================================================
    // 1. ETAPA: MONTAR O VETOR AUTOMATICAMENTE
    //=================================================
    for (i = 0; i < TAM; i++)
    {
        // Se o ÍNDICE for par
        if (i % 2 == 0)
        {
            vetor[i] = numeroParAtual; // Recebe o número da sequência PAR (6 a 10)
            numeroParAtual++;          // Incrementa para o próximo número par
        }
        else // Se o ÍNDICE for ímpar
        {
            vetor[i] = numeroImparAtual; // Recebe o número da sequência ÍMPAR (1 a 5)
            numeroImparAtual++;          // Incrementa para o próximo número ímpar
        }
    }

    //=================================================
    // 2. ETAPA: MOSTRAR O RESULTADO
    //=================================================
    limpartl();
    printf("=========================================================\n");
    printf("         VETOR MONTADO SEGUINDO AS REGRAS DADAS          \n");
    printf("=========================================================\n\n");
    
    // Mostra o vetor final
    for (i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("\n\n=========================================================\n");
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // Definir a localização para Português para exibir acentos corretamente no console
    SetConsoleOutputCP(CP_UTF8);

    //CHAMAR A FUNÇÃO PRINCIPAL
    montarVetorAutomatico();
    
    //FINALIZAR PROGRAMA
    printf("\nFinalizando programa...\n");
    Sleep(1000);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}