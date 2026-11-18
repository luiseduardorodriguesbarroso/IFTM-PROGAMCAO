#include "nodupla.h"

NoDupla *criarNoDupla(int valor, NoDupla *anterior, NoDupla *proximo)
{
    NoDupla *novo = (NoDupla *)malloc(sizeof(NoDupla));
    if (novo == NULL)  // erro alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para o NoDupla.\n");
        exit(1); // Encerra o programa
    }
    novo->valor = valor;
    novo->anterior = anterior;
    novo->proximo = proximo;
    return novo;
}