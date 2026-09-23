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
void mostrarListaDLI(listaDLI *pontlista);
void inserirInicioListaDLI(int valor, listaDLI *pontlista);
void inserirFimListaDLS(int valor, listaDLI *pontlista);
void limparLDLI(listaDLI *pontlista);
void MostrarListaInvertida(listaDLI *pontlista);





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

void mostrarListaDLI(listaDLI *pontlista){
    if (pontlista == NULL){ //se a lista for Excluida ou NULL ela avisa
        printf("\nLista Vazia\n");
    }

    printf("Tamanho da Lista = %d\n", pontlista->tamanho);

    if (pontlista->tamanho == 0) {
        printf("Lista Vazia\n");
    } else {
        NoDSLI *pontAux = pontlista->inicio;
        while (pontAux != NULL) {
            printf("%d -> ", pontAux->valor);
            pontAux = pontAux->proximo; // O ponteiro anda para a próxima "gaveta"
        }
        printf("NULL\n");
    } 
    printf("\n");
}

void inserirInicioListaDLI(int valor, listaDLI *pontlista){

    NoDSLI *novo  = criarNoDLI(valor,NULL,pontlista->inicio);

    if(pontlista->inicio == NULL) {
        pontlista->inicio = novo;
        pontlista->fim = novo; 
    } else {
        pontlista->inicio->anterior = novo;
        pontlista->inicio = novo;
    }
    pontlista->tamanho++;
}

void inserirFimListaDLS(int valor, listaDLI *pontlista){
    if (pontlista == NULL){
        printf("Aviso: lista vazia!\n");
    }
    NoDSLI *novo = criarNoDLI(valor,pontlista->fim,NULL);

    if (pontlista->inicio == NULL) {  //se inicio for null
        pontlista->inicio = novo;
        pontlista->fim = novo;
    } else {
        pontlista->fim->proximo = novo;
        pontlista->fim = novo;
    }

    pontlista->tamanho++;
}

void limparLDLI(listaDLI *pontlista){
    if(pontlista->tamanho == 0)
    {
        printf("\nLista já esta vazia\n");
    } else if (pontlista->tamanho == 1) {
        free(pontlista->inicio);
        pontlista->inicio = NULL;
    } else {
        NoDSLI *aux = pontlista->inicio;
        
        while(aux != NULL){
            NoDSLI *proximo = aux->proximo;
            free(aux);
            aux = proximo;
        }
    }
    pontlista->fim = NULL;
    pontlista->inicio = NULL;
    pontlista->tamanho = 0;
}

void MostrarListaInvertida(listaDLI *pontlista) {

}

int main() {
    
    listaDLI *lista = criarliataDLI();

    system("clear"); //limpatl linux

    inserirInicioListaDLI(15,lista);
    mostrarListaDLI(lista);

    inserirInicioListaDLI(50,lista);
    mostrarListaDLI(lista);

    inserirInicioListaDLI(77,lista);
    mostrarListaDLI(lista);

    inserirFimListaDLS(19,lista);
    mostrarListaDLI(lista);
    
    inserirFimListaDLS(43,lista);
    mostrarListaDLI(lista);

    limparLDLI(lista); //Apagando a lista
    mostrarListaDLI(lista);
    return 0;
}