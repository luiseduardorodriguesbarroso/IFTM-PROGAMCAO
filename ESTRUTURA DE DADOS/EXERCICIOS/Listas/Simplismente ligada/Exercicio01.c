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

typedef struct no_simpes_int {
    int valor;
    struct no_simpes_int *proximo;
}NoSLI;
typedef struct listasimples_prod{
    NoSLI *inicio;
    NoSLI *fim;
    int tamanho;
}listaLSI_Prod;
typedef struct
{
    int codigo; //codigo do produto
    char nom[50];
    float preço; 
}Produto;
typedef struct{

    int valor;
    NoSLI_Prod *proximo;
}NoSLI_Prod; //Novo no de Produto

int main() {

    return 0;
}