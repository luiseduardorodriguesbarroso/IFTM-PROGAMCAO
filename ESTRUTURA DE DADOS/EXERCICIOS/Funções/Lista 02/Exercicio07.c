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

//Crie uma função em C que recebe como parâmetros um vetor de inteiros, seu tamanho e um valor inteiro. A função deve retornar o índice do elemento do vetor com esse valor ou -1 caso ele não exista no vetor.
int mostrarindice(int vetor[], int tamanho, int min, int max);

int main() {
    int vt[5];
    int indice;

    srand(time(NULL));

    indice = mostrarindice(vt, 5, 2, 20);

    if (indice == -1) {
        printf("\nValor nao encontrado.\n");
    } else {
        printf("\nValor encontrado na posicao %d.\n", indice);
    }
    return 0;
}

int mostrarindice(int vetor[], int tamanho, int min, int max) {
    int valor;

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

    printf("\n\nInforme o valor que deseja procurar: ");
    scanf("%d", &valor);

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}