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

/*
Escreva uma função que receba dia, mês e ano e calcule o dia da semana. Esta função retorna 0 se for domingo, 1 se for segunda-feira, etc... Para calcular o dia da semana use o código a seguir no qual o dia da semana está na variável f:
int f = ano + dia + 3 * (mês - 1) - 1;
if (mês < 3) ano--;
else f -= (int)(0.4 * mês + 2.3);
f += (int)(ano/4) - (int)((ano/100 + 1) * 0.75);
f %= 7;
*/
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
{
    printf("Domingo\n");
}   else if (f == 1)
{
    printf("Segunda-feira\n");
}   else if (f == 2)
{
    printf("Terça-feira\n");
}   else if (f == 3)
{
    printf("Quarta-feira\n");
}   else if (f == 4)
{
    printf("Quinta-feira\n");
}   else if (f == 5)
{
    printf("Sexta-feira\n");
}   else if (f == 6)
{
    printf("Sabado\n");
   
}
}