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


typedef struct nodupla
{
    int valor;
    struct nodupla *anterior;
    struct nodupla *proximo;
}NoDSLI;

typedef struct listadupla_int{

    NoDSLI *inicio;
    NoDSLI *fim;
    int tamanho;

}listaDLI;

//---------------------------------------------------------------
NoDSLI *criarNoDLI(int valor, NoDSLI *anterior, NoDSLI *proximo);
listaDLI *criarliataDLI();








//---------------------------------------------------------------

NoDSLI *criarNoDLI(int valor, NoDSLI *anterior, NoDSLI *proximo){
    NoDSLI * novo = (NoDSLI*) malloc(sizeof(NoDSLI));

    if (novo == NULL){
        printf("Ero fatal: Falha na alocação de memoria");
        exit(1);
    }

    novo->valor = valor;
    novo->anterior = anterior;
    novo->proximo = proximo;
    return novo;
}

listaDLI *criarliataDLI(){
    
    listaDLI *nova = (listaDLI*) malloc(sizeof(listaDLI));
    
    if (nova == NULL){
        printf("Ero fatal: Falha na alocação de memoria");
        exit(1);
    }

    nova->tamanho = 0;
    nova->inicio = NULL;
    nova->fim =NULL;
    return nova;
}



int main() {
    
    return 0;
}