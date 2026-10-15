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


//--------------------------------------------------------
NoDSLI *criarNoDLI(int valor, NoDSLI *anterior, NoDSLI *proximo);
listaDLI *criarliataDLI();
void mostrarListaLDLI(listaDLI *pontlista);
void inserirInicioListaDLI(int valor, listaDLI *pontlista);
void inserirFimListaDLS(int valor, listaDLI *pontlista);
int verificarImparesLDLI(listaDLI *pontlista);
int verificarMultiplo(listaDLI *pontlista);

//--------------------------------------------------------
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

void mostrarListaLDLI(listaDLI *pontlista){
    if (pontlista == NULL){ //se a lista for Excluida ou NULL ela avisa
        printf("\nLista Vazia\n");
        return;
    }

    printf("\nTamanho da Lista = %d\n", pontlista->tamanho);

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
        return;
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

int verificarImparesLDLI(listaDLI *pontlista){
    if (pontlista == NULL){
        printf("Erro: Sua lista esta vazia!\n");
        return 0;
    } else {
        int impar = 0;
        NoDSLI *aux = pontlista->inicio;
        while (aux != NULL)
        {
            if (aux->valor % 2 != 0){
                impar++;    
            }
            aux = aux->proximo;
        }
        return impar;
    }
}

//Crie uma função em C que recebe como parâmetro uma lista duplamente ligada de inteiros e retorna o número de elementos com valores múltiplos de 5.
int verificarMultiplo(listaDLI *pontlista){
    if(pontlista->inicio == NULL){
        printf("Erro! Sua lista está vazia!\n");
        return 0;
    }   else {
        int cont = 0;
        NoDSLI *aux = pontlista->inicio;
        while (aux != NULL)
        {
            if (aux->valor % 5 == 0){
                cont++;
            }
            aux = aux->proximo;
        }
        return cont;
    }
}

//Crie uma função em C que recebe como parâmetro uma lista duplamente ligada de inteiros. A função deve criar e retornar uma cópia dessa lista. (A lista original não pode ser modificada)

/*Crie uma função em C que recebe como parâmetros duas listas duplamente ligadas de inteiros. A função deve concatenar as duas listas em uma nova lista e retornar a lista concatenada. (“amarrar” a segunda no final da primeira) (As listas originais não podem ser modificadas)

Crie uma função em C que recebe como parâmetros duas listas duplamente ligadas de inteiros e retorne 1 caso elas sejam idênticas ou 0 caso não sejam. (têm o mesmo conteúdo nas mesmas posições)

Crie uma função em C que recebe como parâmetro uma lista duplamente ligada de inteiros e retorna se ela está ordenada(1) ou não(0).*/

int main() {
    listaDLI *lista = criarliataDLI();

    inserirInicioListaDLI(6,lista);
    
    inserirInicioListaDLI(12,lista);

    inserirInicioListaDLI(20,lista);

    inserirFimListaDLS(30,lista);

    inserirFimListaDLS(35,lista);

    inserirFimListaDLS(60,lista);
    
    mostrarListaLDLI(lista);
    //--------------- verficando os impares ---------------
    printf("Numero de elemetos impares na lista: %d\n",verificarImparesLDLI(lista));
    //--------------- Verificando os multiplos de 5 ---------------
    printf("Quantidade de numeros multiplos de 5: %d\n",verificarMultiplo(lista));


    return 0;
}