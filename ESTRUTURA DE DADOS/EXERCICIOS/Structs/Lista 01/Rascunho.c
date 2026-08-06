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

typedef struct ponto2d
{
    int x;
    int y;
}p2d;

typedef struct pessoa
{
    char nome [25];
    char sexo;
    int idade;
}pessoa;

typedef int maca;
typedef float banana;
typedef char laranja;


int main() {
    banana x = 10.65;
    maca y = 10;
    laranja z = 'nome';
    printf("%ld\n", sizeof(struct ponto2d));        //8
    printf("%ld\n", sizeof(struct ponto2d[10]));    //80
    printf("%ld\n", sizeof(struct pessoa));         //32
    printf("%ld\n", sizeof(struct pessoa[10]));     //320

    printf("%ld\n", sizeof(p2d));        //8
    printf("%ld\n", sizeof(p2d[10]));    //80
    printf("%ld\n", sizeof(pessoa));         //32
    printf("%ld\n", sizeof(pessoa[10]));     //320
    return 0;
}