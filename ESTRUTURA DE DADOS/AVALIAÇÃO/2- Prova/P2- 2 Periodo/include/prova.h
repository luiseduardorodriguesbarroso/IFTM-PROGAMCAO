#ifndef PROVA_H
#define PROVA_H 1

#include "listasli.h"
#include "listadli.h"

// ============================================================================
// QUESTÃO 1 (15%)
// Crie uma função que recebe como parâmetro uma lista duplamente ligada e 
// retorna 1 caso a lista seja um palíndromo (a sequência de valores lida do 
// inicio ao fim é exatamente igual à lida do fim ao inicio) e 0 caso contrário.
//
// Casos especiais:
// - Uma lista vazia NÃO é um palíndromo (retorne 0).
// - Uma lista com 1 único elemento É um palíndromo (retorne 1).
//
// Restrições:
// - Proibido criar outra lista, vetor, alocar nós ou alterar a lista original.
// - Proibido chamar obterValorPosicaoLDLI ou qualquer outra função pronta.
// - Percorra a lista manipulando apenas ponteiros de nó.
// ============================================================================
int ehPalindromoLDLI(ListaDLI *pontLista);

// ============================================================================
// QUESTÃO 2 (20%)
// Crie uma função que recebe um valor e uma lista simplesmente ligada.
// A função deve buscar a PRIMEIRA ocorrência desse valor na lista, desligar 
// esse nó de sua posição atual e religá-lo como o novo início da lista, 
// retornando 1.
//
// Casos especiais:
// - Se o valor já estiver no primeiro nó (início), não altere a lista e retorne 1.
// - Se a lista estiver vazia ou o valor não existir na lista, retorne 0.
//
// Restrições:
// - Proibido usar qualquer função pronta da ListaSLI.
// - Proibido criar novos nós (malloc/criarNoSLI), liberar nós (free) ou 
//   apenas trocar os valores (int) dentro dos nós. Manipule os ponteiros!
// ============================================================================
int moverParaInicioLSLI(int valor, ListaSLI *pontLista);


// ============================================================================
// QUESTÃO 3 (30%)
// Crie uma função que recebe uma posição (0 a tamanho - 1) e uma lista 
// simplesmente ligada. A função deve cortar a lista original naquela posição: 
// todos os nós a partir de 'posicao' até o fim devem ser desligados da lista 
// original e passar a formar uma nova ListaSLI retornada pela função, 
// reaproveitando os próprios nós existentes.
//
// Exemplo:
// L1 = 10 -> 20 -> 30 -> 40 -> 50 -> NULL (tamanho = 5)
// Chamando L2 = dividirListaLSLI(2, L1):
// - L1 passa a ser: 10 -> 20 -> NULL (tamanho = 2)
// - L2 retornada é: 30 -> 40 -> 50 -> NULL (tamanho = 3)
//
// Casos especiais:
// - Casos inválidos (lista vazia, posicao < 0 ou posicao >= tamanho): 
//   não altere a lista original e retorne NULL.
// - Se posicao == 0: L1 deve ficar completamente vazia (inicio = NULL e 
//   tamanho = 0) e L2 leva todos os nós.
//
// Restrições:
// - Você DEVE usar criarListaSLI() apenas para criar a estrutura da nova lista.
// - É estritamente proibido usar outras funções prontas, criar novos nós 
//   (malloc/criarNoSLI), apagar nós (free) ou copiar valores (int).
// ============================================================================
ListaSLI* dividirListaLSLI(int posicao, ListaSLI *pontLista);


// ============================================================================
// QUESTÃO 4 (35%)
// Crie uma função que recebe um valor e uma lista duplamente ligada.
// A função deve buscar e remover TODAS as ocorrências desse valor na lista, 
// liberando a memória dos nós removidos (free) e retornando a quantidade 
// total de nós que foram removidos.
//
// Casos especiais:
// - Se a lista estiver vazia ou o valor não for encontrado, retorne 0.
//
// Restrições:
// - Proibido usar as funções prontas da lista (como removerInicioLDLI, 
//   removerFimLDLI ou limparLDLI).
// - Proibido trocar valores (int) entre os nós. Desengate o nó, ajuste os 
//   ponteiros anterior/proximo/inicio/fim, atualize o tamanho e dê free no nó.
// ============================================================================
int removerTodasOcorrenciasLDLI(int valor, ListaDLI *pontLista);

#endif
