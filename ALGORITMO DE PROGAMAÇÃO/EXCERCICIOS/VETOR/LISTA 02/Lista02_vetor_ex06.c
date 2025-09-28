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
#define TAM 15 // Vetor com 15 posições
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
void processarIndicesParImpar();

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================
void processarIndicesParImpar()
{
    //VARIAVEIS 
    int vetor[TAM];
    int i; // Contador para os laços
    
    // Variável para somar elementos de índice PAR (inicia em 0)
    int somaPares = 0; 
    
    // Variável para multiplicar elementos de índice ÍMPAR (inicia em 1)
    // Usamos long long para garantir que o resultado da multiplicação não exceda o limite
    long long int produtoImpares = 1;

    //=================================================
    // 1. ETAPA: RECEBER DADOS PARA O VETOR
    //=================================================
    printf("======================================\n");
    printf(" PREENCHIMENTO DO VETOR (15 POSICOES) \n");
    printf("======================================\n\n");
    for(i = 0; i < TAM; i++)
    {
        printf("Digite o valor para a posicao [%d de %d]: ", i + 1, TAM);
        scanf("%d", &vetor[i]);
    }

    //=================================================
    // 2. ETAPA: PROCESSAR E MOSTRAR OS RESULTADOS
    //=================================================
    limpartl();
    printf("=========================================================\n");
    printf("           ANALISE DO VETOR POR INDICES                  \n");
    printf("=========================================================\n\n");

    // a) Mostrar o vetor inicial
    printf("a) Vetor Inicial Completo:\n");
    for (i = 0; i < TAM; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n\n---------------------------------------------------------\n\n");

    // b) Elementos de índice PAR e sua SOMA
    printf("b) Elementos em indices PARES (0, 2, 4, ...):\n");
    for (i = 0; i < TAM; i++)
    {
        if (i % 2 == 0) // Se o ÍNDICE for par
        {
            printf("%d ", vetor[i]);
            somaPares += vetor[i]; // Acumula o valor na soma
        }
    }
    printf("\n\n> SOMA dos elementos em indices pares: %d\n", somaPares);
    printf("\n---------------------------------------------------------\n\n");

    // c) Elementos de índice ÍMPAR e seu PRODUTO
    printf("c) Elementos em indices IMPARES (1, 3, 5, ...):\n");
    int contadorImpares = 0; // Para saber se algum elemento foi processado
    for (i = 0; i < TAM; i++)
    {
        if (i % 2 != 0) // Se o ÍNDICE for ímpar
        {
            printf("%d ", vetor[i]);
            produtoImpares *= vetor[i]; // Acumula o valor no produto
            contadorImpares++;
        }
    }
    
    // Mostra o resultado do produto
    if (contadorImpares > 0)
    {
        // Usa %lld para imprimir um long long int
        printf("\n\n> PRODUTO dos elementos em indices impares: %lld\n", produtoImpares);
    }
    else
    {
        printf("\n\n> Nao existem elementos em indices impares para calcular o produto.\n");
    }

    printf("\n=========================================================\n");
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // Definir a localização para Português para exibir acentos corretamente no console
    SetConsoleOutputCP(CP_UTF8);

    //CHAMAR A FUNÇÃO PRINCIPAL
    processarIndicesParImpar();
    
    //FINALIZAR PROGRAMA
    printf("\nFinalizando programa...\n");
    Sleep(1000);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}