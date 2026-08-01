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

//Crie uma função que receba uma temperatura em graus Fahrenheit como parâmetro e retorne a temperatura convertida para graus Celsius.
float conversor (float fahrenheit);

int main() {
    printf("Temperatura converrtida com sucesso: %.2fc",conversor(77.0)); 
    return 0;
}

float conversor (float fahrenheit){
    float celsius;
    return celsius = (5.0/9.0) * (fahrenheit -32);
}