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

//Crie uma função que recebe como parâmetros um dia, um mês e um ano (inteiros) e escreva na tela por extenso o dia da semana.

void dia_semana (int dia, int mes, int ano);

int main() {
    dia_semana(27,9,1974);
    return 0;
}

void dia_semana (int dia, int mes, int ano)
{
int f = ano + dia + 3 * (mes - 1) - 1;
if (mes < 3) { 
    ano--;
}   else { 
    f -= (int)(0.4 * mes + 2.3);
}
f += (int)(ano/4) - (int)((ano/100 + 1) * 0.75);
f %= 7;

if (f == 0)
    printf("Domingo\n");
else if (f == 1)
    printf("Segunda-feira\n");
else if (f == 2)
    printf("Terça-feira\n");
else if (f == 3)
    printf("Quarta-feira\n");
else if (f == 4)
    printf("Quinta-feira\n");
else if (f == 5)
    printf("Sexta-feira\n");
else if (f == 6)
    printf("Sabado\n");
}