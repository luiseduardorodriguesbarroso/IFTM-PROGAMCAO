#include "fila.h"

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

void destruirFila(Fila *f) {
    if (f == NULL) return;
    while (!filaVazia(f)) {
        desenfileirar(f);
    }
    free(f);
}

void enfileirar(Fila *f, int valor) {
    if (f == NULL) return;
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro fatal: Falha na alocacao de memoria para No.\n");
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

int filaVazia(Fila *f) {
    return (f == NULL || f->inicio == NULL || f->tamanho == 0);
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

// Implementacao das funcoes de fila para caracteres
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
