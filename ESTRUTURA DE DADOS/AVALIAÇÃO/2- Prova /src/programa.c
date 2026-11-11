#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prova.h"

int main()
{
    printf("=== Area de testes do aluno ===\n");
    printf("Use este arquivo para testar suas funcoes.\n");
    printf("ATENCAO: A correção será APENAS do arquivo prova.c!\n\n");

    ListaDLI *lista1 = criarListaDLI();
    ListaSLI *lista2 = criarListaSLI();

    inserirFimLDLI(10, lista1);
    inserirFimLDLI(20, lista1);
    inserirFimLDLI(10, lista1);
    mostrarLDLI(lista1);
    ehPalindromoLDLI(lista1);

    inserirInicioLSLI(10,lista2);
    inserirInicioLSLI(20,lista2);
    inserirInicioLSLI(10,lista2);
    mostrarLSLI(lista2);
    moverParaInicioLSLI (20,lista2);
    mostrarLSLI(lista2);

    dividirListaLSLI(2, lista2);
    mostrarLSLI(lista2);   

    destruirLDLI(&lista1);

    return 0;
}