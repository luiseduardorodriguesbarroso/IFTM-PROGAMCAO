#ifndef PILHA_FILA_H
#define PILHA_FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct noSLI {
    int valor;
    struct noSLI * proximo;
} NoSLI;

typedef struct filaLSLI {
    NoSLI * inicio;
    NoSLI * fim;
    int tamanho;
} FilaLSLI;

typedef struct pilhaLSLI {
    NoSLI * topo;
    int tamanho;
} PilhaLSLI;

NoSLI * criarNoLSLI(int valor, NoSLI *proximo){
    NoSLI *novo = (NoSLI *) malloc(sizeof(NoSLI));
    if (novo == NULL){
        printf("Erro: falha na alocacao de memoria para o no.\n");
        exit(1);
    }
    novo->valor = valor;
    novo->proximo = proximo;
    return novo;
}

FilaLSLI * criarFilaLSLI(void){
    FilaLSLI *fila = (FilaLSLI *) malloc(sizeof(FilaLSLI));
    if (fila == NULL){
        printf("Erro: falha na alocacao de memoria para a fila.\n");
        exit(1);
    }
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

PilhaLSLI * criarPilhaLSLI(void){
    PilhaLSLI *pilha = (PilhaLSLI *) malloc(sizeof(PilhaLSLI));
    if (pilha == NULL){
        printf("Erro: falha na alocacao de memoria para a pilha.\n");
        exit(1);
    }
    pilha->topo = NULL;
    pilha->tamanho = 0;
    return pilha;
}

void inserirFilaLSLI(int valor, FilaLSLI *fila){
    if (fila == NULL){
        printf("Impossivel inserir em uma fila nula.\n");
        return;
    }

    NoSLI *novo = criarNoLSLI(valor, NULL);
    if (fila->tamanho == 0){
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }
    fila->fim = novo;
    fila->tamanho++;
}

void inserirPilhaLSLI(int valor, PilhaLSLI *pilha){
    if (pilha == NULL){
        printf("Impossivel inserir em uma pilha nula.\n");
        return;
    }

    pilha->topo = criarNoLSLI(valor, pilha->topo);
    pilha->tamanho++;
}

void mostrarFilaLSLI(FilaLSLI *fila){
    if (fila == NULL){
        printf("Fila nula.\n");
        return;
    }

    printf("Fila (tamanho = %d): ", fila->tamanho);
    if (fila->inicio == NULL){
        printf("vazia\n");
        return;
    }

    NoSLI *atual = fila->inicio;
    while (atual != NULL){
        printf("%d", atual->valor);
        if (atual->proximo != NULL){
            printf(" -> ");
        }
        atual = atual->proximo;
    }
    printf(" -> NULL\n");
}

void mostrarPilhaLSLI(PilhaLSLI *pilha){
    if (pilha == NULL){
        printf("Pilha nula.\n");
        return;
    }

    printf("Pilha (tamanho = %d): ", pilha->tamanho);
    if (pilha->topo == NULL){
        printf("vazia\n");
        return;
    }

    NoSLI *atual = pilha->topo;
    printf("(topo) ");
    while (atual != NULL){
        printf("%d", atual->valor);
        if (atual->proximo != NULL){
            printf(" -> ");
        }
        atual = atual->proximo;
    }
    printf(" -> NULL\n");
}

bool removerFilaLSLI(FilaLSLI *fila){
    if (fila == NULL || fila->tamanho == 0 || fila->inicio == NULL){
        printf("Impossivel remover de uma fila vazia.\n");
        return false;
    }

    NoSLI *remover = fila->inicio;
    fila->inicio = remover->proximo;
    free(remover);
    fila->tamanho--;
    if (fila->tamanho == 0){
        fila->fim = NULL;
    }
    return true;
}

bool removerPilhaLSLI(PilhaLSLI *pilha){
    if (pilha == NULL || pilha->tamanho == 0 || pilha->topo == NULL){
        printf("Impossivel remover de uma pilha vazia.\n");
        return false;
    }

    NoSLI *remover = pilha->topo;
    pilha->topo = remover->proximo;
    free(remover);
    pilha->tamanho--;
    return true;
}

void destruirFilaLSLI(FilaLSLI **fila){
    if (fila == NULL || *fila == NULL){
        return;
    }

    NoSLI *atual = (*fila)->inicio;
    while (atual != NULL){
        NoSLI *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(*fila);
    *fila = NULL;
}

void destruirPilhaLSLI(PilhaLSLI **pilha){
    if (pilha == NULL || *pilha == NULL){
        return;
    }

    NoSLI *atual = (*pilha)->topo;
    while (atual != NULL){
        NoSLI *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(*pilha);
    *pilha = NULL;
}

int contarPares(FilaLSLI* pontfila){
    if (pontfila == NULL || pontfila->tamanho <= 0 || pontfila->inicio == NULL){
        return 0;
    }
    
    int cont = 0;
    int x = 0;
    NoSLI *aux = pontfila->inicio;

    if (pontfila->tamanho > 0) {   
        while (x != pontfila->tamanho){
            if (aux->valor % 2 == 0){
                cont++;
            }
            aux = aux->proximo;
            x++;
        }
    } 
    return cont;
}

int encontrarMaior(FilaLSLI* pontfila){
    if (pontfila == NULL || pontfila->tamanho <= 0 || pontfila->inicio == NULL){
        return 0;
    }
    int maior = pontfila->inicio->valor;
    int x = 0;
    NoSLI *aux1 = pontfila->inicio;
    
    while (x != pontfila->tamanho && aux1 != NULL)
    {
        if(pontfila->tamanho == 1){
           maior = pontfila->inicio->valor; 
        }   else {
            if (aux1->valor > maior){
                maior = aux1->valor;
            } 
            aux1 = aux1->proximo;
        }
        x++;
    }
    return maior;
}



#endif // PILHA_FILA_H
