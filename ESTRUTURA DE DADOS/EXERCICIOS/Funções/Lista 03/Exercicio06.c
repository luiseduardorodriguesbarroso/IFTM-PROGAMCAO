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

//Crie uma função que receba como parâmetro uma matriz 3x3 de inteiros. A função deve calcular e retornar o determinante dessa matriz.
int calcular_determinante(int mt[3][3],int min, int max);

int main() {
    int mt[3][3];
    srand(time(NULL));
    printf("\nDeterminante dessa matriz e: %d",calcular_determinante(mt,2,20));    
    return 0;
}
int calcular_determinante(int mt[3][3],int min, int max)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mt[i][j] = rand() % (max - min + 1) + min;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d",mt[i][j]);
        }
        printf("\n");
    }
    int determinante;

    determinante =
        mt[0][0] * mt[1][1] * mt[2][2]
        + mt[0][1] * mt[1][2] * mt[2][0]
        + mt[0][2] * mt[1][0] * mt[2][1]
        - mt[0][2] * mt[1][1] * mt[2][0]
        - mt[0][0] * mt[1][2] * mt[2][1]
        - mt[0][1] * mt[1][0] * mt[2][2];

    return determinante;
}