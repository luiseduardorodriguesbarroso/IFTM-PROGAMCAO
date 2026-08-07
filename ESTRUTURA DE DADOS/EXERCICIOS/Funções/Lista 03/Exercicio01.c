#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>
#include <assert.h>

// Crie uma função que receba como parâmetros uma matriz 3x3 de inteiros, um valor máximo e um valor mínimo. A função deve preencher a matriz com valores aleatórios dentro dessa faixa.
void preencherVetor(int matriz[3][3], int min, int max);

int main() {
    int vt[3][3];
    srand(time(NULL));

    preencherVetor(vt, 3, 20);

    return 0;
}

void preencherVetor(int matriz[3][3], int min, int max) {
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = rand() % (max - min + 1) + min;
        }
    }

    printf("Matriz gerada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}