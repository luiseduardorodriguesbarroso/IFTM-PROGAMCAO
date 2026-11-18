#ifndef LISTADUPLAMENTELIGADAINTEIROS
#define LISTADUPLAMENTELIGADAINTEIROS 1

#include <stdlib.h>
#include <stdio.h>
#include "nodupla.h"

typedef struct listadupla {
    NoDupla * inicio;
    NoDupla * fim;
    int tamanho;
} ListaDupla;

ListaDupla * criarListaDupla();
void inserirInicioDupla(int valor, ListaDupla * pontLista);
void inserirFimDupla(int valor, ListaDupla * pontLista);
int removerInicioDupla(ListaDupla * pontLista);
int removerFimDupla(ListaDupla * pontLista);

int obterValorInicioDupla(ListaDupla * pontLista);
int obterValorFimDupla(ListaDupla * pontLista);
int trocarValorInicioDupla(int valor, ListaDupla * pontLista);
int trocarValorFimDupla(int valor, ListaDupla * pontLista);

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
int inserirPosicaoDupla(int valor, int posicao, ListaDupla * pontLista);

// lista vazia -> avisar o usuario que esta vazia, nao remover e retornar 0
// posicao negativa -> avisar o usuario, nao remover e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao remover e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, removerPosicao(1, lista)
// TAM = 2 | 3 -> 5 -> NULL, return 1
// int removerPosicaoDupla(int posicao, ListaDupla * pontLista);

// lista vazia -> avisar o usuario que esta vazia, nao trocar e retornar 0
// posicao negativa -> avisar o usuario, nao trocar e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao trocar e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, trocarPosicao(8, 1, lista)
// TAM = 3 | 3 -> 8 -> 5 -> NULL, return 1
// int trocarValorPosicaoDupla(int valor, int posicao, ListaDupla * pontLista);

// lista vazia -> avisar o usuario que esta vazia e retornar 0
// posicao negativa -> avisar o usuario e retornar 0
// posicao > (tamanho -1) -> avisar o usuario e retornar 0
// posicao valida:
// TAM = 3 | 3 -> 7 -> 5 -> NULL, obterPosicao(1, lista)
// TAM = 3 | 3 -> 7 -> 5 -> NULL, return 7
int obterValorPosicaoDupla(int posicao, ListaDupla * pontLista);

void mostrarDupla(ListaDupla * pontLista);
void mostrarInvertidoDupla(ListaDupla * pontLista);
void limparDupla(ListaDupla *pontLista);
void destruirDupla(ListaDupla ** pontLista);

#endif