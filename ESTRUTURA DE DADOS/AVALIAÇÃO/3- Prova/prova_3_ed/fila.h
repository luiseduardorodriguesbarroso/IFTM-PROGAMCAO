#ifndef FILA_H
#define FILA_H 1

#include <stdlib.h>
#include <stdio.h>
#include "nosimples.h"

typedef struct fila {
    NoSimples * inicio;
    NoSimples * fim;
    int tamanho;
} Fila;

Fila * criarFila();

void inserir(int valor, Fila * pontFila);  // ENQUEUE
int remover(Fila * pontFila);  // DEQUEUE
int proximo(Fila * pontFila);

void mostrarFila(Fila * pontFila);

void limparFila(Fila * pontFila);
void destruirFila(Fila ** pontPontFila);

#endif