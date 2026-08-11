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

/*No programa principal:

a) Criar 5 matrizes 3x3
b) Preencher as 2 primeiras matrizes com valores aleatórios entre 1 e 10
c) Mostrar a 1ª matriz na tela
d) Criar a matriz transposta da 1ª matriz na 3ª matriz e mostrá-la
e) Achar e mostrar o maior e o menor elementos da 1ª matriz
f) Calcular e mostrar o determinante da 1ª matriz
g) Somar as 2 primeiras matrizes na 4ª matriz e mostrá-la
h) Multiplicar as 2 primeiras matrizes na 5ª matriz e mostrá-la
*/

// Função para gerar uma matriz com valores aleatórios
void gerarmatriz(int matriz[3][3], int min, int max);
// Função para mostrar uma matriz
void mostrarmatriz(int matriz[3][3]);
// Função para criar a matriz transposta
void trasposta(int mt[3][3], int mt2[3][3]);
// Função para encontrar o maior valor
int procurar_maior(int mt[3][3]);
// Função para encontrar o menor valor
int procurar_menor(int mt[3][3]);
// Função para calcular o determinante
int calcular_determinante(int mt[3][3]);
// Função para somar duas matrizes
void somar_matrizes(int mt[3][3], int mt2[3][3], int mt3[3][3]);
// Função para multiplicar duas matrizes
void multiplicar_matrizes(int mt[3][3], int mt2[3][3], int mt3[3][3]);

int main() {

    // Criando 5 matrizes 3x3
    int mt[3][3];
    int mt2[3][3];
    int mt3[3][3];
    int mt4[3][3];
    int mt5[3][3];
    srand(time(NULL));

    // b) Preenchendo as 2 primeiras matrizes
    // com valores aleatórios entre 1 e 10
    gerarmatriz(mt, 1, 10);
    gerarmatriz(mt2, 1, 10);

    // c) Mostrar a 1ª matriz
    printf("Matriz 01:\n");
    mostrarmatriz(mt);

    // Mostrando a 2ª matriz
    printf("\nMatriz 02:\n");
    mostrarmatriz(mt2);

    // d) Criar a matriz transposta da 1ª matriz
    // na 3ª matriz e mostrar
    trasposta(mt, mt3);
    printf("\nMatriz 03 - Transposta da Matriz 01:\n");
    mostrarmatriz(mt3);

    // e) Achar e mostrar o maior e o menor
    // elemento da 1ª matriz
    printf("\nMaior valor da Matriz 01: %d", procurar_maior(mt));
    printf("\nMenor valor da Matriz 01: %d", procurar_menor(mt));

    // f) Calcular e mostrar o determinante
    // da 1ª matriz
    printf("\nDeterminante da Matriz 01: %d\n",
           calcular_determinante(mt));

    // g) Somar as 2 primeiras matrizes
    // na 4ª matriz e mostrar
    somar_matrizes(mt, mt2, mt4);
    printf("\nMatriz 04 - Soma das Matrizes 01 e 02:\n");
    mostrarmatriz(mt4);

    // h) Multiplicar as 2 primeiras matrizes
    // na 5ª matriz e mostrar
    multiplicar_matrizes(mt, mt2, mt5);
    printf("\nMatriz 05 - Multiplicacao das Matrizes 01 e 02:\n");
    mostrarmatriz(mt5);
    return 0;
}
void gerarmatriz(int matriz[3][3], int min, int max) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = rand() % (max - min + 1) + min;
        }
    }
}

void mostrarmatriz(int matriz[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }
}

void trasposta(int mt[3][3], int mt2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mt2[i][j] = mt[j][i];
        }
    }
}

int procurar_maior(int mt[3][3]) {
    int maior = mt[0][0];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mt[i][j] > maior) {
                maior = mt[i][j];
            }
        }
    }
    return maior;
}

int procurar_menor(int mt[3][3]) {
    int menor = mt[0][0];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (mt[i][j] < menor) {
                menor = mt[i][j];

            }
        }
    }
    return menor;
}

int calcular_determinante(int mt[3][3]) {
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

void somar_matrizes(int mt[3][3], int mt2[3][3], int mt3[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            mt3[i][j] = mt[i][j] + mt2[i][j];
        }
    }
}

void multiplicar_matrizes(int mt[3][3], int mt2[3][3], int mt3[3][3]) {
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            mt3[i][j] = 0;
            for (int k = 0; k < 3; k++) 
            {
                mt3[i][j] += mt[i][k] * mt2[k][j];
            }
        }
    }
}