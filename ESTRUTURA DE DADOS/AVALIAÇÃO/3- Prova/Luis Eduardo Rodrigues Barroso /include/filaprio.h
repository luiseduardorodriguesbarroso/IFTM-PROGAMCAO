#ifndef FILAPRIO_H
#define FILAPRIO_H 1

#include "noprio.h"

typedef struct fila_prio
{
    NoPrio * inicio;
    NoPrio * fim;
    int tamanho;
} FilaPrio;

FilaPrio * criarFilaPrio();
void limparFilaPrio(FilaPrio * pontFila);
void destruirFilaPrio(FilaPrio ** pontPontFila);
void mostrarFilaPrio(FilaPrio * pontFila);

#endif