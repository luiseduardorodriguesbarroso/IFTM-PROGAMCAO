#ifndef PILHA_H
#define PILHA_H 1

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da pilha
typedef struct NoPilha {
    int valor;
    struct NoPilha *prox;
} NoPilha;

// TAD Pilha
typedef struct Pilha {
    NoPilha *topo;
    int tamanho;
} Pilha;

// Primitivas para inteiros
Pilha* criarPilha(void);
void destruirPilha(Pilha *p);
void push(Pilha *p, int valor);
int pop(Pilha *p);
int pilhaVazia(Pilha *p);
void mostrarPilha(Pilha *p);

// Primitivas para caracteres (usadas nas questoes 3 e 5)
Pilha* criarPilhaChars(void);
void destruirPilhaChars(Pilha *p);
void pushChar(Pilha *p, char c);
char popChar(Pilha *p);

#endif
