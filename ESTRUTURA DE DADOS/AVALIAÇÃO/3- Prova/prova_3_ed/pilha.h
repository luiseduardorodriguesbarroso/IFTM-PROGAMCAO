#ifndef PILHA_H
#define PILHA_H 1

#include <stdio.h>
#include <stdlib.h>
#include "nosimples.h"

typedef struct pilha
{
    NoSimples * topo;
    int tamanho;
} Pilha;

Pilha * criarPilha();

void empilhar(int valor, Pilha * pontPilha);  // PUSH
int topo(Pilha * pontPilha);
int desempilhar(Pilha * pontPilha);  // POP

void mostrarPilha(Pilha * pontPilha);

void limparPilha(Pilha * pontPilha);
void destruirPilha(Pilha ** pontPilha);

#endif