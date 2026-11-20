#include "prova.h"

// ============================================================================
// QUESTÃO 1 (Valor: 15%) - Uso de Pilha como TAD (Caixa-Preta)
// ============================================================================

int compactarAdjacentesPilhaI(PilhaI *pontPilha)
{
    if (pontPilha == NULL || pontPilha->tamanho <= 1)
    {
        return 0;
    }

    PilhaI *aux = criarPilhaI();
    int removidos = 0;

    // Move primeiro elemento (topo original) para a pilha auxiliar
    int ultimo = topoI(pontPilha);
    desempilharI(pontPilha);
    empilharI(ultimo, aux);

    while (pontPilha->tamanho > 0)
    {
        int atual = topoI(pontPilha);
        desempilharI(pontPilha);

        if (atual == ultimo)
        {
            removidos++;
        }
        else
        {
            empilharI(atual, aux);
            ultimo = atual;
        }
    }
    
    // Devolve da pilha auxiliar para a pilha original (restaurando a ordem original!)
    while (aux->tamanho > 0)
    {
        int val = topoI(aux);
        desempilharI(aux);
        empilharI(val, pontPilha);
    }

    destruirPilhaI(&aux);
    return removidos;
}

// ============================================================================
// QUESTÃO 2 (Valor: 20%) - Uso de Fila + Pilha como TAD (Caixa-Preta)
// ============================================================================

int inverterPrimeirosKFilaI(int k, FilaI *pontFila)
{
    if (pontFila == NULL || pontFila->tamanho == 0 || k <= 0 || k > pontFila->tamanho)
    {
        return 0;
    }
    if (k == 1)
    {
        return 1;
    }

    int total = pontFila->tamanho;
    PilhaI *aux = criarPilhaI();

    // 1. Retira os k primeiros da fila e empilha em aux
    for (int i = 0; i < k; i++)
    {
        int val = proximoI(pontFila);
        desinfileirarI(pontFila);
        empilharI(val, aux);
    }

    // 2. Desempilha os k elementos e enfileira no fim da fila
    while (aux->tamanho > 0)
    {
        int val = topoI(aux);
        desempilharI(aux);
        enfileirarI(val, pontFila);
    }

    // 3. Rotaciona os (total - k) elementos restantes para o final da fila
    for (int i = 0; i < total - k; i++)
    {
        int val = proximoI(pontFila);
        desinfileirarI(pontFila);
        enfileirarI(val, pontFila);
    }

    destruirPilhaI(&aux);
    return 1;
}

// ============================================================================
// QUESTÃO 3 (Valor: 30%) - Manipulação de Ponteiros In-Place (Pilha -> Fila)
// ============================================================================

int alterarPrioridadePrio(char nome[], int novaPrioridade, FilaPrio *pontFila)
{
    if (pontFila == NULL || pontFila->tamanho == 0 || pontFila->inicio == NULL || nome == NULL)
    {
        return 0;
    }

    // 1. Localiza a primeira ocorrência pelo nome
    NoPrio *alvo = pontFila->inicio;
    while (alvo != NULL && strcmp(alvo->nome, nome) != 0)
    {
        alvo = alvo->proximo;
    }
    if (alvo == NULL)
    {
        return 0; // Arquivo não encontrado
    }

    // Caso especial: mesma prioridade ou único elemento na fila
    if (alvo->prioridade == novaPrioridade)
    {
        return 1;
    }
    alvo->prioridade = novaPrioridade;
    if (pontFila->tamanho == 1)
    {
        return 1;
    }

    // 2. Desengata 'alvo' da sua posição atual na LDE
    if (alvo->anterior != NULL)
    {
        alvo->anterior->proximo = alvo->proximo;
    }
    else
    {
        pontFila->inicio = alvo->proximo;
    }

    if (alvo->proximo != NULL)
    {
        alvo->proximo->anterior = alvo->anterior;
    }
    else
    {
        pontFila->fim = alvo->anterior;
    }
    alvo->anterior = NULL;
    alvo->proximo = NULL;

    // 3. Procura a nova posição ordenada:
    // Menor valor numérico vem primeiro. Em empate, fica APÓS todos com prioridade <= novaPrioridade (FIFO!)
    NoPrio *atual = pontFila->inicio;
    while (atual != NULL && atual->prioridade <= novaPrioridade)
    {
        atual = atual->proximo;
    }

    // 4. Religa 'alvo' na nova posição
    if (atual == pontFila->inicio)
    {
        // Insere no início da fila
        alvo->proximo = pontFila->inicio;
        pontFila->inicio->anterior = alvo;
        pontFila->inicio = alvo;
    }
    else if (atual == NULL)
    {
        // Insere no fim da fila
        alvo->anterior = pontFila->fim;
        pontFila->fim->proximo = alvo;
        pontFila->fim = alvo;
    }
    else
    {
        // Insere no meio, imediatamente antes de 'atual'
        alvo->proximo = atual;
        alvo->anterior = atual->anterior;
        atual->anterior->proximo = alvo;
        atual->anterior = alvo;
    }

    return 1;
}