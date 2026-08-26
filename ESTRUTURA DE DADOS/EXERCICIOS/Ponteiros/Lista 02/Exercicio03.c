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

//3) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro, seu tamanho, um valor máximo e um valor mínimo. A função deve preencher o vetor com números aleatórios dentro dessa faixa de valores. Use o operador de índice no ponteiro.

void preencher_vet(int *vet, int tamanho, int min, int max);



int main() {
    
    int vet[10];
    srand(time(NULL));

    preencher_vet(vet,10,3,20);

    return 0;
}

void preencher_vet(int *vet, int tamanho, int min, int max){
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % (max - min + 1) + min;
    }
    for (int i = 0; i < tamanho; i++)
    {
        printf("%5d",vet[i]);
    }
    
}