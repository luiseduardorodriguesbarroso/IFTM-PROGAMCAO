#include <stdio.h>
#include <stdlib.h>
#include "pilha_fila.h"

int main() {

    FilaLSLI *fila = criarFilaLSLI();

    inserirFilaLSLI(10,fila);
    inserirFilaLSLI(20,fila);
    inserirFilaLSLI(30,fila);

    mostrarFilaLSLI(fila);

    printf("\nPrograma finalizado com sucesso!\n");
    return 0;
}
