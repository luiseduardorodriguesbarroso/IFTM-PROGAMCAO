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

//5) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve encontrar e retornar o índice do maior valor do vetor. Use aritmética de ponteiros sem alterar o ponteiro.

int maior_lemento_vet(int *vet,int tamanho);

int main() {
    
    int vet[5] = {10,5,90,7,45};
    
    srand(time(NULL));

    printf("Maior elemento do vet: %d",maior_lemento_vet(vet,5));

    return 0;
}

int maior_lemento_vet(int *vet,int tamanho){

    int maior = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (vet[maior] < vet[i]){
            maior = i;
        } 
        
    }
    
    return maior;
}