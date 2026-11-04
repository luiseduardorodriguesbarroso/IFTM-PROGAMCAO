#include "nodli.h"

NoDLI * criarNoDLI(int valor, NoDLI *anterior, NoDLI *proximo)
{
    NoDLI * novo = (NoDLI *) malloc(sizeof(NoDLI));
    if (novo == NULL)   // ERRO alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para o NoDLI.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->anterior = anterior;
    novo->proximo = proximo;
    return novo;
}