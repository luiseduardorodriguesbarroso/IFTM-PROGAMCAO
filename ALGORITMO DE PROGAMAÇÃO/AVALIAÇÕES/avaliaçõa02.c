/*===================================
NOME: lUÍS EDUARDO RODRIGUES BARROSO
CURSO:  ENGENHARIA DA COMPUTAÇÃO
CPF:    705.916.916-47
DATA:   03/06/2025
===================================*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>

//========================================
// DECLARAÇÃO DAS FUNÇÕES
//========================================
void menu();
void deposito(float *saldo, float *total_depositos, int *qtd_depositos, int dia_atual);
void retirada(float *saldo, float *total_retiradas, int *qtd_retiradas, int dia_atual);
void relatorio_saldo(float saldo);
void relatorio_extrato();
int validar_dia(int dia_atual);
void limpar_buffer();

//========================================

#define MAX_TRANSACOES 100

typedef struct
{
    int dia;
    char descricao[20];
    char status; // 'C' para crédito, 'D' para débito
    float valor;
    float saldo_apos;
} Transacao;

Transacao transacoes[MAX_TRANSACOES];
int qtd_transacoes = 0;

//========================================
// FUNÇÃO PRINCIPAL
//========================================
int main()
{
    int opc = 0;
    float saldo = 0, total_depositos = 0, total_retiradas = 0;
    int qtd_depositos = 0, qtd_retiradas = 0;
    int dia_atual = 5; // Exemplo: supondo que hoje seja dia 5

    while (opc != 5)
    {
        menu();
        scanf("%d", &opc);
        limpar_buffer(); // Limpa o buffer após ler número

        switch (opc)
        {
            case 1:
                deposito(&saldo, &total_depositos, &qtd_depositos, dia_atual);
                break;
            case 2:
                retirada(&saldo, &total_retiradas, &qtd_retiradas, dia_atual);
                break;
            case 3:
                relatorio_saldo(saldo);
                break;
            case 4:
                relatorio_extrato();
                break;
            case 5:
                printf("\nFinalizando o programa...\n");
                Sleep(1000);
                break;
            default:
                printf("\n=====================================\n");
                printf("Opcao invalida! Tente novamente.\n");
                printf("=====================================\n");
                printf("Pressione qualquer tecla para continuar...");
                getch();
        }
    }

    system("cls");
    printf("\n\n=====================================\n");
    printf("Obrigado por utilizar o sistema bancario!\n");
    printf("=====================================\n\n");
    return 0;
}

//========================================
// IMPLEMENTAÇÃO DAS FUNÇÕES
//========================================

void menu()
{
    system("cls");
    printf("=====================================\n");
    printf("        TRANSACOES BANCARIAS         \n");
    printf("=====================================\n");
    printf(" 1) Deposito (entrada)\n");
    printf(" 2) Retiradas (saida)\n");
    printf(" 3) Relatorio saldo atual\n");
    printf(" 4) Relatorio Extrato do periodo do mes\n");
    printf(" 5) Finalizar\n");
    printf("=====================================\n");
    printf("Informe uma das opcoes (1, 2, 3, 4 ou 5): ");
}

void deposito(float *saldo, float *total_depositos, int *qtd_depositos, int dia_atual)
{
    int dia_informado = 0;
    char tipo_deposito[20];
    float valor;
    int tipo_valido = 0;

    system("cls");
    printf("=====================================\n");
    printf("         DEPOSITO (ENTRADA)          \n");
    printf("=====================================\n");

    // Validação do dia
    dia_informado = validar_dia(dia_atual);

    // Validação do tipo de depósito
    do {
        printf("Informe o tipo de deposito (dinheiro, pix): ");
        fgets(tipo_deposito, sizeof(tipo_deposito), stdin);
        tipo_deposito[strcspn(tipo_deposito, "\n")] = 0; // Remove o \n

        if (strcmp(tipo_deposito, "dinheiro") == 0 || strcmp(tipo_deposito, "pix") == 0) {
            tipo_valido = 1;
        } else {
            printf("Tipo invalido! Digite exatamente 'dinheiro' ou 'pix'.\n");
        }
    } while (!tipo_valido);

    printf("Informe o valor ...: ");
    scanf("%f", &valor);
    limpar_buffer(); // Limpa o buffer após ler número

    if (valor > 0)
    {
        *saldo += valor;
        *total_depositos += valor;
        (*qtd_depositos)++;
        // Salva transação
        if (qtd_transacoes < MAX_TRANSACOES) {
            transacoes[qtd_transacoes].dia = dia_informado;
            strcpy(transacoes[qtd_transacoes].descricao, tipo_deposito);
            transacoes[qtd_transacoes].status = 'C';
            transacoes[qtd_transacoes].valor = valor;
            transacoes[qtd_transacoes].saldo_apos = *saldo;
            qtd_transacoes++;
        }
        printf("\nAguarde .....\n");
        Sleep(1000);
        printf("Atualizando Sistema\n");
        Sleep(1000);
        printf("Deposito realizado com sucesso!\n");
    }
    else
    {
        printf("\nValor invalido!\n");
    }
    printf("\n=====================================\n");
    printf("Pressione qualquer tecla para voltar ao menu...");
    getch();
}

void retirada(float *saldo, float *total_retiradas, int *qtd_retiradas, int dia_atual)
{
    int dia_retirada;
    float valor;

    system("cls");
    printf("=====================================\n");
    printf("         RETIRADA (SAIDA)            \n");
    printf("=====================================\n");

    dia_retirada = validar_dia(dia_atual);

    printf("Informe o valor da retirada: ");
    scanf("%f", &valor);
    limpar_buffer(); // Limpa o buffer após ler número

    if (valor > 0 && valor <= *saldo)
    {
        *saldo -= valor;
        *total_retiradas += valor;
        (*qtd_retiradas)++;
        // Salva transação
        if (qtd_transacoes < MAX_TRANSACOES) 
        {
            transacoes[qtd_transacoes].dia = dia_retirada;
            strcpy(transacoes[qtd_transacoes].descricao, "saida");
            transacoes[qtd_transacoes].status = 'D';
            transacoes[qtd_transacoes].valor = valor;
            transacoes[qtd_transacoes].saldo_apos = *saldo;
            qtd_transacoes++;
        }
        printf("\nRetirada realizada com sucesso!\n");
    }
    else
    {
        printf("\nValor invalido ou saldo insuficiente!\n");
    }
    printf("\n=====================================\n");
    printf("Pressione qualquer tecla para continuar...");
    getch();
}

void relatorio_saldo(float saldo)
{
    system("cls");
    printf("=====================================\n");
    printf("         RELATORIO DE SALDO          \n");
    printf("=====================================\n");
    printf("SALDO ATUAL: R$ %.2f\n", saldo);
    printf("=====================================\n");
    printf("Pressione qualquer tecla para continuar...");
    getch();
}

void relatorio_extrato()
{
    system("cls");
    printf("=====================================\n");
    printf("   RELATORIO EXTRATO DO PERIODO      \n");
    printf("=====================================\n");
    printf("Extrato completo\n");
    printf("===============================================================\n");
    printf("Status: C - Credito (entrada)   D - Debito (saida)\n");
    printf("---------------------------------------------------------------\n");
    printf("dia  descricao      status  valor da transacao  saldo atual\n");
    printf("---------------------------------------------------------------\n");
    for (int i = 0; i < qtd_transacoes; i++)
    {
        printf("%-4d %-13s %-6c %18.2f %13.2f\n",
            transacoes[i].dia,
            transacoes[i].descricao,
            transacoes[i].status,
            transacoes[i].valor,
            transacoes[i].saldo_apos
        );
    }
    printf("===============================================================\n");
    printf("Pressione qualquer tecla para voltar ao menu ");
    getch();
}

int validar_dia(int dia_atual)
{
    int dia;
    do 
    {
        printf("Informe o dia da data de hoje: ");
        scanf("%d", &dia);
        limpar_buffer(); // Limpa o buffer após ler número
        if (dia < dia_atual) 
        {
            printf("A data nao pode ser anterior a data atual.\n");
            printf("Dia invalido ... informe outro ...: ");
        } else if (dia > 31 || dia < 1) 
        {
            printf("Dia invalido ... informe outro ...: ");
        }
    } while (dia < dia_atual || dia > 31 || dia < 1);
    return dia;
}

void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}