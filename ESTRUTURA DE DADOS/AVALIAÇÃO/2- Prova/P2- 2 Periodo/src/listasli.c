#include "listasli.h"

ListaSLI * criarListaSLI()
{
    ListaSLI * nova = (ListaSLI *) malloc(sizeof(ListaSLI));
    if (nova == NULL)   // ERRO alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para a ListaSLI.\n");
        exit(1);
    }
    nova->tamanho = 0;
    nova->inicio = NULL;
    return nova;
}

void inserirFimLSLI(int valor, ListaSLI * pontLista)
{
    NoSLI * novo = criarNoSLI(valor, NULL);  // A
    // VAZIA
    if (pontLista->tamanho == 0)  // pontLista->inicio == NULL
    {
        pontLista->inicio = novo;  // B
    }
    else // 1 OU + DE 1 ELEM
    {
        NoSLI * pontAux = pontLista->inicio;
        while (pontAux->proximo != NULL)  // Andar o ponteiro na lista
        {
            pontAux = pontAux->proximo;
        }
        pontAux->proximo = novo;  // B
    }
    pontLista->tamanho++;  // C
}

void mostrarLSLI(ListaSLI * pontLista)
{
    printf("Tamanho = %d\n", pontLista->tamanho);
    if (pontLista->tamanho == 0) // VAZIA
    {
        printf("Vazia\n");
    }
    else  // 1 OU + DE 1 ELEM
    {
        NoSLI * pontAux = pontLista->inicio;
        while(pontAux != NULL)
        {
            printf("%d -> ", pontAux->valor);
            pontAux = pontAux->proximo;
        }
        printf("NULL\n");
    }
}

void inserirInicioLSLI(int valor, ListaSLI * pontLista)
{
    NoSLI * novo;
    if (pontLista->tamanho == 0)  // VAZIA
    {
        novo = criarNoSLI(valor, NULL);
    }
    else  // 1 OU + DE 1 ELEMENTO
    {
        novo = criarNoSLI(valor, pontLista->inicio);
    }
    pontLista->inicio = novo;
    pontLista->tamanho++;
}

// void inserirInicioLSLI2(int valor, ListaSLI * pontLista)
// {
//     NoSLI * novo = criarNoSLI(valor, NULL);
//     novo->proximo = pontLista->inicio;
//     pontLista->inicio = novo;
//     pontLista->tamanho++;
// }

int obterValorInicioLSLI(ListaSLI * pontLista)
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


int obterValorFimLSLI(ListaSLI * pontLista)
{
    if (pontLista->tamanho == 0)  // VAZIA
    {
        printf("Impossivel obter o valor do fim de uma lista vazia\n");
        return 0;
    }
    else  // 1 OU + DE 1 ELEMENTO
    {
        NoSLI * pontAux = pontLista->inicio;
        while (pontAux->proximo != NULL)
        {
            pontAux = pontAux->proximo;
        }
        return pontAux->valor;
    }
}

// 0 nao removeu
// 1 removeu
int removerInicioLSLI(ListaSLI * pontLista)
{
    if (pontLista->tamanho == 0)
    {
        printf("Impossivel remover o valor do inicio de uma lista vazia\n");
        return 0;
    }
    else 
    {
        NoSLI * pontAux = pontLista->inicio;
        pontLista->inicio = pontAux->proximo;
        free(pontAux);
        pontLista->tamanho--;
        return 1;
    }
}

void limparLSLI(ListaSLI * pontLista)
{
    if (pontLista->tamanho > 0)
    {
        NoSLI * pontAux1, *pontAux2;
        pontAux1 = pontLista->inicio;
        pontAux2 = pontAux1->proximo;
        while(pontAux2 != NULL)
        {
            free(pontAux1);
            pontAux1 = pontAux2;
            pontAux2 = pontAux2->proximo;
        }
        free(pontAux1);
        pontLista->tamanho = 0;
        pontLista->inicio = NULL;
    }
}

void destruirLSLI(ListaSLI ** pontPontLista)
{
    limparLSLI(*pontPontLista);
    free(*pontPontLista);
    *pontPontLista = NULL;
}

// 0 nao removeu
// 1 removeu
int removerFimLSLI(ListaSLI * pontLista)
{
    if (pontLista->tamanho == 0)
    {
        printf("Impossivel remover o fim de uma lista vazia\n");
        return 0;
    }
    else if (pontLista->tamanho == 1)
    {
        free(pontLista->inicio);
        pontLista->inicio = NULL;
        pontLista->tamanho--;
        return 1;
    } 
    else 
    {
        // 1 ponteiro só
        NoSLI * pontAux;
        pontAux = pontLista->inicio;
        while (pontAux->proximo->proximo != NULL)  // penultimo?
        {
            pontAux = pontAux->proximo;
        }
        free(pontAux->proximo);
        pontAux->proximo = NULL;
        pontLista->tamanho--;

        // 2 ponteiros
        // NoSLI * pontAux1, * pontAux2;
        // pontAux1 = NULL;
        // pontAux2 = pontLista->inicio;
        // while(pontAux2->proximo != NULL)  // ultimo?
        // {
        //     pontAux1 = pontAux2;
        //     pontAux2 = pontAux2->proximo;
        // }
        // free(pontAux2);
        // pontAux1->proximo = NULL;
        // pontLista->tamanho--;

        return 1;
    }
}

int trocarValorInicioLSLI(int valor, ListaSLI * pontLista)
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

int trocarValorFimLSLI(int valor, ListaSLI * pontLista)
{
    if (pontLista->tamanho == 0)
    {
        printf("Impossivel trocar o valor do fim de uma lista vazia\n");
        return 0;
    }
    else 
    {
        NoSLI * pontAux = pontLista->inicio;
        while(pontAux->proximo != NULL) {
            pontAux = pontAux->proximo;
        }
        pontAux->valor = valor;
        return 1;
    }
}

// lista vazia -> avisar o usuario que esta vazia, nao inserir e retornar 0
// posicao negativa -> avisar o usuario, nao inserir e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao inserir e retornar 0
int inserirPosicaoLSLI(int valor, int posicao, ListaSLI * pontLista)
{
    if (pontLista->tamanho == 0) {
        printf("Impossivel inserir um valor em uma posicao de uma lista vazia\n");
        return 0;
    } 
    else if(posicao < 0)
    {
        printf("Impossivel inserir um valor em uma posicao negativa de uma lista\n");
        return 0;
    }
    else if(posicao > pontLista->tamanho - 1)
    {
        printf("Impossivel inserir um valor em uma posicao maior que o tamanho-1 de uma lista\n");
        return 0;
    }
    else // tem elementos e a posicao é valida
    {
        if (posicao == 0)
        {
            inserirInicioLSLI(valor, pontLista);
            return 1;
        }
        else 
        {
            NoSLI * pontAux = pontLista->inicio;
            int cont = 0;
            while (cont < posicao - 1)
            {
                pontAux = pontAux->proximo;
                cont++;
            }
            NoSLI * novo = criarNoSLI(valor, pontAux->proximo);
            pontAux->proximo = novo;
            pontLista->tamanho++;
            return 1;
        }
    }
}