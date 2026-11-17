#include "pilha.h"

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

void destruirPilha(Pilha *p) {
    if (p == NULL) return;
    while (!pilhaVazia(p)) {
        pop(p);
    }
    free(p);
}

void push(Pilha *p, int valor) {
    if (p == NULL) return;
    NoPilha *novo = (NoPilha *)malloc(sizeof(NoPilha));
    if (novo == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para NoPilha.\n");
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
    NoPilha *remover = p->topo;
    int valor = remover->valor;
    p->topo = remover->prox;
    free(remover);
    p->tamanho--;
    return valor;
}

int pilhaVazia(Pilha *p) {
    return (p == NULL || p->topo == NULL || p->tamanho == 0);
}

void mostrarPilha(Pilha *p) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia (tamanho = 0)\n");
        return;
    }
    printf("Pilha (tam: %d): [Topo] ", p->tamanho);
    NoPilha *atual = p->topo;
    while (atual != NULL) {
        printf("%d", atual->valor);
        if (atual->prox != NULL) {
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf(" [Fundo]\n");
}

// Implementacao das funcoes de pilha para caracteres
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
