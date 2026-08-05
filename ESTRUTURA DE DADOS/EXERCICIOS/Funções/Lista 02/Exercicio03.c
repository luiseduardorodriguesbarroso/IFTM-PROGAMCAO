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
//Crie uma função em C que recebe como parâmetros um vetor de inteiros e seu tamanho. A função deve calcular e retornar a média dos valores do vetor.
void calcular(int vetor[],int tamanho, int min, int max);

int main() {
    srand(time(NULL));
    int vt[10];
    calcular(vt,8,2,50);
    return 0;
}

void calcular(int vetor[], int tamanho, int min, int max) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (max - min + 1) + min;
    }
    printf("Vetor gerado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    float media=0;
    for (int i = 0; i < tamanho; i++)
    {
        media += vetor[i]; 
    }
    media = media / tamanho;
    printf("Media do Vetor: %.2f",media);
}