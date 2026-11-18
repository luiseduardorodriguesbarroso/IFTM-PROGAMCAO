#include "listasimplesmenteligadainteiro.h"

ListaSimples * criarListaSimples()
{
    ListaSimples * novaLista = (ListaSimples *) malloc(sizeof(ListaSimples));
    if (novaLista == NULL)  // erro alocando memoria
    {
        printf("Erro fatal: Falha na alocacao de memoria para a ListaSimples.\n");
        exit(1); // Encerra o programa
    }
    novaLista->inicio = NULL;
    novaLista->tamanho = 0;
    return novaLista;
}

void inserirFimSimples(int valor, ListaSimples * pontLista)
{
    if (pontLista->inicio == NULL)  // VAZIA
    {
        pontLista->inicio = criarNoSimples(valor, NULL);
    }
    else  // 1 OU + DE 1 ELEM
    {
        NoSimples * aux = pontLista->inicio;
        while(aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = criarNoSimples(valor, NULL);
    }
    pontLista->tamanho++;
}

// TAM = 3 | 3 -> 2 -> 7 -> NULL
void mostrarSimples(ListaSimples * pontLista)
{
    if (pontLista->inicio == NULL) //VAZIA
    {
        printf("TAM = 0 | NULL\n");
    }
    else if (pontLista->inicio->proximo == NULL) //1 ELEM
    {
        printf("TAM = 1 | %d -> NULL\n", pontLista->inicio->valor);
    }
    else //+ DE 1 ELEM
    {
        NoSimples * aux = pontLista->inicio;
        printf("TAM = %d | ", pontLista->tamanho);
        while (aux != NULL)
        {
            printf("%d -> ", aux->valor);
            aux = aux->proximo;
        }
        printf("NULL\n");
    }
}

void inserirInicioSimples(int valor, ListaSimples * pontLista)
{
    // VAZIA
    if (pontLista->tamanho == 0) // pontLista->inicio == NULL
    {
        pontLista->inicio = criarNoSimples(valor, NULL);
    }
    else   // 1 ou + DE 1 ELEM
    {
        pontLista->inicio = criarNoSimples(valor, pontLista->inicio);
    }
    pontLista->tamanho++;
}

void limparSimples(ListaSimples *pontLista)
{
    if (pontLista->tamanho > 0) // NAO VAZIA
    { 
        if (pontLista->tamanho > 1)   // + DE 1 ELEM
        {
            NoSimples * aux = pontLista->inicio->proximo;
            while (aux != NULL)
            {
                free(pontLista->inicio);
                pontLista->inicio = aux;
                aux = aux->proximo;
            }
        }
        free(pontLista->inicio);  // // 1 ELEM
        pontLista->inicio = NULL;
        pontLista->tamanho = 0;
    }

}

void destruirSimples(ListaSimples ** pontLista)
{
    limparSimples(*pontLista);
    free(*pontLista);
    *pontLista = NULL;
}



int removerInicioSimples(ListaSimples * pontLista)
{
    if (pontLista->tamanho == 0)  // VAZIA   pontLista->inicio == NULL
    {
        printf("Impossível remover o início de uma lista vazia\n");
        return -1;
    }
    else  // 1 OU + DE 1 ELEM
    {
        int valor = pontLista->inicio->valor;
        NoSimples * aux = pontLista->inicio->proximo;
        free(pontLista->inicio);
        pontLista->inicio = aux;
        pontLista->tamanho--;
        return valor;
    }
}

int removerFimSimples(ListaSimples * pontLista)
{
    if (pontLista->tamanho == 0)  // VAZIA
    {
        printf("Impossível remover o fim de uma lista vazia\n");
        return -1;
    }
    else if (pontLista->tamanho == 1)  // 1 ELEM
    {
        int valor = pontLista->inicio->valor;
        free(pontLista->inicio);
        pontLista->inicio = NULL;
        pontLista->tamanho = 0;
        return valor;
    }
    else  // + DE 1 ELEM
    {
        NoSimples * penult = pontLista->inicio;
        while (penult->proximo->proximo != NULL)
        {
            penult = penult->proximo;
        }
        int valor = penult->proximo->valor;
        free(penult->proximo);
        penult->proximo = NULL;
        pontLista->tamanho--;
        return valor;
    }
}

int obterValorInicioSimples(ListaSimples * pontLista)
{
    if (pontLista->tamanho == 0)  // VAZIA
    {
        printf("Impossível obter o valor do inicio de uma lista vazia\n");
        return -1;
    }
    else  // 1 OU + DE 1 ELEM
    {
        return pontLista->inicio->valor;
    }
}

int obterValorFimSimples(ListaSimples * pontLista)
{
    if (pontLista->tamanho == 0)  // VAZIA
    {
        printf("Impossível obter o valor do fim de uma lista vazia\n");
        return -1;
    }
    else  // 1 OU + DE 1 ELEM
    {
        NoSimples * ult = pontLista->inicio;
        while (ult->proximo != NULL)
        {
            ult = ult->proximo;
        }
        return ult->valor;
    }
}

int trocarValorInicioSimples(int valor, ListaSimples * pontLista)
{
    if (pontLista->tamanho == 0)  // VAZIA
    {
        printf("Impossível trocar o valor do inicio de uma lista vazia\n");
        return 0;
    }
    else   // 1 OU + DE 1 ELEM
    {
        pontLista->inicio->valor = valor;
        return 1;
    }
}

int trocarValorFimSimples(int valor, ListaSimples * pontLista)
{
    if (pontLista->tamanho == 0)  // VAZIA
    {
        printf("Impossível trocar o valor do fim de uma lista vazia\n");
        return 0;
    }
    else  // 1 OU + DE 1 ELEM
    {
        NoSimples * ult = pontLista->inicio;
        while (ult->proximo != NULL)
        {
            ult = ult->proximo;
        }
        ult->valor = valor;
        return 1;
    }
}


// Deve inserir esse valor nessa posicao, "deslocando" os elementos
// para a direita
// TAM = 3 | 3 -> 7 -> 5 -> NULL
//           0    1    2  (posicao)
// posicao negativa -> avisar o usuario, nao inserir e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao inserir e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, inserirPosicao(9, 1, lista)
// TAM = 4 | 3 -> 9 -> 7 -> 5 -> NULL, return 1
int inserirPosicaoSimples(int valor, int posicao, ListaSimples * pontLista)
{
    if (pontLista->tamanho == 0)
    {
        printf("Impossível inserir em uma posição de uma lista vazia\n");
        return 0;
    }
    if (posicao < 0 || posicao > pontLista->tamanho - 1)
    {
        printf("Valor de posição inválida. Valores válidos entre 0 e %d\n", pontLista->tamanho - 1);
        return 0;
    }
    // Inserir
    if (posicao == 0) {  // Primeira posicao
        pontLista->inicio = criarNoSimples(valor, pontLista->inicio);
    }
    else {   // Ultima posicao ou Posicao no meio
        NoSimples * pont = pontLista->inicio;
        for (int cont = 0; cont < posicao - 1; cont++) {
            pont = pont->proximo;
        }
        pont->proximo = criarNoSimples(valor, pont->proximo);
    }
    pontLista->tamanho++;
    return 1;
}

// lista vazia -> avisar o usuario que esta vazia e retornar 0
// posicao negativa -> avisar o usuario e retornar 0
// posicao > (tamanho -1) -> avisar o usuario e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, obterPosicao(1, lista)
// TAM = 3 | 3 -> 7 -> 5 -> NULL, return 7
int obterValorPosicaoSimples(int posicao, ListaSimples * pontLista) 
{
    if (pontLista->tamanho == 0)
    {
        printf("Impossível obter o valor de uma posição de uma lista vazia\n");
        return 0;
    }
    if (posicao < 0 || posicao > pontLista->tamanho - 1)
    {
        printf("Valor de posição inválida. Valores válidos entre 0 e %d\n", pontLista->tamanho - 1);
        return 0;
    }
    NoSimples * pont = pontLista->inicio;
    for (int cont = 0; cont < posicao; cont++) 
    {
        pont = pont->proximo;
    }
    return pont->valor;
}