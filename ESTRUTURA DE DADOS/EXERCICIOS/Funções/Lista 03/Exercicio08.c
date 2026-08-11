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

//Crie uma função que receba como parâmetros três matrizes 3x3 de inteiros. A função deve multiplicar a 1a matriz pela 2a matriz na 3a.
void multiplicar_matrizes(int mt[3][3], int mt2[3][3], int mt3[3][3], int min, int max);

int main() {
    int mt[3][3], mt2[3][3], mt3[3][3];
    srand(time(NULL));
    multiplicar_matrizes(mt, mt2, mt3, 2, 20);
    return 0;
}

void multiplicar_matrizes(int mt[3][3], int mt2[3][3], int mt3[3][3], int min, int max) {
    // Gerando matriz 01
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mt[i][j] = rand() % (max - min + 1) + min;
        }
    }
    // Gerando matriz 02
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mt2[i][j] = rand() % (max - min + 1) + min;
        }
    }
    // Mostrando matriz 01
    printf("Matriz 01:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d", mt[i][j]);
        }
        printf("\n");
    }
    // Mostrando matriz 02
    printf("\nMatriz 02:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d", mt2[i][j]);
        }
        printf("\n");
    }
    // Calculando a multiplicação das matrizes
    mt3[0][0] = mt[0][0] * mt2[0][0]
              + mt[0][1] * mt2[1][0]
              + mt[0][2] * mt2[2][0];

    mt3[0][1] = mt[0][0] * mt2[0][1]
              + mt[0][1] * mt2[1][1]
              + mt[0][2] * mt2[2][1];

    mt3[0][2] = mt[0][0] * mt2[0][2]
              + mt[0][1] * mt2[1][2]
              + mt[0][2] * mt2[2][2];


    mt3[1][0] = mt[1][0] * mt2[0][0]
              + mt[1][1] * mt2[1][0]
              + mt[1][2] * mt2[2][0];

    mt3[1][1] = mt[1][0] * mt2[0][1]
              + mt[1][1] * mt2[1][1]
              + mt[1][2] * mt2[2][1];

    mt3[1][2] = mt[1][0] * mt2[0][2]
              + mt[1][1] * mt2[1][2]
              + mt[1][2] * mt2[2][2];


    mt3[2][0] = mt[2][0] * mt2[0][0]
              + mt[2][1] * mt2[1][0]
              + mt[2][2] * mt2[2][0];

    mt3[2][1] = mt[2][0] * mt2[0][1]
              + mt[2][1] * mt2[1][1]
              + mt[2][2] * mt2[2][1];

    mt3[2][2] = mt[2][0] * mt2[0][2]
              + mt[2][1] * mt2[1][2]
              + mt[2][2] * mt2[2][2];

    // Mostrando matriz 03
    printf("\nMatriz 03:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d", mt3[i][j]);
        }
        printf("\n");
    }
}