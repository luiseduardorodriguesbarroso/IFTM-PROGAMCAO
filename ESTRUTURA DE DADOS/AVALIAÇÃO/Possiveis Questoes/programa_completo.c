#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================================
// ESTRUTURAS DE DADOS (TAD PILHA E TAD FILA)
// ============================================================================

// --- NÓ GENÉRICO PARA FILA E PILHA ---
typedef struct No {
    int valor;
    struct No *prox;
} No;

// --- ESTRUTURA DA FILA ---
typedef struct Fila {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

// --- ESTRUTURA DA PILHA ---
typedef struct Pilha {
    No *topo;
    int tamanho;
} Pilha;

// ============================================================================
// PRIMITIVAS DO TAD FILA
// ============================================================================

Fila* criarFila(void) {
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para a Fila.\n");
        exit(1);
    }
    f->inicio = NULL;
    f->fim = NULL;
    f->tamanho = 0;
    return f;
}

int filaVazia(Fila *f) {
    return (f == NULL || f->inicio == NULL || f->tamanho == 0);
}

void enfileirar(Fila *f, int valor) {
    if (f == NULL) return;
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para No da Fila.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = NULL;
    if (f->inicio == NULL) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
    f->tamanho++;
}

int desenfileirar(Fila *f) {
    if (filaVazia(f)) {
        return -1;
    }
    No *remover = f->inicio;
    int valor = remover->valor;
    f->inicio = f->inicio->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(remover);
    f->tamanho--;
    return valor;
}

void destruirFila(Fila *f) {
    if (f == NULL) return;
    while (!filaVazia(f)) {
        desenfileirar(f);
    }
    free(f);
}

void mostrarFila(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia (tamanho = 0)\n");
        return;
    }
    printf("Fila (tam: %d): [Frente] ", f->tamanho);
    No *atual = f->inicio;
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf(" [Fim]\n");
}

// Primitivas para Fila de Caracteres
Fila* criarFilaChars(void) {
    return criarFila();
}

void destruirFilaChars(Fila *f) {
    destruirFila(f);
}

void enfileirarChar(Fila *f, char c) {
    enfileirar(f, (int)c);
}

char desenfileirarChar(Fila *f) {
    return (char)desenfileirar(f);
}

// ============================================================================
// PRIMITIVAS DO TAD PILHA
// ============================================================================

Pilha* criarPilha(void) {
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para a Pilha.\n");
        exit(1);
    }
    p->topo = NULL;
    p->tamanho = 0;
    return p;
}

int pilhaVazia(Pilha *p) {
    return (p == NULL || p->topo == NULL || p->tamanho == 0);
}

void push(Pilha *p, int valor) {
    if (p == NULL) return;
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para No da Pilha.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->tamanho++;
}

int pop(Pilha *p) {
    if (pilhaVazia(p)) {
        return -1;
    }
    No *remover = p->topo;
    int valor = remover->valor;
    p->topo = remover->prox;
    free(remover);
    p->tamanho--;
    return valor;
}

void destruirPilha(Pilha *p) {
    if (p == NULL) return;
    while (!pilhaVazia(p)) {
        pop(p);
    }
    free(p);
}

void mostrarPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia (tamanho = 0)\n");
        return;
    }
    printf("Pilha (tam: %d): [Topo] ", p->tamanho);
    No *atual = p->topo;
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf(" [Fundo]\n");
}

// Primitivas para Pilha de Caracteres
Pilha* criarPilhaChars(void) {
    return criarPilha();
}

void destruirPilhaChars(Pilha *p) {
    destruirPilha(p);
}

void pushChar(Pilha *p, char c) {
    push(p, (int)c);
}

char popChar(Pilha *p) {
    return (char)pop(p);
}

// ============================================================================
// QUESTÕES DE PROVA (1 a 10)
// ============================================================================

// QUESTÃO 1 (30%)
void inverterFila(Fila *pontFila)
{
    if (pontFila == NULL || filaVazia(pontFila)) {
        printf("Fila vazia ou nula, nada a inverter\n");
        return;
    }

    Pilha *pAux = criarPilha();
    
    while (!filaVazia(pontFila)) {
        int valor = desenfileirar(pontFila);
        push(pAux, valor);
    }

    while (!pilhaVazia(pAux)) {
        int valor = pop(pAux);
        enfileirar(pontFila, valor);
    }

    destruirPilha(pAux);
    printf("Fila invertida com sucesso!\n");
}

// QUESTÃO 2 (30%)
int removerOcorrenciasFila(int valor, Fila *pontFila)
{
    if (pontFila == NULL || filaVazia(pontFila)) {
        printf("Fila vazia, nenhum elemento removido\n");
        return 0;
    }

    Fila *fAux = criarFila();
    int qtdRemovidos = 0;

    while (!filaVazia(pontFila)) {
        int atual = desenfileirar(pontFila);
        
        if (atual == valor) {
            qtdRemovidos++;
        } else {
            enfileirar(fAux, atual);
        }
    }

    while (!filaVazia(fAux)) {
        enfileirar(pontFila, desenfileirar(fAux));
    }

    destruirFila(fAux);

    if (qtdRemovidos > 0) {
        printf("Foram removidas %d ocorrencia(s) do valor %d\n", qtdRemovidos, valor);
    } else {
        printf("O valor %d não foi encontrado na fila\n", valor);
    }
    
    return qtdRemovidos;
}

// QUESTÃO 3 (40%)
int ehPalindromoPilhaFila(char *palavra)
{
    if (palavra == NULL || palavra[0] == '\0') {
        printf("String vazia ou nula, NÃO é palíndromo\n");
        return 0;
    }

    if (palavra[1] == '\0') {
        printf("String com 1 único elemento É um palíndromo\n");
        return 1;
    }

    Pilha *pAux = criarPilhaChars(); 
    Fila *fAux = criarFilaChars();
    
    int i = 0;
    while (palavra[i] != '\0') {
        pushChar(pAux, palavra[i]);
        enfileirarChar(fAux, palavra[i]);
        i++;
    }

    int deucerto = 1;

    while (!pilhaVazia(pAux) && !filaVazia(fAux)) {
        char doTopo = popChar(pAux);
        char daFrente = desenfileirarChar(fAux);

        if (doTopo != daFrente) {
            deucerto = 0; 
            printf("A string NÃO é um palíndromo\n");
            break;
        }
    }

    while (!pilhaVazia(pAux)) {
        popChar(pAux);
    }
    while (!filaVazia(fAux)) {
        desenfileirarChar(fAux);
    }

    destruirPilhaChars(pAux);
    destruirFilaChars(fAux);

    if (deucerto == 1) {
        printf("A string é sim um palíndromo\n");
        return 1;
    }

    return 0;
}

// QUESTÃO 4 (20%)
Fila* extrairParesFila(Fila *pontFila)
{
    if (pontFila == NULL || filaVazia(pontFila)) {
        printf("Fila original vazia ou nula. Retornando NULL\n");
        return NULL;
    }

    Fila *filaPares = criarFila();
    Fila *filaAux = criarFila();

    while (!filaVazia(pontFila)) {
        int valor = desenfileirar(pontFila);
        
        if (valor % 2 == 0) {
            enfileirar(filaPares, valor);
        } else {
            enfileirar(filaAux, valor);
        }
    }

    while (!filaVazia(filaAux)) {
        enfileirar(pontFila, desenfileirar(filaAux));
    }

    destruirFila(filaAux);

    printf("Pares extraidos com sucesso!\n");
    return filaPares;
}

// QUESTÃO 5 (30%)
int verificaBalanceamentoExpressao(char *expressao)
{
    if (expressao == NULL || expressao[0] == '\0') {
        printf("Expressão vazia ou inválida\n");
        return 0;
    }

    Pilha *p = criarPilhaChars();
    int erro = 0;
    int i = 0;

    while (expressao[i] != '\0') {
        char c = expressao[i];

        if (c == '(' || c == '[' || c == '{') {
            pushChar(p, c);
        } 
        else if (c == ')' || c == ']' || c == '}') {
            if (pilhaVazia(p)) {
                erro = 1;
                break;
            }

            char topo = popChar(p);

            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                erro = 1;
                break;
            }
        }
        i++;
    }

    if (!pilhaVazia(p)) {
        erro = 1;
    }

    while (!pilhaVazia(p)) {
        popChar(p);
    }
    destruirPilhaChars(p);

    if (erro == 1) {
        printf("Expressão DESBALANCEADA (Erros encontrados)\n");
        return 0;
    } else {
        printf("Expressão PERFEITAMENTE BALANCEADA!\n");
        return 1;
    }
}

// QUESTÃO 6 (20%)
Fila* intercalarFilas(Fila *f1, Fila *f2)
{
    Fila *f3 = criarFila();

    if (f1 == NULL && f2 == NULL) {
        printf("Ambas as filas são nulas.\n");
        return f3;
    }

    while (!filaVazia(f1) || !filaVazia(f2)) {
        if (!filaVazia(f1)) {
            int valor1 = desenfileirar(f1);
            enfileirar(f3, valor1);
        }
        
        if (!filaVazia(f2)) {
            int valor2 = desenfileirar(f2);
            enfileirar(f3, valor2);
        }
    }

    printf("Filas intercaladas com sucesso!\n");
    return f3;
}

// QUESTÃO 7 (25%)
void ordenarPilha(Pilha *pOriginal)
{
    if (pOriginal == NULL || pilhaVazia(pOriginal)) {
        return;
    }

    Pilha *pAux = criarPilha();

    while (!pilhaVazia(pOriginal)) {
        int temporario = pop(pOriginal);

        while (!pilhaVazia(pAux)) {
            int valorAux = pop(pAux);
            
            if (valorAux > temporario) {
                push(pOriginal, valorAux);
            } else {
                push(pAux, valorAux);
                break;
            }
        }
        
        push(pAux, temporario);
    }

    while (!pilhaVazia(pAux)) {
        push(pOriginal, pop(pAux));
    }

    destruirPilha(pAux);
    printf("Pilha ordenada com sucesso!\n");
}

// QUESTÃO 8 (20%)
int removerFundoPilha(Pilha *pOriginal)
{
    if (pOriginal == NULL || pilhaVazia(pOriginal)) {
        printf("Erro: A pilha está vazia!\n");
        return -1;
    }

    Pilha *pAux = criarPilha();
    
    while (!pilhaVazia(pOriginal)) {
        push(pAux, pop(pOriginal));
    }

    int valorDoFundo = pop(pAux);

    while (!pilhaVazia(pAux)) {
        push(pOriginal, pop(pAux));
    }

    destruirPilha(pAux);
    
    printf("Valor do fundo removido: %d\n", valorDoFundo);
    return valorDoFundo;
}

// QUESTÃO 9 (20%)
void concatenarFilasO1(Fila *f1, Fila *f2)
{
    if (f2 == NULL || f2->inicio == NULL) {
        return; 
    }

    if (f1 == NULL) {
        return;
    }

    if (f1->inicio == NULL) {
        f1->inicio = f2->inicio;
        f1->fim = f2->fim;
    } 
    else {
        f1->fim->prox = f2->inicio;
        f1->fim = f2->fim;
    }

    f2->inicio = NULL;
    f2->fim = NULL;
    
    f1->tamanho += f2->tamanho;
    f2->tamanho = 0;
}

// QUESTÃO 10 (25%)
int saoPilhasIguais(Pilha *p1, Pilha *p2)
{
    if (p1 == NULL || p2 == NULL) return 0;

    Pilha *aux1 = criarPilha();
    Pilha *aux2 = criarPilha();
    int saoIguais = 1;

    while (!pilhaVazia(p1) && !pilhaVazia(p2)) {
        int v1 = pop(p1);
        int v2 = pop(p2);

        push(aux1, v1);
        push(aux2, v2);

        if (v1 != v2) {
            saoIguais = 0;
            break;
        }
    }

    if (!pilhaVazia(p1) || !pilhaVazia(p2)) {
        saoIguais = 0;
    }

    while (!pilhaVazia(aux1)) {
        push(p1, pop(aux1));
    }
    while (!pilhaVazia(aux2)) {
        push(p2, pop(aux2));
    }

    destruirPilha(aux1);
    destruirPilha(aux2);

    return saoIguais;
}

// ============================================================================
// BATERIA DE TESTES (MAIN)
// ============================================================================

void testarQuestao1() {
    printf("\n============================================================\n");
    printf("TESTE QUESTÃO 1: Inverter Fila usando Pilha auxiliar\n");
    printf("============================================================\n");
    Fila *f = criarFila();
    enfileirar(f, 10);
    enfileirar(f, 20);
    enfileirar(f, 30);
    enfileirar(f, 40);
    printf("Antes da inversão:\n  ");
    mostrarFila(f);

    inverterFila(f);
    printf("Depois da inversão:\n  ");
    mostrarFila(f);

    destruirFila(f);
}

void testarQuestao2() {
    printf("\n============================================================\n");
    printf("TESTE QUESTÃO 2: Remover Ocorrências na Fila\n");
    printf("============================================================\n");
    Fila *f = criarFila();
    enfileirar(f, 5);
    enfileirar(f, 10);
    enfileirar(f, 5);
    enfileirar(f, 20);
    enfileirar(f, 5);
    enfileirar(f, 30);
    printf("Fila original com valores 5:\n  ");
    mostrarFila(f);

    int removidos = removerOcorrenciasFila(5, f);
    printf("Total de remocoes retornadas: %d\n", removidos);
    printf("Fila apos remover ocorrencias de 5:\n  ");
    mostrarFila(f);

    destruirFila(f);
}

void testarQuestao3() {
    printf("\n============================================================\n");
    printf("TESTE QUESTÃO 3: Verificar Palíndromo com Pilha e Fila\n");
    printf("============================================================\n");
    char p1[] = "radar";
    char p2[] = "arara";
    char p3[] = "estrutura";
    char p4[] = "a";

    printf("Testando '%s': %s (retorno = %d)\n", p1, ehPalindromoPilhaFila(p1) ? "PALINDROMO" : "NAO PALINDROMO", ehPalindromoPilhaFila(p1));
    printf("Testando '%s': %s (retorno = %d)\n", p2, ehPalindromoPilhaFila(p2) ? "PALINDROMO" : "NAO PALINDROMO", ehPalindromoPilhaFila(p2));
    printf("Testando '%s': %s (retorno = %d)\n", p3, ehPalindromoPilhaFila(p3) ? "PALINDROMO" : "NAO PALINDROMO", ehPalindromoPilhaFila(p3));
    printf("Testando '%s': %s (retorno = %d)\n", p4, ehPalindromoPilhaFila(p4) ? "PALINDROMO" : "NAO PALINDROMO", ehPalindromoPilhaFila(p4));
}

void testarQuestao4() {
    printf("\n============================================================\n");
    printf("TESTE QUESTÃO 4: Extrair Pares da Fila\n");
    printf("============================================================\n");
    Fila *fOriginal = criarFila();
    enfileirar(fOriginal, 10);
    enfileirar(fOriginal, 15);
    enfileirar(fOriginal, 20);
    enfileirar(fOriginal, 7);
    enfileirar(fOriginal, 33);
    enfileirar(fOriginal, 42);

    printf("Fila original antes da extração:\n  ");
    mostrarFila(fOriginal);

    Fila *fPares = extrairParesFila(fOriginal);

    printf("Fila original apos extração (apenas ímpares mantidos):\n  ");
    mostrarFila(fOriginal);

    printf("Nova fila retornada (apenas pares extraídos):\n  ");
    mostrarFila(fPares);

    destruirFila(fOriginal);
    destruirFila(fPares);
}

void testarQuestao5() {
    printf("\n============================================================\n");
    printf("TESTE QUESTÃO 5: Balanceamento de Expressão com Pilha\n");
    printf("============================================================\n");
    char expr1[] = "{ [ ( ) ] }";
    char expr2[] = "{ [ ( ] ) }";
    char expr3[] = "((2 + 3) * [5 - {4 / 2}])";
    char expr4[] = "((2 + 3)";

    printf("Expressão 1: '%s'\n", expr1);
    verificaBalanceamentoExpressao(expr1);

    printf("Expressão 2: '%s'\n", expr2);
    verificaBalanceamentoExpressao(expr2);

    printf("Expressão 3: '%s'\n", expr3);
    verificaBalanceamentoExpressao(expr3);

    printf("Expressão 4: '%s'\n", expr4);
    verificaBalanceamentoExpressao(expr4);
}

void testarQuestao6() {
    printf("\n============================================================\n");
    printf("TESTE QUESTÃO 6: Intercalar Duas Filas\n");
    printf("============================================================\n");
    Fila *f1 = criarFila();
    enfileirar(f1, 10);
    enfileirar(f1, 20);
    enfileirar(f1, 30);

    Fila *f2 = criarFila();
    enfileirar(f2, 1);
    enfileirar(f2, 2);
    enfileirar(f2, 3);
    enfileirar(f2, 4);
    enfileirar(f2, 5);

    printf("Fila 1:\n  ");
    mostrarFila(f1);
    printf("Fila 2:\n  ");
    mostrarFila(f2);

    Fila *f3 = intercalarFilas(f1, f2);

    printf("Fila resultante intercalada (f3):\n  ");
    mostrarFila(f3);
    printf("Estado final da Fila 1:\n  ");
    mostrarFila(f1);
    printf("Estado final da Fila 2:\n  ");
    mostrarFila(f2);

    destruirFila(f1);
    destruirFila(f2);
    destruirFila(f3);
}

void testarQuestao7() {
    printf("\n============================================================\n");
    printf("TESTE QUESTÃO 7: Ordenar Pilha em Ordem Crescente\n");
    printf("============================================================\n");
    Pilha *p = criarPilha();
    push(p, 40);
    push(p, 20);
    push(p, 50);
    push(p, 10);
    push(p, 30);

    printf("Pilha original desordenada:\n  ");
    mostrarPilha(p);

    ordenarPilha(p);

    printf("Pilha apos ordenação (menor elemento no topo):\n  ");
    mostrarPilha(p);

    destruirPilha(p);
}

void testarQuestao8() {
    printf("\n============================================================\n");
    printf("TESTE QUESTÃO 8: Remover o Elemento do Fundo da Pilha\n");
    printf("============================================================\n");
    Pilha *p = criarPilha();
    push(p, 40); // Fundo
    push(p, 30);
    push(p, 20);
    push(p, 10); // Topo

    printf("Pilha antes da remoção:\n  ");
    mostrarPilha(p);

    int fundo = removerFundoPilha(p);
    printf("Elemento do fundo retornado: %d\n", fundo);

    printf("Pilha apos remoção do fundo (ordem dos demais preservada):\n  ");
    mostrarPilha(p);

    destruirPilha(p);
}

void testarQuestao9() {
    printf("\n============================================================\n");
    printf("TESTE QUESTÃO 9: Concatenar Filas em O(1)\n");
    printf("============================================================\n");
    Fila *f1 = criarFila();
    enfileirar(f1, 10);
    enfileirar(f1, 20);

    Fila *f2 = criarFila();
    enfileirar(f2, 30);
    enfileirar(f2, 40);
    enfileirar(f2, 50);

    printf("Fila 1 antes:\n  ");
    mostrarFila(f1);
    printf("Fila 2 antes:\n  ");
    mostrarFila(f2);

    concatenarFilasO1(f1, f2);

    printf("Fila 1 apos concatenação O(1):\n  ");
    mostrarFila(f1);
    printf("Fila 2 apos concatenação (deve estar vazia):\n  ");
    mostrarFila(f2);

    destruirFila(f1);
    destruirFila(f2);
}

void testarQuestao10() {
    printf("\n============================================================\n");
    printf("TESTE QUESTÃO 10: Comparar se Duas Pilhas são Iguais\n");
    printf("============================================================\n");
    Pilha *p1 = criarPilha();
    push(p1, 1);
    push(p1, 2);
    push(p1, 3);

    Pilha *p2 = criarPilha();
    push(p2, 1);
    push(p2, 2);
    push(p2, 3);

    Pilha *p3 = criarPilha();
    push(p3, 1);
    push(p3, 99);
    push(p3, 3);

    printf("Pilha 1:\n  ");
    mostrarPilha(p1);
    printf("Pilha 2:\n  ");
    mostrarPilha(p2);
    printf("Pilha 3:\n  ");
    mostrarPilha(p3);

    int comp1_2 = saoPilhasIguais(p1, p2);
    printf("Comparando p1 e p2: %s (retorno = %d)\n", comp1_2 ? "IGUAIS" : "DIFERENTES", comp1_2);

    int comp1_3 = saoPilhasIguais(p1, p3);
    printf("Comparando p1 e p3: %s (retorno = %d)\n", comp1_3 ? "IGUAIS" : "DIFERENTES", comp1_3);

    printf("Verificando se p1 foi preservada:\n  ");
    mostrarPilha(p1);
    printf("Verificando se p2 foi preservada:\n  ");
    mostrarPilha(p2);

    destruirPilha(p1);
    destruirPilha(p2);
    destruirPilha(p3);
}

int main() {
    printf("============================================================\n");
    printf("  BATERIA DE TESTES - POSSÍVEIS QUESTÕES P3 (PILHAS E FILAS)\n");
    printf("============================================================\n");

    testarQuestao1();
    testarQuestao2();
    testarQuestao3();
    testarQuestao4();
    testarQuestao5();
    testarQuestao6();
    testarQuestao7();
    testarQuestao8();
    testarQuestao9();
    testarQuestao10();

    printf("\n============================================================\n");
    printf("  TODOS OS TESTES FORAM EXECUTADOS COM SUCESSO!\n");
    printf("============================================================\n");

    return 0;
}
