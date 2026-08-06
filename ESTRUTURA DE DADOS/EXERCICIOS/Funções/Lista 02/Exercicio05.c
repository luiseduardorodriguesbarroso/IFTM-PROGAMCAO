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

//) Crie uma função em C que recebe como parâmetros um vetor de inteiros e seu tamanho. A função deve encontrar e retornar o índice do menor valor do vetor.
void procurarmenor(int vetor[],int tamanho, int min, int max);

int main() {
    int vt [5];
    srand(time(NULL));
    procurarmenor(vt,5,2,20);
    return 0;
}

void procurarmenor(int vetor[],int tamanho, int min, int max){
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (max - min + 1) + min;
    }
    printf("Vetor gerado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int menor;
    int inicio=0;
    for (int i = 1; i < tamanho; i++)
    {
        if (vetor[inicio] < vetor[i])
        {
            menor = vetor[inicio];
        } else {
            menor = vetor[i];
            inicio++;
        }
    }
    printf("Menor numero desse vetor é: %d\n",menor);
}