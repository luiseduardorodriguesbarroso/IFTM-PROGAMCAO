#include "noprio.h"

NoPrio * criarNoPrio(char nome[], int prioridade, NoPrio * anterior, NoPrio * proximo)
{
    NoPrio * novo = (NoPrio *) malloc(sizeof(NoPrio));
    if (novo == NULL)
    {
        printf("Erro fatal: Falha na alocacao de memoria para o NoPrio.\n");
        exit(1);
    }
    strcpy(novo->nome, nome);
    novo->prioridade = prioridade;
    novo->anterior = anterior;
    novo->proximo = proximo;
    return novo;
}