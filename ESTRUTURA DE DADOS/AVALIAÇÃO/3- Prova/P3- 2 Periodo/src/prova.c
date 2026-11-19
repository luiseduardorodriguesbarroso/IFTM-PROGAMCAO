#include "prova.h"

// ============================================================================
// QUESTÃO 1 (Valor: 15%) - Uso de Pilha como TAD (Caixa-Preta)
// ============================================================================
int compactarAdjacentesPilhaI(PilhaI *pontPilha)
{
    if (pontPilha == NULL || pontPilha->tamanho <= 1) {
        return 0;
    }

    PilhaI *pilhaAux = criarPilhaI();
    int removidos = 0;

    // Desempilha da pilha original para a auxiliar pulando duplicados consecutivos
    // ATENÇÃO: desempilharI retorna status (1), o valor DEVE ser lido com topoI()!
    while (pontPilha->tamanho > 0) {
        int atual = topoI(pontPilha);
        desempilharI(pontPilha);

        while (pontPilha->tamanho > 0 && topoI(pontPilha) == atual) {
            desempilharI(pontPilha);
            removidos++;
        }

        empilharI(atual, pilhaAux);
    }

    // Devolve da pilhaAux para pontPilha restaurando a ordem original
    while (pilhaAux->tamanho > 0) {
        int val = topoI(pilhaAux);
        desempilharI(pilhaAux);
        empilharI(val, pontPilha);
    }

    destruirPilhaI(&pilhaAux);
    return removidos;
}

// ============================================================================
// QUESTÃO 2 (Valor: 20%) - Uso de Fila + Pilha como TAD (Caixa-Preta)
// ============================================================================
int inverterPrimeirosKFilaI(int k, FilaI *pontFila)
{
    if (pontFila == NULL || pontFila->tamanho == 0 || k <= 0 || k > pontFila->tamanho) {
        return 0;
    }

    if (k == 1) {
        return 1;
    }

    PilhaI *pilhaAux = criarPilhaI();

    // 1. Desenfileira os k primeiros elementos e empilha
    // ATENÇÃO: desinfileirarI retorna status (1), o valor DEVE ser lido com proximoI()!
    for (int i = 0; i < k; i++) {
        int val = proximoI(pontFila);
        desinfileirarI(pontFila);
        empilharI(val, pilhaAux);
    }

    // 2. Desempilha de volta para a fila (ficam invertidos, mas no final)
    while (pilhaAux->tamanho > 0) {
        int val = topoI(pilhaAux);
        desempilharI(pilhaAux);
        enfileirarI(val, pontFila);
    }

    // 3. Rotaciona os elementos restantes (tamanho - k) para o fim da fila
    int restantes = pontFila->tamanho - k;
    for (int i = 0; i < restantes; i++) {
        int val = proximoI(pontFila);
        desinfileirarI(pontFila);
        enfileirarI(val, pontFila);
    }

    destruirPilhaI(&pilhaAux);
    return 1;
}

// ============================================================================
// QUESTÃO 3 (Valor: 30%) - Manipulação de Ponteiros In-Place (Pilha -> Fila)
// ============================================================================
int transferirTopoParaFilaInPlace(int k, PilhaI *pontPilha, FilaI *pontFila)
{   
    if (pontPilha == NULL || pontFila == NULL || pontPilha->tamanho == 0 || k <= 0 || k > pontPilha->tamanho) {
        return 0;
    }

    // 1. Identifica o primeiro nó a ser transferido (topo atual)
    NoSLI *primeiro = pontPilha->topo;

    // 2. Caminha até o k-ésimo nó a partir do topo
    NoSLI *k_esimo = primeiro;
    for (int i = 1; i < k; i++) {
        k_esimo = k_esimo->proximo;
    }

    // 3. Atualiza o topo da pilha para o nó seguinte ao k-ésimo
    pontPilha->topo = k_esimo->proximo;
    pontPilha->tamanho -= k;

    // 4. O k-ésimo nó agora será o último nó da fila, portanto proximo vira NULL
    k_esimo->proximo = NULL;

    // 5. Engata a cadeia [primeiro ... k_esimo] no fim da fila
    if (pontFila->inicio == NULL) {
        // Fila estava vazia
        pontFila->inicio = primeiro;
        pontFila->fim = k_esimo;
    } else {
        // Fila já tinha elementos
        pontFila->fim->proximo = primeiro;
        pontFila->fim = k_esimo;
    }

    // 6. Atualiza o tamanho da fila
    pontFila->tamanho += k;

    return 1;
}

// ============================================================================
// QUESTÃO 4 (Valor: 35%) - Manipulação de Ponteiros Duplos em FilaPrio
// ============================================================================
int alterarPrioridadePrio(char nome[], int novaPrioridade, FilaPrio *pontFila)
{
    if (pontFila == NULL || pontFila->tamanho == 0 || nome == NULL) {
        return 0;
    }

    // 1. Busca a primeira ocorrência do arquivo pelo nome
    NoPrio *alvo = pontFila->inicio;
    while (alvo != NULL && strcmp(alvo->nome, nome) != 0) {
        alvo = alvo->proximo;
    }

    if (alvo == NULL) {
        return 0; // Arquivo não encontrado
    }

    // 2. Se a prioridade já for igual, não move nada
    if (alvo->prioridade == novaPrioridade) {
        return 1;
    }

    // 3. Se a fila só tem 1 elemento, apenas atualiza a prioridade
    if (pontFila->tamanho == 1) {
        alvo->prioridade = novaPrioridade;
        return 1;
    }

    // 4. Atualiza a prioridade do nó
    alvo->prioridade = novaPrioridade;

    // 5. Desengata o nó alvo da sua posição atual
    if (alvo->anterior != NULL) {
        alvo->anterior->proximo = alvo->proximo;
    } else {
        pontFila->inicio = alvo->proximo;
    }

    if (alvo->proximo != NULL) {
        alvo->proximo->anterior = alvo->anterior;
    } else {
        pontFila->fim = alvo->anterior;
    }

    alvo->anterior = NULL;
    alvo->proximo = NULL;
    pontFila->tamanho--;

    // 6. Procura a posição correta: menor prioridade primeiro.
    // Em caso de empate, fica APÓS todos com prioridade <= novaPrioridade (ordem FIFO).
    NoPrio *atual = pontFila->inicio;
    while (atual != NULL && atual->prioridade <= novaPrioridade) {
        atual = atual->proximo;
    }

    // 7. Religa o nó alvo na posição encontrada
    if (atual == NULL) {
        // Insere no final da fila
        if (pontFila->inicio == NULL) {
            pontFila->inicio = alvo;
            pontFila->fim = alvo;
        } else {
            pontFila->fim->proximo = alvo;
            alvo->anterior = pontFila->fim;
            pontFila->fim = alvo;
        }
    } else if (atual == pontFila->inicio) {
        // Insere no início da fila
        alvo->proximo = pontFila->inicio;
        pontFila->inicio->anterior = alvo;
        pontFila->inicio = alvo;
    } else {
        // Insere no meio, antes de atual
        alvo->proximo = atual;
        alvo->anterior = atual->anterior;
        atual->anterior->proximo = alvo;
        atual->anterior = alvo;
    }

    pontFila->tamanho++;
    return 1;
}
