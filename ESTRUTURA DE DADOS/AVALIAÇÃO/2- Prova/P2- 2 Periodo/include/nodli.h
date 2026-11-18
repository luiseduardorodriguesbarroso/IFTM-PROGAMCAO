#ifndef NODLI_H
#define NODLI_H 1

#include <stdlib.h>
#include <stdio.h>

typedef struct nodupla_int
{
    int valor;
    struct nodupla_int *anterior;
    struct nodupla_int *proximo;
} NoDLI;

NoDLI * criarNoDLI(int valor, NoDLI *anterior, NoDLI *proximo);

#endif