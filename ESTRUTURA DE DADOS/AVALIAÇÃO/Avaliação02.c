#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "questoes.h"

int main()
{

    return 0;
}

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

// 1) Concatenação de Listas
void concatenarDuplas(ListaDupla *l1, ListaDupla *l2)
{
    if (l2->tamanho == 0)
    {
        return; 
    }
    if (l1->tamanho == 0)
    {
        l1->inicio = l2->inicio;
        l1->fim = l2->fim;
        l1->tamanho = l2->tamanho;
    }
    else
    {
        l1->fim->proximo = l2->inicio;
        l2->inicio->anterior = l1->fim;
        
        l1->fim = l2->fim;
        
        l1->tamanho = l1->tamanho + l2->tamanho;
    }

    l2->inicio = NULL;
    l2->fim = NULL;
    l2->tamanho = 0;
}

// 2) Remoção no Meio
int removerPosicaoDupla(int posicao, ListaDupla * pontLista)
{
    if (pontLista->tamanho == 0)
    {
        printf("\n Aviso: A lista esta vazia!\n");
        return -1;
    }
    if (posicao < 0)
    {
        printf("\n Aviso: Posicao negativa e invalida!\n");
        return -1;
    }
    if (posicao > (pontLista->tamanho - 1))
    {
        printf("\n Aviso: Posicao invalida (maior do que o tamanho da lista)!\n");
        return -1;
    }

    NoDupla *aux = pontLista->inicio;
    int i;
    
    for (i = 0; i < posicao; i++)
    {
        aux = aux->proximo;
    }

    int valor_removido = aux->valor;
    if (pontLista->tamanho == 1)
    {
        pontLista->inicio = NULL;
        pontLista->fim = NULL;
    }
    else if (posicao == 0) 
    {
        pontLista->inicio = aux->proximo;
        pontLista->inicio->anterior = NULL;
    }
    else if (posicao == (pontLista->tamanho - 1)) 
    {
        pontLista->fim = aux->anterior;
        pontLista->fim->proximo = NULL;
    }
    else 
    {
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
    }

    free(aux);
    pontLista->tamanho--;

    return valor_removido;
}

// 3) Extração com Condição
ListaDupla * extrairImparesDupla(ListaDupla * pontListaOriginal)
{
    ListaDupla *novaLista = criarListaDupla(); 
    
    NoDupla *aux = pontListaOriginal->inicio;
    NoDupla *proximo_aux = NULL;

    while (aux != NULL)
    {
        proximo_aux = aux->proximo; 

        if (aux->valor % 2 != 0) 
        {
            if (pontListaOriginal->tamanho == 1)
            {
                pontListaOriginal->inicio = NULL;
                pontListaOriginal->fim = NULL;
            }
            else if (aux == pontListaOriginal->inicio)
            {
                pontListaOriginal->inicio = aux->proximo;
                pontListaOriginal->inicio->anterior = NULL;
            }
            else if (aux == pontListaOriginal->fim)
            {
                pontListaOriginal->fim = aux->anterior;
                pontListaOriginal->fim->proximo = NULL;
            }
            else
            {
                aux->anterior->proximo = aux->proximo;
                aux->proximo->anterior = aux->anterior;
            }
            pontListaOriginal->tamanho--;
   
            aux->proximo = NULL;
            aux->anterior = novaLista->fim;

            if (novaLista->tamanho == 0)
            {
                novaLista->inicio = aux;
            }
            else
            {
                novaLista->fim->proximo = aux;
            }   
            novaLista->fim = aux;
            novaLista->tamanho++;
        }
        aux = proximo_aux;
    }
    return novaLista;
}