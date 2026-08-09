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

//Crie uma função que receba como parâmetro uma matriz 3x3 de inteiros. A função deve encontrar e retornar o maior valor da matriz.
void procurar_maior(int mt[3][3], int min, int max);

int main() {
    int mt [3][3];
    srand(time(NULL));
    procurar_maior(mt,2,20);
    return 0;
}

void procurar_maior(int mt[3][3], int min, int max){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mt[i][j] = rand() % (max - min + 1) + min;
        }
    }
    int maior;
     maior = mt[0][0];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(mt[i][j]>maior){
                maior = mt[i][j];
            }
        }  
    }
    printf("Matriz gerada:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d",mt[i][j]);
        }
        printf("\n");
    }
    printf("\nO maior valor dessa matriz e : %d",maior);

}