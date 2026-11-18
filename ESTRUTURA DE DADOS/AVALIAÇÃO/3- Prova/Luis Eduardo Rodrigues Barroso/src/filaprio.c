#include "filaprio.h"

FilaPrio * criarFilaPrio()
{
    FilaPrio * nova = (FilaPrio *) malloc(sizeof(FilaPrio));
    if (nova == NULL)
    {
        printf("Erro fatal: Falha na alocacao de memoria para a FilaPrio.\n");
        exit(1);
    }
    nova->inicio = NULL;
    nova->fim = NULL;
    nova->tamanho = 0;
    return nova;
}

void limparFilaPrio(FilaPrio * pontFila)
{
    if (pontFila->tamanho > 0)
    {
        NoPrio * pontAux1 = pontFila->inicio;
        NoPrio * pontAux2 = pontAux1->proximo;
        while (pontAux2 != NULL)
        {
            free(pontAux1);
            pontAux1 = pontAux2;
            pontAux2 = pontAux2->proximo;
        }
        free(pontAux1);
        pontFila->inicio = NULL;
        pontFila->fim = NULL;
        pontFila->tamanho = 0;
    }
}

void destruirFilaPrio(FilaPrio ** pontPontFila)
{
    limparFilaPrio(*pontPontFila);
    free(*pontPontFila);
    *pontPontFila = NULL;
}

void mostrarFilaPrio(FilaPrio * pontFila)
{
    printf("Tamanho = %d, NULL", pontFila->tamanho);
    if (pontFila->tamanho > 0)
    {
        printf(" <- ");
        NoPrio * aux = pontFila->inicio;
        while (aux != NULL)
        {
            printf("[%s:%d]", aux->nome, aux->prioridade);
            aux = aux->proximo;
            if (aux != NULL)
            {
                printf(" <-> ");
            }
        }
        printf(" -> NULL");
    }
    printf("\n");
}