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

//-------------------------------------------------
void inserirnoInicioSLI (ListaSLProd *pontlista, int valor);
void inserirnoFimSLI (ListaSLProd *pontlista, int valor);


//-------------------------------------------------
void inserirnoInicioSLI (ListaSLProd *pontlista, int valor) {
    NoSLProd *novo = criarNoSLI(valor,NULL);

    if (pontlista->inicio == 0) {
        pontlista->inicio = novo; //inicio aponta pro novo e o fim tambem
        pontlista->fim = novo;
    }
    else {
        novo->proximo = pontlista->inicio;
        pontlista->inicio = novo;
    }
    pontlista->tamanho++;
}

void inserirnoFimSLI (ListaSLProd *pontlista, int valor) {
    NoSLProd *novo = criarNoSLI(valor,NULL);

    if (pontlista->fim == NULL) {
        pontlista->inicio = novo;
        pontlista->fim = novo;
    }
    else   {
        pontlista->fim->proximo = novo; //Vai no ultimo elemento e anda +1 e inseri novo lá 
        pontlista->fim = novo; //agr o fim e o novo 
    }
    pontlista->tamanho++;
}

int main() {

    return 0;
}