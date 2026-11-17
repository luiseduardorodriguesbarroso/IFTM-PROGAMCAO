#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prova.h"

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
    push(p, 30);
    push(p, 10);
    push(p, 50);
    push(p, 20);
    push(p, 40);

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
