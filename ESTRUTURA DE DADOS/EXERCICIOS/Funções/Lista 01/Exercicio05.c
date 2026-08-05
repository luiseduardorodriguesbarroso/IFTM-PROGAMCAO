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

//Crie uma função que receba como parâmetros uma temperatura e um inteiro para indicar a operação. Se a operação for 0, a temperatura deve ser convertida de Celsius para Fahrenheit e se a operação for 1, a temperatura deve ser convertida de Fahrenheit para Celsius.
float conversor(float temperatura, int operacao);

int main() {

    printf("25C = %.2fF\n", conversor(25,0));
    printf("77F = %.2fC\n", conversor(77,1));
    return 0;
}

float conversor(float temperatura, int operacao) {

    if (operacao == 0) {
        return (9.0 / 5.0) * temperatura + 32;
    }   
    else if (operacao == 1) {
        return (5.0 / 9.0) * (temperatura - 32);
    }   
    else {
        return -1;
    }
}