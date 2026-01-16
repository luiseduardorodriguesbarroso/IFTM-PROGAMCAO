/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    Data: 15/01/2026
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
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDulos DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================
int main()
{
    limpartl(); // Limpa a tela para melhorar a amostragem do codigo

    //VARIAVEIS 
    int v1[10], v2[5]; // Meus 2 vetores para receber valores 
    int i, j; // i e j para ser minha forma de movimentar dendro dos vetores
    
    // R1 e R2 precisam ser vetores para guardar varios resultados, nao so um numero
    int R1[10], R2[10]; 
    
    // Variaveis para controlar a posicao dentro de R1 e R2
    int posR1 = 0; 
    int posR2 = 0;

    //RECEBENDO OS VALORES DOS VETORES 
    printf("\n--- PREENCHENDO VETOR V1 ---\n");
    for(i=0;i<10;i++)
    {
        printf("Informe o valor do vetor V1 na posicao [%d]...: ",i);
        fflush(stdin);
        scanf("%d",&v1[i]); // Corrigido: precisa do [i] para saber onde guardar

    }
    printf("\n--- PREENCHENDO VETOR V2 ---\n");
    for(i=0;i<5;i++)
    {
        printf("Informe o valor do vetor V2 na posicao [%d]...: ",i);
        fflush(stdin);
        scanf("%d",&v2[i]); // Corrigido: precisa do [i] aqui tambem

    }    
    
    //Calculando a soma de V2 para usar no calculo de R1...
    int soma = 0; //Res vai ser = a soma de tdos os valores do vetor V2 
    for(i=0;i<5;i++)
    {
        soma = soma + v2[i];
    }

    // PROCESSANDO OS DADOS
    // Percorrendo o vetor V1 para ver quem e par e quem e impar
    for (i=0;i<10;i++)
    {
        // Se for PAR vai para o R1
        if(v1[i] % 2 == 0)
        {
            R1[posR1] = v1[i] + soma;
            posR1++; // Pula para a proxima casa do vetor R1
        }
        // Se for IMPAR vai para o R2
        else 
        {
            // A regra do R2 e contar quantos divisores tem no V2
            int contDiv = 0;
            // Vou percorrer o V2 todo para testar a divisao
            for(j=0; j<5; j++)
            {
                // Verifica se o numero do V1 divide pelo do V2
                if (v2[j] != 0 && v1[i] % v2[j] == 0)
                {
                    contDiv++;
                }
            }
            R2[posR2] = contDiv;
            posR2++; // Pula para a proxima casa do vetor R2
        }
    }

    // MOSTRANDO OS RESULTADOS FINAIS
    printf("\n\n================ RESULTADOS ================\n");
    
    printf("Vetor R1 (Resultante dos Pares): ");
    for(i=0; i<posR1; i++)
    {
        printf("[%d] ", R1[i]);
    }

    printf("\n\nVetor R2 (Resultante dos Impares): ");
    for(i=0; i<posR2; i++)
    {
        printf("[%d] ", R2[i]);
    }
}