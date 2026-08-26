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

//8) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro, seu tamanho e um valor inteiro. A função deve retornar o índice do elemento do vetor com esse valor ou -1 caso ele não exista no vetor. Use aritmética de ponteiros sem alterar o ponteiro. 

int verificaador(int *vet,int taamanho,int procurar);

int main() {
    
    int vet[5] = {1,2,3,4,5};

    printf("Indici: %d",verificaador(vet,5,55));
    return 0;
}

int verificaador(int *vet,int taamanho,int procurar){

    for (int i = 0; i < taamanho; i++)
    {
       if(procurar == vet[i])
            return procurar = i; 
    }
    return -1;
    
}