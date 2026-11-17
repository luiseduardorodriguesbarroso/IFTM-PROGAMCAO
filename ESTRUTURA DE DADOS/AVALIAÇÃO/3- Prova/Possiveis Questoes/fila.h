#ifndef FILA_H
#define FILA_H 1

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da fila
typedef struct No {
    int valor;
    struct No *prox;
} No;

// TAD Fila
typedef struct Fila {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

// Primitivas para inteiros
Fila* criarFila(void);
void destruirFila(Fila *f);
void enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f);
int filaVazia(Fila *f);
void mostrarFila(Fila *f);

// Primitivas para caracteres (usadas na questao 3)
Fila* criarFilaChars(void);
void destruirFilaChars(Fila *f);
void enfileirarChar(Fila *f, char c);
char desenfileirarChar(Fila *f);

#endif
