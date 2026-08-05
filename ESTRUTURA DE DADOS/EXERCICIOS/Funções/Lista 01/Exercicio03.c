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

//Crie uma função que receba uma temperatura em graus Celsius como parâmetro e retorne a temperatura convertida para graus Fahrenheit.
float conversor (float celsius);

int main() {
       printf("Temperatura converrtida com sucesso: %.2ff",conversor(25)); 
    return 0;
}

float conversor (float celsius){
    float fahrenheit;
    return fahrenheit = (9.0/5.0) * celsius + 32;
}