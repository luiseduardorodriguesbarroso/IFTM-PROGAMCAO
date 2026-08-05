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

//Crie uma função em C que recebe como parâmetros um vetor de inteiros e seu tamanho. A função deve encontrar e retornar o índice do maior valor do vetor.
void procurarmaior(int vetor[],int tamanho, int min, int max);

int main() {

    return 0;
}

void procurarmaior(int vetor[],int tamanho, int min, int max){
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (max - min + 1) + min;
    }
    printf("Vetor gerado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int maior;
    for (int i = 0; i < tamanho; i++)
    {
        
    }
    
}