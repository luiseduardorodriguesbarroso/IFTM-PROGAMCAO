#include "listadli.h"

ListaDLI *criarListaDLI()
{
    ListaDLI *nova = (ListaDLI *)malloc(sizeof(ListaDLI));
    if (nova == NULL) // ERRO alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para a ListaDLI.\n");
        exit(1);
    }
    nova->tamanho = 0;
    nova->inicio = NULL;
    nova->fim = NULL;
    return nova;
}

void inserirInicioLDLI(int valor, ListaDLI *pontLista)
{
    NoDLI *novo = criarNoDLI(valor, NULL, pontLista->inicio);
    if (pontLista->tamanho == 0)
    {
        pontLista->fim = novo;
    }
    else
    {
        pontLista->inicio->anterior = novo;
    }
    pontLista->inicio = novo;
    pontLista->tamanho++;
}

// Tamanho = 0, NULL
// Tamanho = 1, NULL <- 10 -> NULL
// Tamanho = 3, NULL <- 10 <-> 20 <-> 30 -> NULL
void mostrarLDLI(ListaDLI *pontLista)
{
    printf("Tamanho = %d, NULL", pontLista->tamanho);
    if (pontLista->tamanho > 0)
    {
        printf(" <- ");
        NoDLI *aux = pontLista->inicio;
        while (aux != NULL)
        {
            printf("%d", aux->valor);
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

// Mostrar do fim para o inicio
void mostrarInvertidaLDLI(ListaDLI *pontLista)
{
    printf("Tamanho = %d, NULL", pontLista->tamanho);
    if (pontLista->tamanho > 0)
    {
        printf(" <- ");
        NoDLI *aux = pontLista->fim;
        while (aux != NULL)
        {
            printf("%d", aux->valor);
            aux = aux->anterior;
            if (aux != NULL)
            {
                printf(" <-> ");
            }
        }
        printf(" -> NULL");
    }
    printf("\n");
}

void inserirFimLDLI(int valor, ListaDLI *pontLista)
{
    NoDLI *novo = criarNoDLI(valor, pontLista->fim, NULL);
    if (pontLista->tamanho == 0)
    {
        pontLista->inicio = novo;
    }
    else
    {
        pontLista->fim->proximo = novo;
    }
    pontLista->fim = novo;
    pontLista->tamanho++;
}

void limparLDLI(ListaDLI *pontLista)
{
    if (pontLista->tamanho > 0)
    {
        NoDLI *aux = pontLista->inicio;
        while (aux->proximo != NULL) // while (aux != pontLista->fim)
        {
            aux = aux->proximo;
            free(aux->anterior);
        }
        free(pontLista->fim);
        pontLista->inicio = NULL;
        pontLista->fim = NULL;
        pontLista->tamanho = 0;
    }
}

void destruirLDLI(ListaDLI **pontPontLista)
{
    limparLDLI(*pontPontLista);
    free(*pontPontLista);
    *pontPontLista = NULL;
}


int removerInicioLDLI(ListaDLI *pontLista)
{
    if (pontLista->tamanho == 0) 
    {
        printf("Impossivel remover o inicio de uma lista vazia\n");
        return 0;
    }
    else 
    {
        if (pontLista->tamanho == 1) // pontLista->inicio == pontLista->fim
        {
            free(pontLista->inicio);
            pontLista->inicio = NULL;
            pontLista->fim = NULL;
        }
        else {
            pontLista->inicio = pontLista->inicio->proximo;
            free(pontLista->inicio->anterior);
            pontLista->inicio->anterior = NULL;
        }
        pontLista->tamanho--;
        return 1;
    }
}

int removerFimLDLI(ListaDLI *pontLista)
{
    if (pontLista->tamanho == 0) 
    {
        printf("Impossivel remover o fim de uma lista vazia\n");
        return 0;
    }
    else 
    {
        if (pontLista->tamanho == 1) // pontLista->inicio == pontLista->fim
        {
            free(pontLista->inicio);
            pontLista->inicio = NULL;
            pontLista->fim = NULL;
        }
        else 
        {
            pontLista->fim = pontLista->fim->anterior;
            free(pontLista->fim->proximo);
            pontLista->fim->proximo = NULL;
        }
        pontLista->tamanho--;
        return 1;
    }
}

int obterValorInicioLDLI(ListaDLI *pontLista)
{
    if (pontLista->tamanho == 0) 
    {
        printf("Impossivel obter o valor do inicio de uma lista vazia\n");
        return 0;
    }
    else 
    {
        return pontLista->inicio->valor;
    }
}

int trocarValorInicioLDLI(int valor, ListaDLI *pontLista)
{
    if (pontLista->tamanho == 0) 
    {
        printf("Impossivel trocar o valor do inicio de uma lista vazia\n");
        return 0;
    }
    else 
    {
        pontLista->inicio->valor = valor;
        return 1;
    }
}

int obterValorFimLDLI(ListaDLI *pontLista)
{
    if (pontLista->tamanho == 0) 
    {
        printf("Impossivel obter o valor do fim de uma lista vazia\n");
        return 0;
    }
    else 
    {
        return pontLista->fim->valor;
    }
}

int trocarValorFimLDLI(int valor, ListaDLI *pontLista)
{
    if (pontLista->tamanho == 0) 
    {
        printf("Impossivel trocar o valor do fim de uma lista vazia\n");
        return 0;
    }
    else 
    {
        pontLista->fim->valor = valor;
        return 1;
    }
}

// lista vazia -> avisar o usuario que esta vazia e retornar 0
// posicao negativa -> avisar o usuario e retornar 0
// posicao > (tamanho -1) -> avisar o usuario e retornar 0
// posicao valida:
// TAM = 3 | NULL <- 3 <-> 7 <-> 5 -> NULL, obterPosicao(1, lista)
// TAM = 3 | NULL <- 3 <-> 7 <-> 5 -> NULL, return 7
int obterValorPosicaoLDLI(int posicao, ListaDLI *pontLista)
{
    if (pontLista->tamanho == 0)
    {
        printf("Impossivel obter o valor de uma posicao de uma lista vazia\n");
        return 0;
    } 
    else if (posicao < 0 ) 
    {
        printf("Impossivel obter o valor de uma posicao negativa de uma lista\n");
        return 0;
    }
    else if (posicao > pontLista->tamanho - 1)
    {
        printf("Impossivel obter o valor de uma posicao maior que o tamanho-1 de uma lista\n");
        return 0;
    }
    else 
    {
        NoDLI * aux = pontLista->inicio;
        int cont = 0;
        while (cont < posicao)
        {
            aux = aux->proximo;
            cont++;
        }
        return aux->valor;
    }
}