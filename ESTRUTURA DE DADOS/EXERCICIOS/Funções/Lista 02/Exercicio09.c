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

/*No programa principal:

a) Criar um vetor de tamanho 20 de inteiros
b) Preencher os 10 primeiros valores do vetor com números digitados pelo usuário via teclado
c) Preencher os 10 últimos valores do vetor com números aleatórios entre 1 e 100
d) Mostrar o vetor inteiro na tela
e) Calcular e mostrar a média dos valores do vetor
f) Encontrar e mostrar o maior e o menor valor do vetor
g)Verificar se há elementos repetidos no vetor e exibir uma mensagem em caso afirmativo
h) Solicitar um valor ao usuário e verificar se esse valor existe no vetor. Se existir exibir a posição em que ele está, senão exibir uma mensagem de valor não encontrado
i) Verificar se o vetor está em ordem crescente, ou seja, se a[0] <= a[1] <= a[2] <= ... para todos elementos do vetor

Use as funções que você criou!
*/
void mostrarparametros(int inteiros[], int numeros);
float calcularmedia(int vetor[], int tamanho);
void procurarmaior(int vetor[], int tamanho);
void procurarmenor(int vetor[], int tamanho);
int procurar_repetidos(int vetor[], int tamanho);
int mostrarindice(int vetor[], int tamanho, int valor);
int verificarordem(int vetor[], int tamanho);

int main() {

    int vt[20];
    int valor;
    int indice;
    int resultado;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        printf("Informe o %d valor: ", i + 1);
        scanf("%d", &vt[i]);
    }

    for (int i = 10; i < 20; i++) {
        vt[i] = rand() % 100 + 1;
    }

    printf("\nVetor completo:");

    mostrarparametros(vt,20);

    printf("\n\nMedia do vetor: %.2f", calcularmedia(vt,20));

    procurarmaior(vt,20);
    procurarmenor(vt,20);

    if (procurar_repetidos(vt,20) == 1) {
        printf("\nExistem valores repetidos no vetor.");
    } else {
        printf("\nNao existem valores repetidos no vetor.");
    }

    printf("\n\nInforme um valor para procurar: ");
    scanf("%d",&valor);

    indice = mostrarindice(vt,20,valor);

    if (indice == -1) {
        printf("Valor nao encontrado.");
    } else {
        printf("Valor encontrado na posicao: %d",indice);
    }

    resultado = verificarordem(vt,20);

    if (resultado == 1) {
        printf("\nO vetor esta em ordem crescente.");
    } else {
        printf("\nO vetor nao esta em ordem crescente.");
    }
    return 0;
}



void mostrarparametros(int inteiros[], int numeros){
    printf("\n");

    for (int i = 0; i < numeros; i++) {
        printf("%5d",inteiros[i]);
    }
}



float calcularmedia(int vetor[], int tamanho){
    float media = 0;

    for (int i = 0; i < tamanho; i++) {
        media += vetor[i];
    }
    media = media / tamanho;
    return media;
}



void procurarmaior(int vetor[], int tamanho){
    int maior = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    printf("\nMaior valor do vetor: %d",maior);
}



void procurarmenor(int vetor[], int tamanho){
    int menor = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    printf("\nMenor valor do vetor: %d",menor);
}



int procurar_repetidos(int vetor[], int tamanho){
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[i] == vetor[j]) {
                return 1;
            }

        }

    }
    return 0;
}



int mostrarindice(int vetor[], int tamanho, int valor){

    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}



int verificarordem(int vetor[], int tamanho){

    for (int i = 0; i < tamanho - 1; i++) {
        if (vetor[i] > vetor[i + 1]) {
            return 0;
        }
    }
    return 1;
}