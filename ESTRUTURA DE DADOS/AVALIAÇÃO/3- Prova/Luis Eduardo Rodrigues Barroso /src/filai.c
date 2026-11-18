#include "filai.h"

FilaI * criarFilaI()
{
    FilaI * nova = (FilaI *) malloc(sizeof(FilaI));
    if (nova == NULL)   // ERRO alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para a FilaI.\n");
        exit(1);
    }
    nova->tamanho = 0;
    nova->inicio = NULL;
    nova->fim = NULL;
    return nova;
}

void limparFilaI(FilaI * pontFila)
{
    if (pontFila->tamanho > 0)
    {
        NoSLI * pontAux1, *pontAux2;
        pontAux1 = pontFila->inicio;
        pontAux2 = pontAux1->proximo;
        while(pontAux2 != NULL)
        {
            free(pontAux1);
            pontAux1 = pontAux2;
            pontAux2 = pontAux2->proximo;
        }
        free(pontAux1);
        pontFila->tamanho = 0;
        pontFila->inicio = NULL;
        pontFila->fim = NULL;
    }
}

void destruirFilaI(FilaI ** pontPontFila)
{
    limparFilaI(*pontPontFila);
    free(*pontPontFila);
    *pontPontFila = NULL;
}

// Tamanho = 0, Vazia
// Tamanho = 5, 6(P) -> 12 -> 4 -> 7 -> 2 -> NULL
void mostrarFilaI(FilaI * pontFila)
{
    printf("Tamanho = %d, ", pontFila->tamanho);
    if (pontFila->tamanho == 0) // VAZIA
    {
        printf("Vazia\n");
    }
    else  // 1 OU + DE 1 ELEM
    {
        NoSLI * pontAux = pontFila->inicio;
        printf("%d(P) -> ", pontAux->valor);
        pontAux = pontAux->proximo;
        while(pontAux != NULL)
        {
            printf("%d -> ", pontAux->valor);
            pontAux = pontAux->proximo;
        }
        printf("NULL\n");
    }
}

void enfileirarI(int valor, FilaI * pontFila)
{
    NoSLI * novo = criarNoSLI(valor, NULL);
    if (pontFila->tamanho == 0)  // pontFila->inicio == NULL
    {
        pontFila->inicio = novo;
    }
    else // 1 OU + DE 1 ELEM
    {
        pontFila->fim->proximo = novo;
    }
    pontFila->fim = novo;
    pontFila->tamanho++;
}

int desinfileirarI(FilaI * pontFila)
{
    if (pontFila->tamanho == 0)
    {
        printf("Impossivel remover de uma fila vazia\n");
        return 0;
    }
    else 
    {
        NoSLI * pontAux = pontFila->inicio;
        pontFila->inicio = pontAux->proximo;
        free(pontAux);
        pontFila->tamanho--;
        if (pontFila->tamanho == 0) {
            pontFila->fim = NULL;
        }
        return 1;
    }
}

int proximoI(FilaI * pontFila)
{
    if (pontFila->tamanho == 0) 
    {
        printf("Impossivel obter o próximo de uma fila vazia\n");
        return 0;
    }
    else
    {
        return pontFila->inicio->valor;
    }
}