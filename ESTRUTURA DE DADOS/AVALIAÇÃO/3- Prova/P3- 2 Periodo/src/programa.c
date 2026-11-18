#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/filai.h"
#include "../include/prova.h"

int main()
{
    FilaI * fila = criarFilaI();

    mostrarFilaI(fila);

    enfileirarI(2, fila);
    printf("Próximo: %d\n", proximoI(fila));
    enfileirarI(7, fila);
    printf("Próximo: %d\n", proximoI(fila));
    enfileirarI(4, fila);
    printf("Próximo: %d\n", proximoI(fila));
    enfileirarI(12, fila);
    printf("Próximo: %d\n", proximoI(fila));
    enfileirarI(6, fila);
    printf("Próximo: %d\n", proximoI(fila));
    mostrarFilaI(fila);

    printf("Desinfileirou: %d\n", desinfileirarI(fila));
    printf("Próximo: %d\n", proximoI(fila));
    mostrarFilaI(fila);
    printf("Desinfileirou: %d\n", desinfileirarI(fila));
    printf("Próximo: %d\n", proximoI(fila));
    mostrarFilaI(fila);
    printf("Desinfileirou: %d\n", desinfileirarI(fila));
    printf("Próximo: %d\n", proximoI(fila));
    mostrarFilaI(fila);
    printf("Desinfileirou: %d\n", desinfileirarI(fila));
    printf("Próximo: %d\n", proximoI(fila));
    mostrarFilaI(fila);
    printf("Desinfileirou: %d\n", desinfileirarI(fila));
    printf("Próximo: %d\n", proximoI(fila));
    mostrarFilaI(fila);
    printf("Desinfileirou: %d\n", desinfileirarI(fila));

    enfileirarI(2, fila);
    enfileirarI(7, fila);
    enfileirarI(4, fila);
    enfileirarI(12, fila);
    enfileirarI(6, fila);
    mostrarFilaI(fila);

    inverterPrimeirosKFilaI(3,fila);//Eu que adcionei

    mostrarFilaI(fila);
    limparFilaI(fila);
    mostrarFilaI(fila);


    destruirFilaI(&fila);
    return 0;
}