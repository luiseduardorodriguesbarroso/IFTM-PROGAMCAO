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

//7) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve retornar 1 caso o vetor tenha elementos repetidos e 0 caso contrário. Use o operador de índice no ponteiro.

int Verificar_rep(int *vet,int tamanho);

int main() {
    
    int vet[10] = {1,2,3,7,5,6,9,8,10,2};
    
    printf("%d",Verificar_rep(vet,10));
    return 0;
}

int Verificar_rep(int *vet,int tamanho){

    for (int i = 0; i < tamanho; i++)
    {
        for (int x = i + 1; x < tamanho; x++)
        {
            if(*(vet + x) == *(vet + i)){
                return 1;  
            } 
        }
    }
    return 0;
}