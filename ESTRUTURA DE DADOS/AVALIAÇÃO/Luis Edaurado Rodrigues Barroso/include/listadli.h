#ifndef LISTADLI_H
#define LISTADLI_H 1

#include <stdlib.h>
#include <stdio.h>
#include "nodli.h"

typedef struct listadupla_int
{
    NoDLI * inicio;
    NoDLI * fim;
    int tamanho;
} ListaDLI;

ListaDLI * criarListaDLI();
void mostrarLDLI(ListaDLI *pontLista);
void mostrarInvertidaLDLI(ListaDLI *pontLista);
void limparLDLI(ListaDLI *pontLista);
void destruirLDLI(ListaDLI **pontPontLista);

void inserirInicioLDLI(int valor, ListaDLI *pontLista);
void inserirFimLDLI(int valor, ListaDLI *pontLista);

int removerInicioLDLI(ListaDLI *pontLista);
int removerFimLDLI(ListaDLI *pontLista);

int obterValorInicioLDLI(ListaDLI *pontLista);
int obterValorFimLDLI(ListaDLI *pontLista);
int obterValorPosicaoLDLI(int posicao, ListaDLI *pontLista);

int trocarValorInicioLDLI(int valor, ListaDLI *pontLista);
int trocarValorFimLDLI(int valor, ListaDLI *pontLista);

// Deve inserir esse valor nessa posicao, "deslocando" os elementos
// para a direita
// TAM = 3 | NULL <- 3 <-> 7 <-> 5 -> NULL
//                   0    1    2  (posicao)
// lista vazia -> avisar o usuario que esta vazia, nao inserir e retornar 0
// posicao negativa -> avisar o usuario, nao inserir e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao inserir e retornar 0
// posicao valida:
// TAM = 3 | NULL <- 3 <-> 7 <-> 5 -> NULL, inserirPosicao(9, 1, lista)
// TAM = 4 | NULL <- 3 <-> 9 <-> 7 <-> 5 -> NULL, return 1
// int inserirPosicaoLDLI(int valor, int posicao, ListaDLI * pontLista);

// lista vazia -> avisar o usuario que esta vazia, nao remover e retornar 0
// posicao negativa -> avisar o usuario, nao remover e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao remover e retornar 0
// posicao valida:
// TAM = 3 | NULL <- 3 <-> 7 <-> 5 -> NULL, removerPosicao(1, lista)
// TAM = 2 | NULL <- 3 <-> 5 -> NULL, return 1
// int removerPosicaoLDLI(int posicao, ListaDLI * pontLista);

// lista vazia -> avisar o usuario que esta vazia, nao trocar e retornar 0
// posicao negativa -> avisar o usuario, nao trocar e retornar 0
// posicao > (tamanho -1) -> avisar o usuario, nao trocar e retornar 0
// posicao valida:
// TAM = 3 | NULL <- 3 <-> 7 <-> 5 -> NULL, trocarPosicao(8, 1, lista)
// TAM = 3 | NULL <- 3 <-> 8 <-> 5 -> NULL, return 1
// int trocarValorPosicaoLDLI(int valor, int posicao, ListaDLI * pontLista);

#endif