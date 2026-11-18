#ifndef LISTASIMPLESMENTELIGADAINTEIRO
#define LISTASIMPLESMENTELIGADAINTEIRO 1

#include <stdlib.h>
#include <stdio.h>
#include "nosimples.h"

typedef struct listasimples {
    NoSimples * inicio;
    int tamanho;
} ListaSimples;

ListaSimples * criarListaSimples();
void inserirInicioSimples(int valor, ListaSimples * pontLista);
void inserirFimSimples(int valor, ListaSimples * pontLista);
int removerInicioSimples(ListaSimples * pontLista);
int removerFimSimples(ListaSimples * pontLista);
int obterValorInicioSimples(ListaSimples * pontLista);
int obterValorFimSimples(ListaSimples * pontLista);
int trocarValorInicioSimples(int valor, ListaSimples * pontLista);
int trocarValorFimSimples(int valor, ListaSimples * pontLista);

// Deve inserir esse valor nessa posicao, "deslocando" os elementos
// para a direita
// TAM = 3 | 3 -> 7 -> 5 -> NULL
//           0    1    2  (posicao)
// lista vazia -> avisar o usuario que esta vazia, nao inserir e retornar 0
// posicao negativa -> avisar o usuario, nao inserir e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao inserir e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, inserirPosicao(9, 1, lista)
// TAM = 4 | 3 -> 9 -> 7 -> 5 -> NULL, return 1
int inserirPosicaoSimples(int valor, int posicao, ListaSimples * pontLista);

// lista vazia -> avisar o usuario que esta vazia, nao remover e retornar 0
// posicao negativa -> avisar o usuario, nao remover e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao remover e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, removerPosicao(1, lista)
// TAM = 2 | 3 -> 5 -> NULL, return 1
// int removerPosicaoSimples(int posicao, ListaSimples * pontLista);

// lista vazia -> avisar o usuario que esta vazia, nao trocar e retornar 0
// posicao negativa -> avisar o usuario, nao trocar e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao trocar e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, trocarPosicao(8, 1, lista)
// TAM = 3 | 3 -> 8 -> 5 -> NULL, return 1
// int trocarValorPosicaoSimples(int valor, int posicao, ListaSimples * pontLista);

// lista vazia -> avisar o usuario que esta vazia e retornar 0
// posicao negativa -> avisar o usuario e retornar 0
// posicao > (tamanho -1) -> avisar o usuario e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, obterPosicao(1, lista)
// TAM = 3 | 3 -> 7 -> 5 -> NULL, return 7
int obterValorPosicaoSimples(int posicao, ListaSimples * pontLista);

void mostrarSimples(ListaSimples * pontLista);
void limparSimples(ListaSimples *pontLista);
void destruirSimples(ListaSimples ** pontLista);

#endif


