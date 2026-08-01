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

//Escreva uma função que receba como argumento o ano e retorne 1 se for um ano bissexto e 0 se não for um ano bissexto. Um ano é bissexto se for divisível por 4, mas não por 100. Um ano também é bissexto se for divisível por 400.
void anobissexto (int ano);

int main() {
    anobissexto(2024);    
    return 0;
}

void anobissexto (int ano){
   if (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0){
        printf("1\n");
    }   else {
        printf("0\n");
    }
}