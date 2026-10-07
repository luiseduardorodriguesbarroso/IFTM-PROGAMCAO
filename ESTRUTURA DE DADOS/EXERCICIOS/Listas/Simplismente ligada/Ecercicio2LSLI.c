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

typedef struct noSLI {
    int valor;
    struct noSLI * proximo;
} NoSLI;

typedef struct {
    NoSLI * inicio;
    int tamanho;
} ListaSLI;

//------------------------------------------------------------------------------------------------------------
NoSLI* criarNoSLI(int valor, NoSLI *proximo);
ListaSLI * criarListaSLI();
void mostrarListaSLI(ListaSLI *pontLista);
void inserirInicio(int valor, ListaSLI *pontlista);
int numero_de_Impares(ListaSLI *pontlista);
int verific_multiplo5(ListaSLI *pontlista);

//------------------------------------------------------------------------------------------------------------

NoSLI* criarNoSLI(int valor, NoSLI *proximo) {
    NoSLI *novo = (NoSLI *) malloc(sizeof(NoSLI));
    novo->valor = valor;
    novo->proximo = proximo;
    return novo;
}

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

void inserirInicio(int valor, ListaSLI *pontlista){
    if (pontlista == NULL) {
        printf("Aviso: Lista nao existe!\n");
        return;
    } 
    NoSLI *novo = criarNoSLI(valor,pontlista->inicio);
    pontlista->inicio = novo;
    pontlista->tamanho++;
}

//Crie uma função em C que recebe como parâmetro uma lista simplesmente ligada de inteiros e retorna o número de elementos com valores ímpares.
int numero_de_Impares(ListaSLI *pontlista){
    if (pontlista == NULL){
        printf("Aviso: Sua lista esta vazia!");
        return 0;
    }   
    
    NoSLI *aux = pontlista->inicio;
    
    int contador = 0;
    int nuimpares = 0;

    while (contador < pontlista->tamanho)
    { 
        if(aux->valor % 2 != 0){
            nuimpares++; 
        } 
        aux = aux->proximo;
        contador++;
    }
    printf("\nNumero de elementos impares da lista: %d\n",nuimpares);
    return 1;
}

//Crie uma função em C que recebe como parâmetro uma lista simplesmente ligada de inteiros e retorna o número de elementos com valores múltiplos de 5.
int verific_multiplo5(ListaSLI *pontlista){
    if (pontlista == NULL){
        printf("Avisso: Sua lista esta vazia!\n");
        return 0;
    }
    NoSLI *aux = pontlista->inicio;
    int cont = 0;
    int multiplos = 0;
    while (cont < pontlista->tamanho)
    {
        if (aux->valor % 5 == 0){
            multiplos++;
        }
        aux = aux->proximo;
        cont++;
    }
    printf("\nQuantidade de numeros multiplos de 5 na sua lista: %d\n",multiplos);
    return 1;
}

//Crie uma função em C que recebe como parâmetro uma lista simplesmente ligada de inteiros. A função deve criar e retornar uma cópia dessa lista. (A lista original não pode ser modificada)
void clonar_listalSLDI(ListaSLI *pontlista){
    ListaSLI *clone = criarListaSLI();

    NoSLI *aux = pontlista->inicio;
    NoSLI *novo = criarNoSLI(pontlista->inicio->valor,NULL);
    int cont = 0;

    while (cont < pontlista->tamanho)
    {
        
    }
    
}
int main() {
    ListaSLI *lista = criarListaSLI();

    system("clear");

    inserirInicio(15,lista);
    inserirInicio (20,lista);
    inserirInicio(37,lista);
    inserirInicio(50,lista);
    inserirInicio(77,lista);
    inserirInicio(135,lista);

    mostrarListaSLI(lista);

    numero_de_Impares(lista);
    verific_multiplo5(lista);
    return 0;
}