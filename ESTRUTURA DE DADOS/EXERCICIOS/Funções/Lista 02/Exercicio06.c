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

//) Crie uma função em C que recebe como parâmetros um vetor de inteiros e seu tamanho. A função deve retornar 1 caso o vetor tenha elementos repetidos e 0 caso contrário.
int procurar_repetidos(int vetor[],int tamanho, int min, int max);

int main() {
    int vt [5];
    srand(time(NULL));
    procurar_repetidos(vt,5,2,10);
    return 0;
}

int procurar_repetidos(int vetor[],int tamanho, int min, int max){
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (max - min + 1) + min;
    }
    printf("Vetor gerado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    for (int i = 0; i < tamanho - 1; i++) {

        for (int j = i + 1; j < tamanho; j++) {

            if (vetor[i] == vetor[j]) {
                printf("O numero %d esta repetido.\n", vetor[i]);
                return 1;
            }
        }
    }
    return 0;   
}