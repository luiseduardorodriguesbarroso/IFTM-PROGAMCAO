#include <stdio.h>
#include <string.h>
#include "../include/pilhai.h"
#include "../include/filai.h"
#include "../include/filaprio.h"
#include "../include/prova.h"


/*@(
    Get-Content include\prova.h, include\pilhai.h, src\pilhai.c
    "INSTRUÇÃO: Com base nos arquivos acima, implemente em C a função (int alterarPrioridadePrio(char nome[], int novaPrioridade, FilaPrio *pontFila)) da Questão (4). ATENÇÃO: Sigua sempre todas as intruções do enuncado da questão, e preste muita atenção as restriçoes da questão"
) | ollama run qwen2.5-coder:7b



 */
// Questão 1 (15%)
// QUESTÃO 1 (Valor: 15%) - Uso de Pilha como TAD (Caixa-Preta)
// Crie uma função que recebe uma pilha de inteiros e remove todas as 
// ocorrências duplicadas CONSECUTIVAS (adjacentes), mantendo apenas um 
// elemento de cada sequência contígua e preservando a ordem original da pilha.
// Retorne a quantidade total de elementos removidos.
//
// Exemplo:
// Antes:  (T) 10 -> 10 -> 10 -> 20 -> 30 -> 30 -> 10 -> NULL
// Depois: (T) 10 -> 20 -> 30 -> 10 -> NULL  (Retorna 3)
//
// Casos especiais:
// - Se a pilha estiver vazia ou tiver apenas 1 elemento, não altere e retorne 0.
//
// Restrições:
// - Proibido manipular ponteiros diretamente (->topo, ->proximo) ou alocar nós.
// - Proibido usar vetores ou Filas.
// - É permitido criar outras estruturas do tipo PilhaI e utilizar suas 
//   funções prontas
// ============================================================================
int compactarAdjacentesPilhaI(PilhaI *pontPilha)
{
    if (pontPilha == NULL || pontPilha->tamanho <= 1){
        printf("A pilha está vazia ou tem apenas 1 elemento, então não há nada a remover");
        return 0;
    }
    
    PilhaI *pilhatemp = criarPilhaI();
    int removidos = 0;

    while (pontPilha->tamanho > 0)
    {
        empilharI(desempilharI(pontPilha),pilhatemp);
    }

    while (pilhatemp->tamanho > 0)
    {
        int valor = desempilharI(pilhatemp);
        if (pontPilha->tamanho == 0 || valor != topoI(pontPilha)){
        empilharI(valor,pontPilha);
        }
        else {
            removidos++;
        }
    }
    destruirPilhaI(&pilhatemp);
    return removidos;  
}

// Questão 2 (20%)
// QUESTÃO 2 (Valor: 20%) - Uso de Fila + Pilha como TAD (Caixa-Preta)
// Crie uma função que recebe um inteiro k e uma fila de inteiros. A função 
// deve inverter a ordem apenas dos k PRIMEIROS elementos da fila, mantendo 
// os demais elementos na ordem original. Retorne 1 se deu certo ou 0 caso 
// contrário.
//
// Exemplo (k = 3):
// Antes:  10(P) -> 20 -> 30 -> 40 -> 50 -> NULL
// Depois: 30(P) -> 20 -> 10 -> 40 -> 50 -> NULL  (Retorna 1)
//
// Casos especiais:
// - Se a fila estiver vazia, k <= 0 ou k > tamanho: não altere a fila e 
//   retorne 0.
// - Se k == 1: a fila permanece igual e retorna 1.
//
// Restrições:
// - Proibido manipular ponteiros diretamente (->inicio, ->fim, ->proximo, ->topo).
// - Proibido usar vetores ou criar uma nova FilaI.
// - É permitido criar estruturas do tipo PilhaI e utilizar as funções prontas 
//   das bibliotecas de PilhaI e FilaI.
// ============================================================================
int inverterPrimeirosKFilaI(int k, FilaI *pontFila)
{
    if (pontFila == NULL || pontFila->tamanho == 0 || k <= 0 || k > pontFila->tamanho) {
        return 0;  // Fila vazia, k <= 0 ou k > tamanho: não altere a fila e retorne 0.
    }

    if (k == 1){
        return 1;
    }

    PilhaI *tempPilha = criarPilhaI();  // Cria uma pilha temporária para auxiliar na inversão

    // Empilha os primeiros k elementos da fila na pilha temporária
    for (int i = 0; i < k; i++) {
        empilharI(desinfileirarI(pontFila), tempPilha);
    }

    // Desempilha os elementos da pilha temporária e enfileira de volta na fila original
    while (tempPilha->tamanho > 0) {
        enfileirarI(desempilharI(tempPilha), pontFila);
    }

    destruirPilhaI(&tempPilha);  // Destroi a pilha temporária

    return 1;  // Operação bem-sucedida
}


// Questão 3 (30%)
// QUESTÃO 3 (Valor: 30%) - Manipulação de Ponteiros In-Place (Pilha -> Fila)
// Crie uma função que recebe um inteiro k, uma PilhaI e uma FilaI.
// A função deve cortar os 'k' primeiros nós do topo da pilha e engatá-los no 
// final da fila (mantendo a ordem em que estavam a partir do topo), 
// reaproveitando os PRÓPRIOS NÓS existentes na memória. Retorne 1 se a 
// transferência foi realizada ou 0 em caso de parâmetros inválidos.
//
// Exemplo (k = 2):
// Antes:
//   Pilha: (T) 10 -> 20 -> 30 -> NULL (tamanho = 3)
//   Fila:  80(P) -> 90 -> NULL        (tamanho = 2, inicio = 80, fim = 90)
// Depois de transferirTopoParaFilaInPlace(2, pilha, fila):
//   Pilha: (T) 30 -> NULL             (tamanho = 1, topo = 30)
//   Fila:  80(P) -> 90 -> 10 -> 20 -> NULL (tamanho = 4, inicio = 80, fim = 20)
//   Retorno: 1
//
// Casos especiais:
// - Se a pilha estiver vazia, k <= 0 ou k > pontPilha->tamanho: não altere 
//   nenhuma das estruturas e retorne 0.
// - Atenção: a fila de destino pode estar inicialmente VAZIA ou já conter elementos!
// - Se k == pontPilha->tamanho, a pilha deve terminar vazia.
//
// Restrições:
// - Proibido usar funções de inserção/remoção (empilharI, desempilharI, 
//   enfileirarI, desinfileirarI, limparPilhaI, limparFilaI).
// - Proibido criar novos nós (malloc/criarNoSLI), liberar nós (free) ou 
//   copiar valores (int). Manipule apenas os ponteiros e tamanhos!
// ============================================================================
int transferirTopoParaFilaInPlace(int k, PilhaI *pontPilha, FilaI *pontFila)
{   
   if (pontPilha == NULL || pontFila == NULL || k <= 0 || k > pontPilha->tamanho) {
        return 0;
    }

    int tamanhoPilhaOriginal = pontPilha->tamanho;

    for (int i = 0; i < k; i++) {
        NoSLI *no = pontPilha->topo;
        pontPilha->topo = pontPilha->topo->proximo;
        pontPilha->tamanho--;

        no->proximo = pontFila->fim;
        if (pontFila->fim != NULL) {
            pontFila->fim->proximo = no;
        }
        pontFila->fim = no;

        if (pontFila->inicio == NULL) {
            pontFila->inicio = no;
        }

        no->anterior = NULL;
    }

    return 1;
}

// Questão 4 (35%)
// QUESTÃO 4 (Valor: 35%) - Manipulação de Ponteiros Duplos em FilaPrio
// Crie uma função que recebe o nome de um arquivo, uma nova prioridade e uma 
// fila de prioridade duplamente encadeada (como uma fila de impressão). A 
// função deve localizar a primeira ocorrência com esse nome de arquivo 
// (usando strcmp), alterar sua prioridade para 'novaPrioridade' e reposicionar 
// o PRÓPRIO NÓ na posição correta da fila.
// Retorne 1 se encontrou e atualizou, ou 0 se a fila estiver vazia ou o 
// arquivo não existir na fila.
//
// Regras de Ordenação da FilaPrio:
// - Menor valor numérico de prioridade vem primeiro (ex: prioridade 1 vem 
//   antes de prioridade 2).
// - Em caso de empate na prioridade, o nó reposicionado deve ficar APÓS todos 
//   os arquivos que já possuíam prioridade menor ou igual (ordem FIFO).
//
// Casos especiais:
// - Se a prioridade atual do arquivo já for igual a 'novaPrioridade', não 
//   altere sua posição na fila e retorne 1.
// - Se a fila tiver apenas 1 elemento, atualize sua prioridade mantendo inicio 
//   e fim apontando para ele.
// - Mantenha todos os ponteiros (inicio, fim, anterior, proximo) íntegros.
//
// Restrições:
// - Proibido criar novos nós (malloc/criarNoPrio), liberar nós (free), usar 
//   vetores ou trocar os dados (nome/prioridade) entre nós diferentes. 
//   Desengate o nó de sua posição atual e religue-o na nova posição!
// ============================================================================
int alterarPrioridadePrio(char nome[], int novaPrioridade, FilaPrio *pontFila)
{
     if (pontFila->tamanho == 0)
    {
        return 0;  // Fila vazia, nada a fazer
    }

    NoPrio *pontAtual = pontFila->inicio;
    while (pontAtual != NULL)
    {
        if (strcmp(pontAtual->nome, nome) == 0)
        {
            if (pontAtual->prioridade == novaPrioridade)
            {
                return 1;  // Prioridade já é a nova, não altera posição
            }

            // Desengate o nó atual da lista
            NoPrio *pontAnterior = pontAtual->anterior;
            NoPrio *pontProximo = pontAtual->proximo;

            if (pontAnterior != NULL)
            {
                pontAnterior->proximo = pontProximo;
            }
            if (pontProximo != NULL)
            {
                pontProximo->anterior = pontAnterior;
            }

            // Reposicione o nó na fila corretamente
            NoPrio *pontProcurar = pontFila->inicio;
            while (pontProcurar != NULL && pontProcurar->prioridade <= novaPrioridade)
            {
                pontProcurar = pontProcurar->proximo;
            }

            if (pontProcurar == NULL)  // Inserir no final
            {
                pontAtual->anterior = pontFila->fim;
                pontAtual->proximo = NULL;
                pontFila->fim->proximo = pontAtual;
                pontFila->fim = pontAtual;
            }
            else  // Inserir em uma posição intermediária
            {
                pontAtual->anterior = pontProcurar->anterior;
                pontAtual->proximo = pontProcurar;
                pontProcurar->anterior->proximo = pontAtual;
                pontProcurar->anterior = pontAtual;
            }

            pontAtual->prioridade = novaPrioridade;

            return 1;  // Nó encontrado e prioridade atualizada
        }

        pontAtual = pontAtual->proximo;
    }

    return 0;  // Nó não encontrado na fila
}