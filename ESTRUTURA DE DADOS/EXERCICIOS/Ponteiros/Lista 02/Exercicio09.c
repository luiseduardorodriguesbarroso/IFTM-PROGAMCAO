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

//9) Crie uma função em C que recebe como parâmetros um vetor de inteiros via ponteiro e seu tamanho. A função deve retornar 1 caso os elementos estejam em ordem crescente, 2 caso os elementos estejam em ordem decrescente e 0 caso estejam fora de ordem. Use aritmética de ponteiros alterando o ponteiro.

int verificar_orden(int *vet,int tamanho);

int main() {
    
    int vet1[5] = {1,2,3,4,5};
    int vet2[5] = {5,4,3,2,1};
    int vet3[5] = {7,5,6,3,8};

    printf("%d\n",verificar_orden(vet1,5)); //Ordem decrescente - 1
    printf("%d\n",verificar_orden(vet2,5)); //Orrdem decrescente - 2
    printf("%d\n",verificar_orden(vet3,5)); //Fora de ordem - 0
    return 0;
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