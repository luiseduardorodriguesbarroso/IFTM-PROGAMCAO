#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Criar lista vazia
No* criarLista() {
    return NULL;
}

// Inserir no início
No* inserirInicio(No *lista, int valor) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    novo->valor = valor;
    novo->prox = lista;

    return novo;
}

// Inserir no final
No* inserirFim(No *lista, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if (lista == NULL) {
        return novo;
    }

    No *aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
    return lista;
}

// Buscar elemento
No* buscar(No *lista, int valor) {
    No *aux = lista;

    while (aux != NULL) {
        if (aux->valor == valor) {
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}

// Remover elemento
No* remover(No *lista, int valor) {
    No *ant = NULL;
    No *atual = lista;

    while (atual != NULL && atual->valor != valor) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Valor nao encontrado!\n");
        return lista;
    }

    if (ant == NULL) {
        lista = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
    return lista;
}

// Imprimir lista
void imprimir(No *lista) {
    No *aux = lista;

    while (aux != NULL) {
        printf("%d -> ", aux->valor);
        aux = aux->prox;
    }

    printf("NULL\n");
}

// Liberar memória
void liberarLista(No *lista) {
    No *aux;

    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

// Contar elementos
int tamanho(No *lista) {
    int cont = 0;
    while (lista != NULL) {
        cont++;
        lista = lista->prox;
    }
    return cont;
}

// Exemplo de uso
int main() {
    No *lista = criarLista();

    lista = inserirInicio(lista, 10);
    lista = inserirInicio(lista, 5);
    lista = inserirFim(lista, 20);
    lista = inserirFim(lista, 30);

    imprimir(lista);

    printf("Tamanho: %d\n", tamanho(lista));

    No *encontrado = buscar(lista, 20);
    if (encontrado != NULL) {
        printf("Encontrado: %d\n", encontrado->valor);
    }

    lista = remover(lista, 10);
    imprimir(lista);

    liberarLista(lista);

    return 0;
}