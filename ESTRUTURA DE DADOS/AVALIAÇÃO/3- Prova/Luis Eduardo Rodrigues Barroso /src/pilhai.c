#include "pilhai.h"

PilhaI * criarPilhaI()
{
    PilhaI * nova = (PilhaI *) malloc(sizeof(PilhaI));
    if (nova == NULL)   // ERRO alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para a PilhaI.\n");
        exit(1);
    }
    nova->tamanho = 0;
    nova->topo = NULL;
    return nova;
}

void limparPilhaI(PilhaI * pontPilha)
{
    if (pontPilha->tamanho > 0)
    {
        NoSLI * pontAux1, *pontAux2;
        pontAux1 = pontPilha->topo;
        pontAux2 = pontAux1->proximo;
        while(pontAux2 != NULL)
        {
            free(pontAux1);
            pontAux1 = pontAux2;
            pontAux2 = pontAux2->proximo;
        }
        free(pontAux1);
        pontPilha->tamanho = 0;
        pontPilha->topo = NULL;
    }
}

void destruirPilhaI(PilhaI ** pontPontPilha)
{
    limparPilhaI(*pontPontPilha);
    free(*pontPontPilha);
    *pontPontPilha = NULL;
}

// Tamanho = 0, Vazia
// Tamanho = 5, (T)6 -> 12 -> 4 -> 7 -> 2 -> NULL
void mostrarPilhaI(PilhaI * pontPilha)
{
    printf("Tamanho = %d, ", pontPilha->tamanho);
    if (pontPilha->tamanho == 0) // VAZIA
    {
        printf("Vazia\n");
    }
    else  // 1 OU + DE 1 ELEM
    {
        NoSLI * pontAux = pontPilha->topo;
        printf("(T)");
        while(pontAux != NULL)
        {
            printf("%d -> ", pontAux->valor);
            pontAux = pontAux->proximo;
        }
        printf("NULL\n");
    }
}

void empilharI(int valor, PilhaI * pontPilha)
{
    NoSLI * novo;
    if (pontPilha->tamanho == 0)  // VAZIA
    {
        novo = criarNoSLI(valor, NULL);
    }
    else  // 1 OU + DE 1 ELEMENTO
    {
        novo = criarNoSLI(valor, pontPilha->topo);
    }
    pontPilha->topo = novo;
    pontPilha->tamanho++;
}

int desempilharI(PilhaI * pontPilha)
{
    if (pontPilha->tamanho == 0)
    {
        printf("Impossivel desempilhar uma pilha vazia\n");
        return 0;
    }
    else 
    {
        NoSLI * pontAux = pontPilha->topo;
        pontPilha->topo = pontAux->proximo;
        free(pontAux);
        pontPilha->tamanho--;
        return 1;
    }
}

int topoI(PilhaI * pontPilha)
{
    if (pontPilha->tamanho == 0) 
    {
        printf("Impossivel obter o topo de uma pilha vazia\n");
        return 0;
    }
    else
    {
        return pontPilha->topo->valor;
    }
}