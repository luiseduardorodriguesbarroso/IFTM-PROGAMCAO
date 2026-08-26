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

//6) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve encontrar e retornar o índice do menor valor do vetor.  Use aritmética de ponteiros alterando o ponteiro.

int menor_lemento_vet(int *vet,int tamanho);

int main() {
    
    int vet[5] = {10,5,90,1,45};
    
    srand(time(NULL));

    printf("Menor elemento do vet: %d",menor_lemento_vet(vet,5));

    return 0;
}

int menor_lemento_vet(int *vet,int tamanho){

    int menor = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (*(vet + menor) > *(vet + i)){
            menor = i;
        } 
        
    }
    
    return menor;
}