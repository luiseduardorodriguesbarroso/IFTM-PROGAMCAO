#include "pilha.h"

Pilha *criarPilha()
{
    Pilha *nova = (Pilha *)malloc(sizeof(Pilha));
    if (nova == NULL) // erro alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para a Pilha.\n");
        exit(1); // Encerra o programa
    }
    nova->topo = NULL;
    nova->tamanho = 0;
    return nova;
}

void empilhar(int valor, Pilha *pontPilha)
{
    // VAZIA, 1 ELEM OU MAIS DE 1 ELEM
    pontPilha->topo = criarNoSimples(valor, pontPilha->topo);
    pontPilha->tamanho++;
}

void mostrarPilha(Pilha *pontPilha)
{
    // VAZIA, 1 OU MAIS DE 1 ELEM
    printf("TAM = %d, T[", pontPilha->tamanho);
    NoSimples *pont = pontPilha->topo;
    while (pont != NULL)
    {
        printf("%d", pont->valor);
        if (pont->proximo != NULL)
        {
            printf(" <- ");
        }
        pont = pont->proximo;
    }
    printf("]\n");
}

int topo(Pilha * pontPilha)
{
    if (pontPilha->tamanho == 0)  // VAZIA
    {
        printf("Impossivel obter o topo de uma pilha vazia\n");
        return 0;
    }
    else  // 1 OU MAIS DE UM ELEMENTO
    {
        return pontPilha->topo->valor;
    }
}

int desempilhar(Pilha * pontPilha)
{
    int valor = 0;
    if (pontPilha->tamanho == 0)  // VAZIA
    {
        printf("Impossivel desempilhar de uma pilha vazia\n");
    }
    else 
    {
        valor = pontPilha->topo->valor;
        if (pontPilha->tamanho == 1)  // 1 ELEM
        {
            free(pontPilha->topo);
            pontPilha->topo = NULL;
        } else  // MAIS DE 1 ELEM
        {
            NoSimples * pont = pontPilha->topo;
            pontPilha->topo = pontPilha->topo->proximo;
            free(pont);
        }
        pontPilha->tamanho--;
    }
    return valor;
}

void limparPilha(Pilha * pontPilha)
{
    if (pontPilha->tamanho > 0)  // 1 OU MAIS DE 1 ELEM
    {
        NoSimples * pont1, * pont2;
        pont1 = pontPilha->topo;
        pont2 = pont1->proximo;
        while (pont1->proximo != NULL)
        {
            free(pont1);
            pont1 = pont2;
            pont2 = pont2->proximo;
        }
        free(pont1);
        pontPilha->topo = NULL;
        pontPilha->tamanho = 0;
    }
}

void destruirPilha(Pilha ** pontPilha)
{
    limparPilha(*pontPilha);
    free(*pontPilha);
    *pontPilha = NULL;
}