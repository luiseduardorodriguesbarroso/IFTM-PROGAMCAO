#include "listaduplamenteligadainteiros.h"

ListaDupla *criarListaDupla()
{
    ListaDupla *nova = (ListaDupla *)malloc(sizeof(ListaDupla));
    if (nova == NULL)  // erro alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para a ListaDupla.\n");
        exit(1); // Encerra o programa
    }
    nova->inicio = nova->fim = NULL;
    nova->tamanho = 0;
    return nova;
}

void inserirInicioDupla(int valor, ListaDupla *pontLista)
{
    NoDupla *novo;
    if (pontLista->tamanho == 0) // VAZIA  lista->inicio/fim == NULL
    {
        novo = criarNoDupla(valor, NULL, NULL);
        pontLista->fim = novo;
    }
    else // 1 OU + DE 1 ELEM
    {
        novo = criarNoDupla(valor, NULL, pontLista->inicio); // A
        // pontLista->inicio = novo;  // B
        // novo->proximo->anterior = novo; // C
        pontLista->inicio->anterior = novo; // B
    }
    pontLista->inicio = novo;
    pontLista->tamanho++;
}

void mostrarDupla(ListaDupla *pontLista)
{
    if (pontLista->tamanho == 0)
    { // VAZIA
        printf("TAM = 0 | NULL\n");
    }
    else
    { // 1 ELEM OU + DE 1 ELEM
        printf("TAM = %d | NULL <=> ", pontLista->tamanho);
        NoDupla *pont = pontLista->inicio;
        while (pont != NULL)
        {
            printf("%d <=> ", pont->valor);
            pont = pont->proximo;
        }
        printf("NULL\n");
    }
}

void mostrarInvertidoDupla(ListaDupla *pontLista)
{
    if (pontLista->tamanho == 0)
    { // VAZIA
        printf("TAM = 0 | NULL\n");
    }
    else
    { // 1 ELEM OU + DE 1 ELEM
        printf("TAM = %d | NULL <=> ", pontLista->tamanho);
        NoDupla *pont = pontLista->fim;
        while (pont != NULL)
        {
            printf("%d <=> ", pont->valor);
            pont = pont->anterior;
        }
        printf("NULL\n");
    }
}

void inserirFimDupla(int valor, ListaDupla *pontLista)
{
    NoDupla *novo;
    if (pontLista->tamanho == 0) // VAZIA
    {
        novo = criarNoDupla(valor, NULL, NULL);
        pontLista->inicio = novo;
    }
    else // 1 ELEM OU + DE 1 ELEM
    {
        novo = criarNoDupla(valor, pontLista->fim, NULL);
        pontLista->fim->proximo = novo;
    }
    pontLista->fim = novo;
    pontLista->tamanho++;
}

void limparDupla(ListaDupla *pontLista)
{
    if (pontLista->tamanho > 0)
    {
        // 1 ELEM OU + DE 1 ELEM
        NoDupla *pont = pontLista->inicio;
        while (pont->proximo != NULL) // tem proximo
        {
            pont = pont->proximo;
            free(pont->anterior);
        }
        free(pont);
        pontLista->inicio = NULL;
        pontLista->fim = NULL;
        pontLista->tamanho = 0;
    }
}

void destruirDupla(ListaDupla ** pontLista)
{
    limparDupla(*pontLista);
    free(*pontLista);
    *pontLista = NULL;
}

int removerFimDupla(ListaDupla * pontLista) 
{
    int valor;
    if (pontLista->tamanho == 0)  // VAZIA
    {
        printf("Impossivel remover o fim de uma lista vazia\n");
        return -1;
    }

    valor = pontLista->fim->valor;
    if (pontLista->tamanho == 1)  // 1 ELEM
    {
        free(pontLista->fim);
        pontLista->inicio = NULL;
        pontLista->fim = NULL;
    }
    else  // + DE 1 ELEM
    {
        pontLista->fim = pontLista->fim->anterior;
        free(pontLista->fim->proximo);        
        pontLista->fim->proximo = NULL;
    }
    pontLista->tamanho--;
    return valor;
}


int removerInicioDupla(ListaDupla * pontLista)
{
    int valor;
    if (pontLista->tamanho == 0)  // VAZIA
    {
        printf("Impossivel remover o inicio de uma lista vazia\n");
        return -1;
    }

    valor = pontLista->inicio->valor;
    if (pontLista->tamanho == 1)  // 1 ELEM
    {
        free(pontLista->inicio);
        pontLista->inicio = NULL;
        pontLista->fim = NULL;
    }
    else  // + DE 1 ELEM
    {
        pontLista->inicio = pontLista->inicio->proximo;
        free(pontLista->inicio->anterior);
        pontLista->inicio->anterior = NULL;
    }
    pontLista->tamanho--;
    return valor;
}

int obterValorInicioDupla(ListaDupla * pontLista)
{
    if (pontLista->tamanho == 0)  // VAZIA
    {
        printf("Impossivel obter o valor do inicio de uma lista vazia\n");
        return -1;
    } 
    else { // 1 ELEM ou + DE 1 ELEM
        return pontLista->inicio->valor;
    }
}


int obterValorFimDupla(ListaDupla * pontLista)
{
    if (pontLista->tamanho == 0)  // VAZIA
    {
        printf("Impossivel obter o valor do fim de uma lista vazia\n");
        return -1;
    } 
    else { // 1 ELEM ou + DE 1 ELEM
        return pontLista->fim->valor;
    }
}

int trocarValorInicioDupla(int valor, ListaDupla * pontLista)
{
    if (pontLista->tamanho == 0)
    {
        printf("Impossivel trocar o valor do inicio de uma lista vazia\n");
        return 0;
    } 
    else { // 1 ELEM ou + DE 1 ELEM
        pontLista->inicio->valor = valor;
        return 1;
    }
}

int trocarValorFimDupla(int valor, ListaDupla * pontLista)
{
    if (pontLista->tamanho == 0)
    {
        printf("Impossivel trocar o valor do fim de uma lista vazia\n");
        return 0;
    } 
    else { // 1 ELEM ou + DE 1 ELEM
        pontLista->fim->valor = valor;
        return 1;
    }
}

// lista vazia -> avisar o usuario que esta vazia e retornar 0
// posicao negativa -> avisar o usuario e retornar 0
// posicao > (tamanho -1) -> avisar o usuario e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, obterPosicao(1, lista)
// TAM = 3 | 3 -> 7 -> 5 -> NULL, return 7
int obterValorPosicaoDupla(int posicao, ListaDupla * pontLista)
{
    if (pontLista->tamanho == 0)
    {
        printf("Impossivel obter o valor de uma posicao de uma lista vazia\n");
        return 0;
    }
    if (posicao < 0 || posicao > pontLista->tamanho - 1)
    {
        printf("Posicao invalida. Posicoes permitidas: 0 a %d\n", pontLista->tamanho - 1);
        return 0;
    }
    NoDupla * pont = pontLista->inicio;  // 1 ou + DE 1 ELEM
    int cont = 0;
    while (cont < posicao)
    {
        pont = pont->proximo;
        cont++;
    }
    return pont->valor;
}


