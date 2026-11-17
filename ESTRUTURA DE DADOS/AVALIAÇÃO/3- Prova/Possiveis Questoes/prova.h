#ifndef PROVA_H
#define PROVA_H 1

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "fila.h"

/* ============================================================
   INSTRUÇÕES GERAIS - AVALIAÇÃO 3 (PILHAS E FILAS)

   - TADs disponíveis: Fila e Pilha (inteiros e caracteres).
   - Respeite rigorosamente as restrições descritas em cada questão.
   - Utilize apenas as funções primitivas autorizadas em cada enunciado.
   - Proibido acessar ponteiros internos quando restrito.
   - Cuidado com vazamento de memória (free em estruturas auxiliares).
   - Use o programa.c (main) para testar suas soluções.
   ============================================================ */

// ============================================================================
// QUESTÃO 1 (30%)
// Crie uma função que recebe uma Fila e inverte a ordem de todos os seus 
// elementos utilizando OBRIGATORIAMENTE uma Pilha como estrutura auxiliar.
//
// Casos especiais:
// - Se a fila estiver vazia ou for nula, a função não deve fazer nada.
//
// Restrições:
// - Proibido acessar os ponteiros internos da estrutura (como inicio, fim, prox).
// - Utilize apenas as funções primitivas do TAD: 
//   enfileirar, desenfileirar, filaVazia, push, pop, pilhaVazia, criarPilha 
//   e destruirPilha.
// ============================================================================
void inverterFila(Fila *pontFila);

// ============================================================================
// QUESTÃO 2 (30%)
// Crie uma função que recebe um valor e uma Fila. A função deve buscar e 
// remover TODAS as ocorrências desse valor na fila original, mantendo a ordem 
// dos demais elementos. A função deve retornar a quantidade total de remoções.
//
// Casos especiais:
// - Se a fila estiver vazia ou o valor não for encontrado, retorne 0.
//
// Restrições:
// - Você deve usar uma Fila auxiliar para resolver o problema.
// - É proibido acessar os ponteiros internos dos nós (nada de aux->prox).
// - Utilize apenas as funções primitivas de enfileirar e desenfileirar.
// ============================================================================
int removerOcorrenciasFila(int valor, Fila *pontFila);

// ============================================================================
// QUESTÃO 3 (40%)
// Crie uma função que recebe uma string (vetor de char) e determina se ela é 
// um palíndromo (retorna 1) ou não (retorna 0), utilizando OBRIGATORIAMENTE 
// uma Pilha e uma Fila simultaneamente.
//
// Casos especiais:
// - Uma string vazia (NULL ou '\0' na primeira posição) NÃO é um palíndromo (retorne 0).
// - Uma string contendo 1 único caractere É um palíndromo (retorne 1).
//
// Restrições:
// - Insira os caracteres da string tanto na Pilha quanto na Fila.
// - Faça a validação desenfileirando e desempilhando ao mesmo tempo.
// - Obrigatoriamente limpe (esvazie) e destrua as estruturas auxiliares antes 
//   do return, mesmo se achar o resultado na metade da checagem.
// ============================================================================
int ehPalindromoPilhaFila(char *palavra);

// ============================================================================
// QUESTÃO 4 (20%)
// Crie uma função que recebe uma Fila original contendo números inteiros. 
// A função deve retirar todos os valores PARES da fila original e transferi-los 
// para uma NOVA fila, que será retornada pela função. Os valores ÍMPARES devem 
// permanecer na fila original, mantendo a ordem exata em que estavam.
//
// Exemplo:
// Fila Original (F1): [Frente] 10, 15, 20, 7, 33, 42 [Fim]
// Chamando F2 = extrairParesFila(F1):
// - F1 passa a ser: [Frente] 15, 7, 33 [Fim]
// - F2 retornada é: [Frente] 10, 20, 42 [Fim]
//
// Casos especiais:
// - Se a fila original estiver vazia, retorne NULL.
// - Se não houver nenhum número par, retorne uma fila vazia e não altere a original.
//
// Restrições:
// - Utilize criarFila() apenas para criar a nova fila de pares e uma fila auxiliar.
// - É estritamente proibido acessar os ponteiros internos (como inicio, fim).
// - Utilize apenas enfileirar, desenfileirar e filaVazia.
// ============================================================================
Fila* extrairParesFila(Fila *pontFila);

// ============================================================================
// QUESTÃO 5 (30%)
// Crie uma função que recebe uma expressão matemática em formato de string e 
// utiliza uma Pilha para verificar se os parênteses '()', colchetes '[]' e 
// chaves '{}' estão abertos e fechados na ordem correta (balanceados).
// Retorne 1 se a expressão estiver correta e 0 se estiver incorreta.
//
// Exemplo:
// "{ [ ( ) ] }" -> Balanceado (retorna 1)
// "{ [ ( ] ) }" -> Desbalanceado (retorna 0)
//
// Casos especiais:
// - Uma string vazia (NULL ou '\0') deve retornar 0.
// - Se sobrarem caracteres de abertura na pilha ao final da string, retorne 0.
//
// Restrições:
// - Utilize apenas OBRIGATORIAMENTE uma Pilha para resolver o problema.
// - Ignore os números e operadores da string, empilhe apenas os caracteres 
//   de abertura ('{', '[', '(') e desempilhe ao encontrar os de fechamento.
// ============================================================================
int verificaBalanceamentoExpressao(char *expressao);

// ============================================================================
// QUESTÃO 6 (20%)
// Crie uma função que recebe duas Filas (f1 e f2) e retorna uma NOVA Fila 
// contendo os elementos de ambas intercalados (um de f1, um de f2, etc.).
// 
// Exemplo:
// f1 = [10, 20, 30] e f2 = [1, 2, 3, 4, 5]
// Retorno f3 = [10, 1, 20, 2, 30, 3, 4, 5]
//
// Casos especiais:
// - Se uma fila for maior que a outra, os elementos restantes da fila maior 
//   devem ser simplesmente adicionados ao final da nova fila.
// - As filas originais f1 e f2 devem ficar vazias ao final do processo.
//
// Restrições:
// - Proibido acessar ponteiros internos (inicio, fim, prox).
// - Utilize apenas criarFila, enfileirar, desenfileirar e filaVazia.
// ============================================================================
Fila* intercalarFilas(Fila *f1, Fila *f2);

// ============================================================================
// QUESTÃO 7 (25%)
// Crie uma função que recebe uma Pilha contendo números inteiros desordenados 
// e ORDENA esses elementos em ordem CRESCENTE (o menor valor fica no topo).
//
// Casos especiais:
// - Se a pilha estiver vazia ou tiver apenas 1 elemento, não faça nada.
//
// Restrições:
// - É OBRIGATÓRIO o uso de apenas UMA Pilha auxiliar.
// - Proibido o uso de vetores, listas, arrays ou outras variáveis compostas.
// - Proibido acessar os ponteiros internos (topo, prox).
// - Utilize apenas criarPilha, destruirPilha, push, pop e pilhaVazia.
// ============================================================================
void ordenarPilha(Pilha *pOriginal);

// ============================================================================
// QUESTÃO 8 (20%)
// Crie uma função que recebe uma Pilha, extrai e retorna APENAS o valor que 
// está no FUNDO da pilha (o primeiro elemento que foi inserido). 
// Os demais elementos devem permanecer na pilha original, EXATAMENTE na 
// mesma ordem em que estavam.
//
// Exemplo:
// Pilha: [Topo] 10, 20, 30, 40 [Fundo] -> Fundo é o 40.
// Após a execução, a pilha deve ser: [Topo] 10, 20, 30 [Fundo] e retorna 40.
//
// Casos especiais:
// - Se a pilha estiver vazia, retorne -1.
//
// Restrições:
// - Utilize obrigatoriamente uma Pilha auxiliar.
// - Proibido acessar os ponteiros internos do nó.
// ============================================================================
int removerFundoPilha(Pilha *pOriginal);

// ============================================================================
// QUESTÃO 9 (20%)
// Crie uma função que recebe duas Filas (f1 e f2) construídas com listas 
// simplesmente ligadas. A função deve CONCATENAR f2 ao final de f1.
// 
// Casos especiais:
// - Se f2 estiver vazia, não faça nada.
// - Se f1 estiver vazia, f1 deve assumir os nós de f2.
//
// Restrições:
// - É ESTRITAMENTE PROIBIDO usar criarNo, malloc, free, enfileirar ou desenfileirar.
// - É ESTRITAMENTE PROIBIDO usar laços de repetição (while/for). A operação 
//   deve ser O(1).
// - Você deve manipular EXCLUSIVAMENTE os ponteiros internos (inicio, fim, prox).
// - Ao final, f2 deve ficar completamente vazia (inicio = NULL e fim = NULL).
// ============================================================================
void concatenarFilasO1(Fila *f1, Fila *f2);

// ============================================================================
// QUESTÃO 10 (25%)
// Crie uma função que recebe duas Pilhas (p1 e p2) e verifica se elas são 
// EXATAMENTE IGUAIS (possuem o mesmo tamanho e os mesmos valores na mesma ordem).
// A função deve retornar 1 se forem iguais e 0 se forem diferentes.
//
// Regra de Ouro:
// - Ao final da função, p1 e p2 DEVEM estar no estado EXATAMENTE ORIGINAL, 
//   independentemente se são iguais ou diferentes.
//
// Restrições:
// - Proibido acessar os ponteiros internos (topo, prox).
// - Utilize apenas as primitivas (push, pop, pilhaVazia, criarPilha, destruirPilha).
// - Utilize pilhas auxiliares para realizar a verificação e a reconstrução.
// ============================================================================
int saoPilhasIguais(Pilha *p1, Pilha *p2);

#endif
