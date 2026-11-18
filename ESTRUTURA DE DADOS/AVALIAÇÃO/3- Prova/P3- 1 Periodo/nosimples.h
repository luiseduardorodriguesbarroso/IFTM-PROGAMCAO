#ifndef NOSIMPLES_H
#define NOSIMPLES_H 1

#include <stdlib.h>
#include <stdio.h>

typedef struct nosimples {
    int valor;
    struct nosimples * proximo;
} NoSimples;

NoSimples * criarNoSimples(int valor, NoSimples * proximo);

#endif