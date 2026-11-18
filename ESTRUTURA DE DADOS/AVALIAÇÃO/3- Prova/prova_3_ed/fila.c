#include "fila.h"

Fila *criarFila()
{
    Fila *nova = (Fila *)malloc(sizeof(Fila));
    nova->inicio = nova->fim = NULL;
    nova->tamanho = 0;
    return nova;
}

// Inserindo no FIM
void inserir(int valor, Fila *pontFila)
{
    NoSimples *novo = criarNoSimples(valor, NULL);
    if (pontFila->tamanho == 0) // VAZIA
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

// Tam = 0, P[]
// Tam = 1, P[10]
// Tam = 3, P[10 <- 15 <- 7]
void mostrarFila(Fila *pontFila)
{
    printf("TAM = %d, P[", pontFila->tamanho);

    if (pontFila->tamanho > 0)
    {
        NoSimples *pont = pontFila->inicio;
        while (pont->proximo != NULL)
        {
            printf("%d <- ", pont->valor);
            pont = pont->proximo;
        }
        printf("%d", pont->valor);
    }

    printf("]\n");
}

int proximo(Fila *pontFila)
{
    if (pontFila->tamanho == 0)
    {
        printf("Impossivel obter o proximo de uma fila vazia\n");
        return 0;
    }
    else
    {
        return pontFila->inicio->valor;
    }
}

// Removendo do INICIO
int remover(Fila *pontFila)
{
    int valor = 0;
    if (pontFila->tamanho == 0) // VAZIA
    {
        printf("Impossivel remover de uma fila vazia\n");
    }
    else
    {
        valor = pontFila->inicio->valor;
        if (pontFila->tamanho == 1) // 1 ELEM
        {
            free(pontFila->inicio);
            pontFila->inicio = NULL;
            pontFila->fim = NULL;
        }
        else // + DE 1 ELEM
        {
            NoSimples *pont = pontFila->inicio->proximo;
            free(pontFila->inicio);
            pontFila->inicio = pont;
        }
        pontFila->tamanho--;
    }
    return valor;
}

void destruirFila(Fila ** pontPontFila)
{
    limparFila(*pontPontFila);
    free(*pontPontFila);
    *pontPontFila = NULL;
}

void limparFila(Fila * pontFila)
{
    if (pontFila->tamanho > 0)
    {
        NoSimples * pont1 = pontFila->inicio;
        NoSimples * pont2 = pont1->proximo;
        while (pont2 != NULL)
        {
            free(pont1);
            pont1 = pont2;
            pont2 = pont2->proximo;
        }
        free(pont1);
        pontFila->inicio = NULL;
        pontFila->fim = NULL;
        pontFila->tamanho = 0;

    }
}