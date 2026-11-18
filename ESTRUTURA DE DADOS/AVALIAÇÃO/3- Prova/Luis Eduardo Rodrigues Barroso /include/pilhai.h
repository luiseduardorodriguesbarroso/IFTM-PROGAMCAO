#ifndef PILHAI_H
#define PILHAI_H 1

#include "nosli.h"

typedef struct pilha_int
{
    NoSLI * topo;
    int tamanho;
} PilhaI;

PilhaI * criarPilhaI();
void limparPilhaI(PilhaI * pontPilha);
void destruirPilhaI(PilhaI ** pontPontPilha);
void mostrarPilhaI(PilhaI * pontPilha);

void empilharI(int valor, PilhaI * pontPilha);
int desempilharI(PilhaI * pontPilha);
int topoI(PilhaI * pontPilha);

#endif