#ifndef LISTASLI_H
#define LISTASLI_H 1

#include "nosli.h"

typedef struct listasimples_int
{
    NoSLI * inicio;
    int tamanho;
} ListaSLI;

ListaSLI * criarListaSLI();
void limparLSLI(ListaSLI * pontLista);
void destruirLSLI(ListaSLI ** pontPontLista);
void mostrarLSLI(ListaSLI * pontLista);

void inserirFimLSLI(int valor, ListaSLI * pontLista);
void inserirInicioLSLI(int valor, ListaSLI * pontLista);

// Retornam o valor
int obterValorInicioLSLI(ListaSLI * pontLista);
int obterValorFimLSLI(ListaSLI * pontLista);

// Retornam 1 se deu certo e 0 caso contrario
int removerInicioLSLI(ListaSLI * pontLista);
int removerFimLSLI(ListaSLI * pontLista);

// Retornam 1 se deu certo e 0 caso contrario
int trocarValorInicioLSLI(int valor, ListaSLI * pontLista);
int trocarValorFimLSLI(int valor, ListaSLI * pontLista);


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
int inserirPosicaoLSLI(int valor, int posicao, ListaSLI * pontLista);

// lista vazia -> avisar o usuario que esta vazia, nao remover e retornar 0
// posicao negativa -> avisar o usuario, nao remover e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao remover e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, removerPosicao(1, lista)
// TAM = 2 | 3 -> 5 -> NULL, return 1
// int removerPosicaoLSLI(int posicao, ListaSLI * pontLista);

// lista vazia -> avisar o usuario que esta vazia, nao trocar e retornar 0
// posicao negativa -> avisar o usuario, nao trocar e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao trocar e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, trocarPosicao(8, 1, lista)
// TAM = 3 | 3 -> 8 -> 5 -> NULL, return 1
// int trocarValorPosicaoLSLI(int valor, int posicao, ListaSLI * pontLista);

// lista vazia -> avisar o usuario que esta vazia e retornar 0
// posicao negativa -> avisar o usuario e retornar 0
// posicao > (tamanho -1) -> avisar o usuario e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, obterPosicao(1, lista)
// TAM = 3 | 3 -> 7 -> 5 -> NULL, return 7
// int obterValorPosicaoLSLI(int posicao, ListaSLI * pontLista);

#endif