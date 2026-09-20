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

typedef struct {
    int codigo; //codigo do produto 
    char nome[255];
    float preco;
} Produto;

typedef struct nosimples_prod {
    Produto valor;
    struct nosimples_prod *proximo; //proximo produto da lista
} NoSLProd;

typedef struct listasimples_prod {
    NoSLProd *inicio;
    NoSLProd *fim;
    int tamanho;
} ListaSLProd;





int main() {

    return 0;
}