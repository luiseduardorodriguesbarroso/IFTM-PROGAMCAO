#include "nosimples.h"

NoSimples * criarNoSimples(int valor, NoSimples * proximo)
{
    NoSimples * pont = (NoSimples *) malloc(sizeof(NoSimples));
    if (pont == NULL)  // erro alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para o No.\n");
        exit(1); // Encerra o programa
    }
    pont->valor = valor;
    pont->proximo = proximo;
    return pont;
}