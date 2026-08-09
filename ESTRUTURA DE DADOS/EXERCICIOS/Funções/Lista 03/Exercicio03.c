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

//Crie uma função que receba como parâmetros duas matrizes 3x3 de inteiros. A função deve montar a transposta da 1a matriz na 2a.
void trasposta (int mt[3][3],int mt2[3][3]);
void mostrartrasnposta(int mt[3][3],int mt2[3][3]);

int main() {
    int mt [3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int mt2[3][3];

    trasposta(mt,mt2);
    mostrartrasnposta(mt,mt2);
    return 0;
}
//trasposta da Matriz orriginal
void trasposta (int mt[3][3],int mt2[3][3]){
    for(int i = 0; i < 3; i++ ){
        for(int j = 0; j < 3; j++){
            mt2[i][j] = mt [j][i]; 
        }
    }
}
//Mostra a matriz transposta que eu usei na 'void trasposta (int mt[3][3],int mt2[3][3])'
void mostrartrasnposta(int mt[3][3],int mt2[3][3]){
    printf("Matriz original:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz transposta:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", mt2[i][j]);
        }
        printf("\n");
    }
}