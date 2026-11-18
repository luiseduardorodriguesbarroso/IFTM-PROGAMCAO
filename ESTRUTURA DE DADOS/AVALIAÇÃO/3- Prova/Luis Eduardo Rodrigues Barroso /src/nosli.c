#include "nosli.h"

NoSLI * criarNoSLI(int valor, NoSLI * proximo)
{
    NoSLI * novo = (NoSLI *) malloc(sizeof(NoSLI));
    if (novo == NULL)   // ERRO alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para o NoSLI.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = proximo;
    return novo;
}