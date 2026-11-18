#ifndef NODUPLA_H
#define NODUPLA_H 1

#include <stdlib.h>
#include <stdio.h>

typedef struct nodupla {
    int valor;
    struct nodupla * anterior;
    struct nodupla * proximo;
} NoDupla;

NoDupla * criarNoDupla(int valor, NoDupla *anterior, NoDupla * proximo);

#endif