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

// 1. PRIMEIRO O NÓ (O compilador precisa saber o que é um nó antes de criar a lista)
typedef struct no_simples_int {
    int valor;
    struct no_simples_int *proximo;
} NoSLI;

// 2. DEPOIS A LISTA (Agora ela já conhece o NoSLI)
typedef struct listasimples_int {
    NoSLI * inicio;
    int tamanho;
} ListaSLI;

// ================= PROTÓTIPOS =================

ListaSLI* criarListaSLI();
NoSLI* criarNoSLI(int valor, NoSLI *proximo);
void mostrarListaSLI(ListaSLI *pontLista);
void inserirFimSLI(int valor, ListaSLI *pontLista);
void InserirInicioSLI(int valor, ListaSLI *pontLista);
void espaco();
int obtervalordoinicioLSLI(ListaSLI *pontlista);
int obtervalordoFimLSLI(ListaSLI *pontlista);

// ================= FUNÇÕES AUXILIARES =================
void espaco() {
    printf("\n");
}

NoSLI* criarNoSLI(int valor, NoSLI *proximo) {
    NoSLI *novo = (NoSLI *) malloc(sizeof(NoSLI));
    novo->valor = valor;
    novo->proximo = proximo;
    return novo;
}

// ================= FUNÇÕES DA LISTA =================
ListaSLI * criarListaSLI() {
    ListaSLI * nova = (ListaSLI *) malloc(sizeof(ListaSLI));
    nova->tamanho = 0;
    nova->inicio = NULL; // CORREÇÃO: antes estava nova->tamanho = NULL
    return nova;
}

void mostrarListaSLI(ListaSLI *pontLista) {
    printf("Tamanho da Lista = %d\n", pontLista->tamanho);
    
    if (pontLista->tamanho == 0) {
        printf("Lista Vazia\n");
    } else {
        NoSLI *pontAux = pontLista->inicio;
        while (pontAux != NULL) {
            printf("%d -> ", pontAux->valor);
            pontAux = pontAux->proximo; // O ponteiro anda para a próxima "gaveta"
        }
        printf("NULL\n");
    }
}

void inserirFimSLI(int valor, ListaSLI *pontLista) {
    NoSLI *novo = criarNoSLI(valor, NULL); 

    if (pontLista->inicio == NULL) {
        pontLista->inicio = novo;
    } else {
        NoSLI *pontAux = pontLista->inicio;
        while (pontAux->proximo != NULL) {
            pontAux = pontAux->proximo;
        }
        pontAux->proximo = novo; 
    }
    pontLista->tamanho++; 
}

void InserirInicioSLI(int valor, ListaSLI *pontLista) {
    NoSLI *novo = criarNoSLI(valor, NULL);

    if (pontLista->inicio == NULL) {
        pontLista->inicio = novo; 
    } else {   
        novo->proximo = pontLista->inicio;
        pontLista->inicio = novo; 
    }
    pontLista->tamanho++; 
}

int obtervalordoinicioLSLI(ListaSLI *pontlista){
    if(pontlista->inicio == NULL)
    {
        printf("Lista vazia!\n");
        return 0;
    } else {
        return pontlista->inicio->valor;
    }
}

int obtervalordoFimLSLI(ListaSLI *pontlista){
    if(pontlista->inicio == NULL)
    {
        printf("Lista vazia!\n");
        return 0;
    } else {
        NoSLI *aux = pontlista->inicio;
        while (aux->proximo != NULL){
            aux= aux->proximo;
        }
        return aux->valor;
    }
}
int main() {
    ListaSLI * lista = criarListaSLI();
    espaco();

    printf("+--------------------------------+\n");
    printf("| INSERIR ELEMENTOS EM UMA LISTA |\n");
    printf("+--------------------------------+\n");
    espaco();

    printf("-> PELO FIM: ");
    espaco();
    mostrarListaSLI(lista);
    espaco();

    inserirFimSLI(10, lista);
    mostrarListaSLI(lista);
    espaco();

    inserirFimSLI(20, lista);
    mostrarListaSLI(lista);
    espaco();

    inserirFimSLI(30, lista);
    mostrarListaSLI(lista);
    espaco();

    printf("-> PELO INICIO: ");
    espaco();
    mostrarListaSLI(lista);
    espaco();

    InserirInicioSLI(55, lista);
    mostrarListaSLI(lista);
    obtervalordoinicioLSLI(lista);
    espaco();

    InserirInicioSLI(67, lista);
    mostrarListaSLI(lista);
    espaco();

    InserirInicioSLI(100, lista);
    mostrarListaSLI(lista);
    espaco();

    printf("Mostrando o Inicio da Lista: %d\n",obtervalordoinicioLSLI(lista));
    
    printf("Fim da Lista: %d \n",obtervalordoFimLSLI(lista));

    return 0;
}