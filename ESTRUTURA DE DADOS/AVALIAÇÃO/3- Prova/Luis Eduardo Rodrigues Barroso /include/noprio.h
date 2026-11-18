#ifndef NOPRIO_H
#define NOPRIO_H 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct noprio
{
    char nome[255];
    int prioridade;
    struct noprio * anterior;
    struct noprio * proximo;
} NoPrio;

NoPrio * criarNoPrio(char nome[], int prioridade, NoPrio * anterior, NoPrio * proximo);

#endif
