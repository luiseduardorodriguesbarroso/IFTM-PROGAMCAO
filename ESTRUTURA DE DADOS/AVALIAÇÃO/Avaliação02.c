/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    3º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2026
    Prof. Rafael Orbolato
    Data: 27/05/2026
*/
//===============================================================
//===============================================================
//======== LOCAL PARA DECLARAR AS INCLUDES E VARS GLOBAIS =======
//===============================================================
#include "questoes.h"
#include <stdio.h>
#include <stdlib.h>

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================

//===============================================================
// 1) Concatenação de Listas
void concatenarDuplas(ListaDupla *l1, ListaDupla *l2)
{
    // Se a lista 2 estiver vazia, não há o que fazer
    if (l2->tamanho == 0)
    {
        return; 
    }

    // Se a lista 1 estiver vazia, ela apenas recebe todos os ponteiros da lista 2
    if (l1->tamanho == 0)
    {
        l1->inicio = l2->inicio;
        l1->fim = l2->fim;
        l1->tamanho = l2->tamanho;
    }
    else
    {
        // Emenda direta usando os ponteiros (sem iterar)
        l1->fim->proximo = l2->inicio;
        l2->inicio->anterior = l1->fim;
        
        // Atualiza o final da lista 1 para ser o final da lista 2
        l1->fim = l2->fim;
        
        // Soma os tamanhos
        l1->tamanho = l1->tamanho + l2->tamanho;
    }

    // Ao final, a lista 2 deve ficar vazia
    l2->inicio = NULL;
    l2->fim = NULL;
    l2->tamanho = 0;
}

//===============================================================
// 2) Remoção no Meio
int removerPosicaoDupla(int posicao, ListaDupla * pontLista)
{
    // Verificacoes de erro obrigatorias
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
    
    // Navega ate a posicao desejada
    for (i = 0; i < posicao; i++)
    {
        aux = aux->proximo;
    }

    // Guarda o valor para retornar depois de apagar o no
    int valor_removido = aux->valor;

    // Lógica para desengatar o no da lista dependendo de onde ele esta
    if (pontLista->tamanho == 1)
    {
        // Era o unico elemento
        pontLista->inicio = NULL;
        pontLista->fim = NULL;
    }
    else if (posicao == 0) 
    {
        // Era o primeiro elemento
        pontLista->inicio = aux->proximo;
        pontLista->inicio->anterior = NULL;
    }
    else if (posicao == (pontLista->tamanho - 1)) 
    {
        // Era o ultimo elemento
        pontLista->fim = aux->anterior;
        pontLista->fim->proximo = NULL;
    }
    else 
    {
        // Esta no meio da lista
        aux->anterior->proximo = aux->proximo;
        aux->proximo->anterior = aux->anterior;
    }

    // Libera a memoria do no removido e diminui o tamanho
    free(aux);
    pontLista->tamanho--;

    return valor_removido;
}

//===============================================================
// 3) Extração com Condição
ListaDupla * extrairImparesDupla(ListaDupla * pontListaOriginal)
{
    // A unica funcao pronta permitida
    ListaDupla *novaLista = criarListaDupla(); 
    
    NoDupla *aux = pontListaOriginal->inicio;
    NoDupla *proximo_aux = NULL;

    while (aux != NULL)
    {
        // Salva o proximo antes de quebrar as ligacoes do "aux"
        proximo_aux = aux->proximo; 

        // Se o valor for impar, remove da original e joga na nova
        if (aux->valor % 2 != 0) 
        {
            // --- PARTE A: DESENGATAR DA LISTA ORIGINAL ---
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

            // --- PARTE B: ENGATAR NA NOVA LISTA (NO FINAL) ---
            aux->proximo = NULL;
            aux->anterior = novaLista->fim;

            // Se a nova lista estiver vazia
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

        // Pula para o proximo elemento da lista original
        aux = proximo_aux; 
    }

    return novaLista;
}