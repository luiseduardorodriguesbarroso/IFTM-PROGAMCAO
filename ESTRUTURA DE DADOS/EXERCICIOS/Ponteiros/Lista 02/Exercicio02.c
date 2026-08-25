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

//2) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve mostrar os elementos do vetor na tela. Use aritmética de ponteiros sem alterar o ponteiro.

void elementos_vet(int *vet[],int tamanho);


int main() {
    int vet [5] = {1,2,3,4,5};

    elementos_vet(vet,5);

    return 0;
}

void elementos_vet(int *vet[],int tamanho){
   
    for(int i  = 0;i < tamanho;i++){
        printf("%5d",*(vet + i));
    }
}