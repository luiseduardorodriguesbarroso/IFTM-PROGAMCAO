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
#define TAM 50 // Alterado para 50 posições, conforme solicitado
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
void processarDados();

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDulos DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================
void processarDados()
{
    //VARIAVEIS 
    char nomes[TAM][80]; // Vetor para 50 nomes de até 79 caracteres
    int idades[TAM];     // Vetor para 50 idades
    int maiorIdade = -1; // Variável para guardar a maior idade encontrada. Inicia com -1.
    int i; // Contador para os laços

    //=================================================
    // 1. ETAPA: RECEBER DADOS DO USUÁRIO
    //=================================================
    for(i = 0; i < TAM; i++)
    {
        printf("\n======================================\n");
        printf("Informe o nome da pessoa [%d de %d]...: ", i + 1, TAM);
        
        // fflush(stdin) é dependente de sistema (Windows), mas mantido para similaridade.
        fflush(stdin); 
        // Correção: scanf para string não precisa do '&' e lê até o primeiro espaço.
        scanf("%s", nomes[i]);

        // Laço para garantir que a idade seja válida
        do
        {
            printf("Informe a idade de %s ..............: ", nomes[i]);
            fflush(stdin);
            scanf("%d", &idades[i]);

            if (idades[i] < 0)
            {
                printf("\nERRO: Idade invalida! Por favor, informe um valor maior ou igual a zero.\n");
            }
        } 
        while (idades[i] < 0); // Repete enquanto a idade for inválida
    }

    //=================================================
    // 2. ETAPA: PROCESSAR E ENCONTRAR A MAIOR IDADE
    //=================================================
    for (i = 0; i < TAM; i++)
    {
        if (idades[i] > maiorIdade)
        {
            maiorIdade = idades[i];
        }
    }

    //=================================================
    // 3. ETAPA: MOSTRAR OS RESULTADOS
    //=================================================
    limpartl();
    printf("=========================================================\n");
    printf("           RESULTADO DA PESQUISA DE IDADE                \n");
    printf("=========================================================\n\n");
    
    // Verifica se alguma idade foi inserida (caso TAM > 0)
    if (maiorIdade != -1)
    {
        printf("A maior idade encontrada foi: %d anos.\n", maiorIdade);
        printf("Pessoa(s) com essa idade:\n");

        for (i = 0; i < TAM; i++)
        {
            if (idades[i] == maiorIdade)
            {
                printf(" -> %s\n", nomes[i]);
            }
        }
    }
    else
    {
        printf("Nenhum dado foi inserido para processar.\n");
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
    processarDados();
    
    //FINALIZAR PROGRAMA
    printf("\nFinalizando programa...\n");
    Sleep(1000);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}