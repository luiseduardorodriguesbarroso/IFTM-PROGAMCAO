#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listasimplesmenteligadainteiro.h"
#include "listaduplamenteligadainteiros.h"
#include "pilha.h"
#include "fila.h"
#include "questoes.h"


// USE ESSE ARQUIVO APENAS PARA TESTAR SUAS FUNCOES

// A SOLUCAO QUE SERA AVALIADA DEVE ESTAR NO ARQUIVO questoes.c


int main()
{
    Fila *f = criarFila();
    Pilha *v = criarPilha();
    Pilha *a = criarPilha();

    //empilhar(1, v);
    //empilhar(2, v);
    empilhar(4, a);
    empilhar(3, a);

    mostrarPilha(v);
    mostrarPilha(a);

    clicar_voltar(v, a);

    mostrarPilha(v);
    mostrarPilha(a);
    
    return 0;
}