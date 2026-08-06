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

//rie uma função em C que recebe como parâmetros um vetor de inteiros e seu tamanho. A função deve retornar 1 caso os elementos estejam em ordem crescente, 2 caso os elementos estejam em ordem decrescente e 0 caso estejam fora de ordem.
int verificarordem(int vetor[], int tamanho, int min, int max);

int main() {
    int vt[5];
    int resultado;

    srand(time(NULL));

    resultado = verificarordem(vt, 5, 2, 20);

    if (resultado == 1) {
        printf("\nO vetor esta em ordem crescente.\n");
    } else if (resultado == 2) {
        printf("\nO vetor esta em ordem decrescente.\n");
    } else {
        printf("\nO vetor esta fora de ordem.\n");
    }
    return 0;
}

int verificarordem(int vetor[], int tamanho, int min, int max) {
    int crescente = 1;
    int decrescente = 1;

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (max - min + 1) + min;
    }

    printf("\nIndice:");
    for (int i = 0; i < tamanho; i++) {
        printf("%5d", i);
    }

    printf("\nVetor :");
    for (int i = 0; i < tamanho; i++) {
        printf("%5d", vetor[i]);
    }

    printf("\n");

    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            crescente = 0;
        }

        if (vetor[i] < vetor[i + 1]) {
            decrescente = 0;
        }
    }

    if (crescente) {
        return 1;
    }
    if (decrescente) {
        return 2;
    }
    return 0;
}