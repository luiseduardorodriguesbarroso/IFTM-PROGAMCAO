#ifndef QUESTOES_H
#define QUESTOES_H 1

#include <stdlib.h>
#include <stdio.h>
#include "nodupla.h"

typedef struct listadupla {
    NoDupla * inicio;
    NoDupla * fim;
    int tamanho;
} ListaDupla;

ListaDupla * criarListaDupla();
void mostrarDupla(ListaDupla * pontLista);
void mostrarInvertidoDupla(ListaDupla * pontLista);
void limparDupla(ListaDupla *pontLista);
void destruirDupla(ListaDupla ** pontLista);

// 1) Concatenação de Listas
void concatenarDuplas(ListaDupla *l1, ListaDupla *l2);

//Regras: 
//A função deve emendar a l2 no final da l1.
//Restrição Crítica: É proibido iterar sobre a l2 inserindo nó por nó na l1. A concatenação deve ser feita manipulando diretamente os ponteiros da l1 e da l2.
//Ao final, l1 deve conter todos os elementos e a l2 deve estar vazia.
//Ex:
//Antes
//Tam = 3, NULL <=> 10 <=> 20 <=> 30 <=> NULL  // L1
//Tam = 3, NULL <=> 40 <=> 50 <=> 60 <=> NULL  // L2
//Depois
//Tam = 6, NULL <=> 10 <=> 20 <=> 30 <=> 40 <=> 50 <=> 60 <=> NULL  // L1
//Tam = 0, NULL  // L2

// 2) Remoção no Meio
int removerPosicaoDupla(int posicao, ListaDupla * pontLista);

// lista vazia -> avisar o usuario que esta vazia e retornar -1
// posicao negativa -> avisar o usuario e retornar -1
// posicao > (tamanho -1) -> avisar o usuario e retornar -1
// posicao valida:
// TAM = 3 | NULL <=> 3 <=> 7 <=> 5 <=> NULL, removerPosicaoDupla(1, lista)
// TAM = 2 | NULL <=> 3 <=> 5 <=> NULL, return 7

// 3) Extração com Condição
ListaDupla * extrairImparesDupla(ListaDupla * pontListaOriginal);
// Regras:
// A função deve varrer a lista original, remover os nós ímpares e reconectá-los em uma nova lista que deve ser retornada .
// Restrição Crítica: É terminantemente proibido utilizar qualquer função pronta (como inserirFim, removerPosicao, etc.).
// A função deve manipular os ponteiros manualmente para desengatar o nó de uma lista e engatar na outra.
// A única coisa que pode ser criada é a nova lista (que será retornada) usando a função criarListaDupla.
// Antes
//Tam = 6, NULL <=> 3 <=> 6 <=> 9 <=> 11 <=> 16 <=> 20 <=> NULL  // pontListaOriginal
// Depois
//Tam = 3, NULL <=> 6 <=> 16 <=> 20 <=> NULL  // pontListaOriginal 
//Tam = 3, NULL <=> 3 <=> 9 <=> 11 <=> <=> NULL  // nova lista retornada

#endif