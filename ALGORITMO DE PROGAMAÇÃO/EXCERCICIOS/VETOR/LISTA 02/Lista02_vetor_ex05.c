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
#define TAM 20 // Vetor A com 20 posições
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
void separarVetoresParesImpares();

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================
void separarVetoresParesImpares()
{
    //VARIAVEIS 
    int vetorA[TAM];
    int vetorB[TAM]; // No pior caso, todos os 20 números são pares
    int vetorC[TAM]; // No pior caso, todos os 20 números são ímpares

    int contadorB = 0; // Contador para a próxima posição livre no vetor B
    int contadorC = 0; // Contador para a próxima posição livre no vetor C
    int i; // Contador para os laços

    //=================================================
    // 1. ETAPA: RECEBER DADOS PARA O VETOR A
    //=================================================
    printf("======================================\n");
    printf("   PREENCHIMENTO DO VETOR A (20 POSICOES)   \n");
    printf("======================================\n\n");
    for(i = 0; i < TAM; i++)
    {
        printf("Digite o valor para a posicao [%d de %d]: ", i + 1, TAM);
        scanf("%d", &vetorA[i]);
    }

    //=================================================
    // 2. ETAPA: PROCESSAR O VETOR A E GERAR B E C
    //=================================================
    for (i = 0; i < TAM; i++)
    {
        // Verifica se o número é par
        if (vetorA[i] % 2 == 0)
        {
            vetorB[contadorB] = vetorA[i]; // Adiciona o par ao vetor B
            contadorB++;                   // Incrementa o contador de pares
        }
        else // Se não for par, é ímpar
        {
            vetorC[contadorC] = vetorA[i]; // Adiciona o ímpar ao vetor C
            contadorC++;                   // Incrementa o contador de ímpares
        }
    }

    //=================================================
    // 3. ETAPA: MOSTRAR OS RESULTADOS
    //=================================================
    limpartl();
    printf("=========================================================\n");
    printf("           RESULTADO DA SEPARACAO DOS VETORES            \n");
    printf("=========================================================\n\n");
    
    // Mostra o Vetor A (Original)
    printf("--- Vetor Original (A) ---\n");
    for (i = 0; i < TAM; i++)
    {
        printf("%d ", vetorA[i]);
    }
    printf("\n\n");

    // Mostra o Vetor B (Pares)
    printf("--- Vetor de Pares (B) ---\n");
    if (contadorB > 0) // Verifica se houve alguma ocorrência de pares
    {
        for (i = 0; i < contadorB; i++)
        {
            printf("%d ", vetorB[i]);
        }
    }
    else
    {
        printf("NAO houve ocorrencia de numeros pares.\n");
    }
    printf("\n\n");

    // Mostra o Vetor C (Ímpares)
    printf("--- Vetor de Impares (C) ---\n");
    if (contadorC > 0) // Verifica se houve alguma ocorrência de ímpares
    {
        for (i = 0; i < contadorC; i++)
        {
            printf("%d ", vetorC[i]);
        }
    }
    else
    {
        printf("NAO houve ocorrencia de numeros impares.\n");
    }
    printf("\n\n");
    printf("=========================================================\n");
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // Definir a localização para Português para exibir acentos corretamente no console
    SetConsoleOutputCP(CP_UTF8);

    //CHAMAR A FUNÇÃO PRINCIPAL
    separarVetoresParesImpares();
    
    //FINALIZAR PROGRAMA
    printf("\nFinalizando programa...\n");
    Sleep(1000);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}