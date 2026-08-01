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

// Um número primo é qualquer inteiro positivo divisível apenas por si próprio e por 1. 
// Escreva uma função que receba um inteiro positivo e, se este número for primo, retorne 1, caso contrário retorne 0.
void nuprimo(int numero);

int main() {
    nuprimo(13);
    return 0;
}

void nuprimo(int numero) {
    int divisoes = 0;
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            divisoes++;
        }
    }
    if (divisoes == 2) {
        printf("%d é primo\n", numero);
    } else {
        printf("%d não é primo\n", numero);
    }
}