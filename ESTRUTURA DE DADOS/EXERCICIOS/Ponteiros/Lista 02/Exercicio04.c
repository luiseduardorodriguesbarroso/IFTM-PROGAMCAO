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

//4) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve calcular e retornar a média dos valores do vetor. Use aritmética de ponteiros alterando o ponteiro.

float media_vet(int *vet,int tamanho);

int main() {
    
    int vet[10] = {15,20,78,9,7,3,88,22,37,21}; //Medía tem que ser 30

    srand(time(NULL));

    printf("Media do Vt: %.2f",media_vet(vet,10));
    return 0;
}

float media_vet(int *vet,int tamanho){
    
    float somatotal = 0;

    for (int i = 0; i < tamanho; i++)
    {
        somatotal = somatotal + vet[i];
    }

    return somatotal / tamanho;
}