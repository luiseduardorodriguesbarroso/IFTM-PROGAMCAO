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

/*10) No programa principal:

a) Criar um vetor de tamanho 20 de inteiros
b) Preencher os 10 primeiros valores do vetor com números digitados pelo usuário via teclado
c) Preencher os 10 últimos valores do vetor com números aleatórios entre 1 e 100
d) Mostrar o vetor inteiro na tela
e) Calcular e mostrar a média dos valores do vetor
f) Encontrar e mostrar o maior e o menor valor do vetor
g)Verificar se há elementos repetidos no vetor e exibir uma mensagem em caso afirmativo
h) Solicitar um valor ao usuário e verificar se esse valor existe no vetor. Se existir exibir a posição em que ele está, senão exibir uma mensagem de valor não encontrado
i) Verificar se o vetor está em ordem crescente, ou seja, se a[0] <= a[1] <= a[2] <= ... para todos elementos do vetor

Use as funções que você criou! (2 a 9)
*/

void elementos_vet(int *vet, int tamanho);
void preencher_vet(int *vet, int tamanho, int min, int max);
float media_vet(int *vet, int tamanho);
int maior_lemento_vet(int *vet, int tamanho);
int menor_lemento_vet(int *vet, int tamanho);
int Verificar_rep(int *vet, int tamanho);
int verificaador(int *vet, int taamanho, int procurar);
int verificar_orden(int *vet, int tamanho);

int main() {
    int vet[10];
    int procurar = 15;

    srand(time(NULL));

    preencher_vet(vet, 10, 1, 30);
    printf("\n");

    elementos_vet(vet, 10);
    printf("\n");

    printf("Media: %.2f\n", media_vet(vet, 10));

    printf("Indice Maior: %d\n", maior_lemento_vet(vet, 10));

    printf("Indice Menor: %d\n", menor_lemento_vet(vet, 10));

    printf("Tem repetido: %d\n", Verificar_rep(vet, 10));

    printf("Ordem: %d\n", verificar_orden(vet, 10));

    printf("Indice do valor %d: %d\n", procurar, verificaador(vet, 10, procurar));

    return 0;
}

void elementos_vet(int *vet, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%5d", *(vet + i));
    }
    printf("\n");
}

void preencher_vet(int *vet, int tamanho, int min, int max) {
    for (int i = 0; i < tamanho; i++) {
        vet[i] = rand() % (max - min + 1) + min;
    }
}

float media_vet(int *vet, int tamanho) {
    float somatotal = 0;

    for (int i = 0; i < tamanho; i++) {
        somatotal = somatotal + *vet;
        vet++;
    }

    return somatotal / tamanho;
}

int maior_lemento_vet(int *vet, int tamanho) {
    int maior = 0;

    for (int i = 0; i < tamanho; i++) {
        if (*(vet + maior) < *(vet + i)) {
            maior = i;
        }
    }

    return maior;
}

int menor_lemento_vet(int *vet, int tamanho) {
    int menor = 0;
    int menor_valor = *vet;

    for (int i = 0; i < tamanho; i++) {
        if (*vet < menor_valor) {
            menor_valor = *vet;
            menor = i;
        }
        vet++;
    }

    return menor;
}

int Verificar_rep(int *vet, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        for (int x = i + 1; x < tamanho; x++) {
            if (vet[x] == vet[i]) {
                return 1;
            }
        }
    }
    return 0;
}

int verificaador(int *vet, int taamanho, int procurar) {
    for (int i = 0; i < taamanho; i++) {
        if (procurar == *(vet + i)) {
            return i;
        }
    }
    return -1;
}

int verificar_orden(int *vet, int tamanho) {
    int crescente = 1;
    int decrescente = 1;

    for (int i = 0; i < tamanho - 1; i++) {
        if (*vet > *(vet + 1)) {
            crescente = 0;
        }
        if (*vet < *(vet + 1)) {
            decrescente = 0;
        }
        vet++;
    }

    if (crescente == 1) {
        return 1;
    } else if (decrescente == 1) {
        return 2;
    }

    return 0;
}