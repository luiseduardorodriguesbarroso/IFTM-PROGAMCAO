#ifndef NOSLI_H
#define NOSLI_H 1

#include <stdlib.h>
#include <stdio.h>

typedef struct nosimples_int
{
    int valor;
    struct nosimples_int * proximo;
} NoSLI;

NoSLI * criarNoSLI(int valor, NoSLI * proximo);

#endif
