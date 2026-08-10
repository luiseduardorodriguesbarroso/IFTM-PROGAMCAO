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

//Crie uma função que receba como parâmetros três matrizes 3x3 de inteiros. A função deve somar a 1a e a 2a matrizes na 3a.
void somar_matrizes(int mt[3][3],int mt2[3][3],int mt3[3][3],int min, int max);

int main() {
    
    return 0;
}

void somar_matrizes(int mt[3][3],int mt2[3][3],int mt3[3][3],int min, int max){
    for (int i = 0; i < 3; i++) { //Gerando mt1
        for (int j = 0; j < 3; j++) {
            mt[i][j] = rand() % (max - min + 1) + min;
        }
    }//Gerando mt2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mt2[i][j] = rand() % (max - min + 1) + min;
        }
    }//Mostrando mt1
    printf("Matrriz ");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d",mt[i][j]);
        }
        printf("\n");
    }//Mostrando mt2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d",mt2[i][j]);
        }
        printf("\n");
    }
    //Calculando mt3
    mt3 [0][0] = mt[0][0] + mt2[0][0];
    mt3 [0][1] = mt[0][1] + mt2[0][1];
    mt3 [0][2] = mt[0][2] + mt2[0][2];

    mt3 [1][0] = mt[1][0] + mt2[1][0];
    mt3 [1][1] = mt[1][1] + mt2[1][1];
    mt3 [1][2] = mt[1][2] + mt2[1][2];

    mt3 [2][0] = mt[2][0] + mt2[2][0];
    mt3 [2][1] = mt[2][1] + mt2[2][1];
    mt3 [2][2] = mt[2][2] + mt2[2][2];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d",mt3[i][j]);
        }
        printf("\n");
    }

}