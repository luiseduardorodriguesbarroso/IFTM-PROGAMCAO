#include <stdio.h>
#include <stdlib.h>

// ==========================================
// ESTRUTURAS
// ==========================================

typedef struct nodupla
{
    int valor;
    struct nodupla *anterior;
    struct nodupla *proximo;

} NoDupla;

typedef struct
{
    NoDupla *inicio;
    NoDupla *fim;
    int tamanho;

} ListaDupla;

// ==========================================
// CRIAR NÓ
// ==========================================

NoDupla *criarNoDupla(int valor)
{
    NoDupla *novo = (NoDupla *)malloc(sizeof(NoDupla));

    if (novo == NULL)
    {
        printf("Erro de memoria\n");
        exit(1);
    }

    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = NULL;

    return novo;
}

// ==========================================
// CRIAR LISTA
// ==========================================

ListaDupla *criarListaDupla()
{
    ListaDupla *lista = (ListaDupla *)malloc(sizeof(ListaDupla));

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;

    return lista;
}

// ==========================================
// INSERIR NO FINAL
// (apenas para testes)
// ==========================================

void inserirFim(int valor, ListaDupla *lista)
{
    NoDupla *novo = criarNoDupla(valor);

    // lista vazia
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
        lista->fim = novo;
    }
    else
    {
        novo->anterior = lista->fim;

        lista->fim->proximo = novo;

        lista->fim = novo;
    }

    lista->tamanho++;
}

// ==========================================
// MOSTRAR LISTA
// ==========================================

void mostrarDupla(ListaDupla *lista)
{
    NoDupla *aux = lista->inicio;

    printf("TAM = %d | NULL <=> ", lista->tamanho);

    while (aux != NULL)
    {
        printf("%d <=> ", aux->valor);

        aux = aux->proximo;
    }

    printf("NULL\n");
}

// ==========================================
// QUESTÃO 1
// CONCATENAR
// ==========================================

void concatenarDuplas(ListaDupla *l1, ListaDupla *l2)
{
    // l2 vazia
    if (l2->tamanho == 0)
    {
        return;
    }

    // l1 vazia
    if (l1->tamanho == 0)
    {
        l1->inicio = l2->inicio;
        l1->fim = l2->fim;
        l1->tamanho = l2->tamanho;
    }
    else
    {
        // liga as listas

        l1->fim->proximo = l2->inicio;

        l2->inicio->anterior = l1->fim;

        l1->fim = l2->fim;

        l1->tamanho += l2->tamanho;
    }

    // esvazia l2

    l2->inicio = NULL;
    l2->fim = NULL;
    l2->tamanho = 0;
}

// ==========================================
// QUESTÃO 2
// REMOVER POSIÇÃO
// ==========================================

int removerPosicaoDupla(int posicao, ListaDupla *lista)
{
    // lista vazia

    if (lista->tamanho == 0)
    {
        printf("Lista vazia\n");
        return -1;
    }

    // posição inválida

    if (posicao < 0 || posicao >= lista->tamanho)
    {
        printf("Posicao invalida\n");
        return -1;
    }

    NoDupla *aux = lista->inicio;

    int i;

    for (i = 0; i < posicao; i++)
    {
        aux = aux->proximo;
    }

    int valor = aux->valor;

    // único elemento

    if (lista->tamanho == 1)
    {
        lista->inicio = NULL;
        lista->fim = NULL;
    }

    // remove início

    else if (aux == lista->inicio)
    {
        lista->inicio = aux->proximo;

        lista->inicio->anterior = NULL;
    }

    // remove fim

    else if (aux == lista->fim)
    {
        lista->fim = aux->anterior;

        lista->fim->proximo = NULL;
    }

    // remove meio

    else
    {
        aux->anterior->proximo = aux->proximo;

        aux->proximo->anterior = aux->anterior;
    }

    free(aux);

    lista->tamanho--;

    return valor;
}

// ==========================================
// QUESTÃO 3
// EXTRAIR ÍMPARES
// ==========================================

ListaDupla *extrairImparesDupla(ListaDupla *original)
{
    ListaDupla *nova = criarListaDupla();

    NoDupla *aux = original->inicio;

    while (aux != NULL)
    {
        NoDupla *prox = aux->proximo;

        // se for ímpar

        if (aux->valor % 2 != 0)
        {
            // REMOVE DA ORIGINAL

            // único elemento

            if (original->tamanho == 1)
            {
                original->inicio = NULL;
                original->fim = NULL;
            }

            // início

            else if (aux == original->inicio)
            {
                original->inicio = aux->proximo;

                original->inicio->anterior = NULL;
            }

            // fim

            else if (aux == original->fim)
            {
                original->fim = aux->anterior;

                original->fim->proximo = NULL;
            }

            // meio

            else
            {
                aux->anterior->proximo = aux->proximo;

                aux->proximo->anterior = aux->anterior;
            }

            original->tamanho--;

            // LIMPA PONTEIROS

            aux->anterior = NULL;
            aux->proximo = NULL;

            // INSERE NA NOVA LISTA

            if (nova->tamanho == 0)
            {
                nova->inicio = aux;
                nova->fim = aux;
            }
            else
            {
                aux->anterior = nova->fim;

                nova->fim->proximo = aux;

                nova->fim = aux;
            }

            nova->tamanho++;
        }

        aux = prox;
    }

    return nova;
}

// ==========================================
// LIMPAR
// ==========================================

void limparDupla(ListaDupla *lista)
{
    NoDupla *aux = lista->inicio;

    while (aux != NULL)
    {
        NoDupla *prox = aux->proximo;

        free(aux);

        aux = prox;
    }

    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

// ==========================================
// MAIN
// ==========================================

int main()
{
    ListaDupla *l1 = criarListaDupla();
    ListaDupla *l2 = criarListaDupla();

    inserirFim(10, l1);
    inserirFim(20, l1);
    inserirFim(30, l1);

    inserirFim(40, l2);
    inserirFim(50, l2);
    inserirFim(60, l2);

    printf("\nL1:\n");
    mostrarDupla(l1);

    printf("\nL2:\n");
    mostrarDupla(l2);

    // QUESTÃO 1
    concatenarDuplas(l1, l2);

    printf("\nDepois da concatenacao:\n");

    mostrarDupla(l1);
    mostrarDupla(l2);

    // QUESTÃO 2
    printf("\nRemovido: %d\n", removerPosicaoDupla(2, l1));

    mostrarDupla(l1);

    // QUESTÃO 3

    ListaDupla *impares = extrairImparesDupla(l1);

    printf("\nLista original:\n");
    mostrarDupla(l1);

    printf("\nLista de impares:\n");
    mostrarDupla(impares);

    limparDupla(l1);
    limparDupla(l2);
    limparDupla(impares);

    free(l1);
    free(l2);
    free(impares);

    return 0;
}