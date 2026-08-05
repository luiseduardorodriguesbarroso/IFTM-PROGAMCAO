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

//Crie uma função em C que recebe como parâmetros um vetor de inteiros, seu tamanho, um valor máximo e um valor mínimo. A função deve preencher o vetor com números aleatórios dentro dessa faixa de valores.
void preencherVetor(int vetor[], int tamanho, int min, int max);

int main() {
    int vt[10];
    srand(time(NULL));

    preencherVetor(vt,10,3,50);
    
    return 0;
}

void preencherVetor(int vetor[], int tamanho, int min, int max) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (max - min + 1) + min;
    }
    printf("Vetor gerado:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}