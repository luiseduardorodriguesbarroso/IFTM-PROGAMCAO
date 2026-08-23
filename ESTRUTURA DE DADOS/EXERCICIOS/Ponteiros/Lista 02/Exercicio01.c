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

//1) Crie uma função que receba como parâmetros uma temperatura e um inteiro para indicar a operação, ambos via ponteiro. A função deve retornar a temperatura convertida de acordo com a operação escolhida: se a operação for 0, a temperatura deve ser convertida de Celsius para Fahrenheit e se a operação for 1, a temperatura deve ser convertida de Fahrenheit para Celsius.

void conversao(float *temperatura, int *opc);

int main() {

    float temp = 22;
    int opc = 0;

    conversao(&temp, &opc);

    printf("Temperatura convertida: %.2f\n", temp);

    return 0;
}

void conversao(float *temperatura, int *opc) {

    if (*opc == 0) {
        *temperatura = (*temperatura * 1.8) + 32;
    } else {
        *temperatura = (*temperatura - 32) / 1.8;
    }
}