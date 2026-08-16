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

/* Crie uma estrutura para descrever restaurantes. Os membros devem armazenar
o nome, o endereço, o preço médio e o tipo de comida.

A) Crie uma função que obtém os dados de uma estrutura restaurante pelo teclado e a retorna.

B) Crie uma função que recebe uma estrutura restaurante como parâmetro e escreve seus dados na tela.

C) Crie uma função que recebe um vetor de estruturas restaurante e a quantidade de restaurantes válidos no vetor como parâmetros e os imprime na tela.

D) Crie uma função que recebe um vetor de estruturas restaurantes, a quantidade de restaurantes válidos no vetor e valores mínimo e máximo de preço como parâmetros. A função deve imprimir os restaurantes com valor médio de preço nesse intervalo.

E) Crie uma função que recebe um vetor de estruturas restaurantes, a quantidade de restaurantes válidos no vetor e um tipo de comida como parâmetros. A função deve imprimir os restaurantes com tipo de comida desse tipo.

F) Crie um programa principal que crie uma matriz de 50 estruturas restaurante; pergunte a quantidade de restaurantes a serem lidos; leia os dados desses restaurantes no vetor; mostre os dados dos restaurantes lidos; pergunte uma faixa de valores de preço; mostre os restaurantes com preço médio nessa faixa; pergunte um tipo de comida; mostre os restaurantes com esse tipo de comida. */

typedef struct {
    char nome[100];
    char endereco[200];
    float precoMedio;
    char tipoComida[50];
} cadastro;

cadastro receber_dados(void);
void mostrar_restaurante(cadastro a);
void mostrar_dados(cadastro a[], int tamanho);
void mostrar_por_preco(cadastro a[], int tamanho, float minimo, float maximo);
void mostrar_por_tipo(cadastro a[], int tamanho, char tipo[]);
void limpar_enter(char texto[]);


int main() {
    cadastro restaurante[50];

    int quantidade;
    float minimo;
    float maximo;
    char tipo[50];

    printf("Quantos restaurantes deseja cadastrar? ");
    scanf("%d", &quantidade);

    getchar(); // limpa o '\n' do scanf

    if (quantidade > 50) {
        quantidade = 50;
        printf("\nQuantidade maxima permitida: 50\n");
    }

    for (int i = 0; i < quantidade; i++) {
        printf("\n========== Restaurante %d ==========\n", i + 1);
        restaurante[i] = receber_dados();
    }

    printf("\n\n|========== RESTAURANTES CADASTRADOS ==========|\n");
    mostrar_dados(restaurante, quantidade);

    printf("\n\n========== PESQUISA POR PRECO ==========\n");
    printf("Informe o preco minimo: ");
    scanf("%f", &minimo);

    printf("Informe o preco maximo: ");
    scanf("%f", &maximo);

    printf("\n\n|========== RESTAURANTES NESSA FAIXA DE PRECO ==========|\n");
    mostrar_por_preco(restaurante, quantidade, minimo, maximo);

    getchar(); // limpa o '\n' do scanf
    printf("\n\n========== PESQUISA POR TIPO DE COMIDA ==========\n");
    printf("Informe o tipo de comida: ");
    fgets(tipo, 50, stdin);
    
    limpar_enter(tipo);

    printf("\n\n|========== RESTAURANTES DESSE TIPO ==========|\n");
    mostrar_por_tipo(restaurante, quantidade, tipo);
    return 0;
}

cadastro receber_dados(void) {
    cadastro a;

    printf("\nInforme o nome do restaurante: ");
    fgets(a.nome, 100, stdin);
    limpar_enter(a.nome);

    printf("Informe o endereco do restaurante: ");
    fgets(a.endereco, 200, stdin);
    limpar_enter(a.endereco);

    printf("Qual o preco medio: ");
    scanf("%f", &a.precoMedio);

    getchar(); // limpa o '\n'
    printf("Informe o tipo de comida: ");
    fgets(a.tipoComida, 50, stdin);
    limpar_enter(a.tipoComida);
    return a;
}

void mostrar_restaurante(cadastro a) {
    printf("\n----------------------------------------\n");
    printf("Nome: %s\n", a.nome);
    printf("Endereco: %s\n", a.endereco);
    printf("Preco medio: %.2f\n", a.precoMedio);
    printf("Tipo de comida: %s\n", a.tipoComida);
    printf("----------------------------------------\n");
}

void mostrar_dados(cadastro a[], int tamanho) {
    for (int i = 0; i < tamanho; i++) 
    {
        printf("\nRestaurante [%d]", i + 1);
        mostrar_restaurante(a[i]);
    }
}

void mostrar_por_preco(cadastro a[], int tamanho, float minimo, float maximo) {
    int encontrou = 0;
    for (int i = 0; i < tamanho; i++) 
    {
        if (a[i].precoMedio >= minimo && a[i].precoMedio <= maximo)     
        {
            mostrar_restaurante(a[i]);
            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("\nNenhum restaurante encontrado nessa faixa de preco.\n");
    }
}

void mostrar_por_tipo(cadastro a[], int tamanho, char tipo[]) {
    int encontrou = 0;

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(a[i].tipoComida, tipo) == 0) {
            mostrar_restaurante(a[i]);
            encontrou = 1;
        }
    }

    if (encontrou == 0) {
        printf("\nNenhum restaurante encontrado com esse tipo de comida.\n");
    }
}

void limpar_enter(char texto[]) {
    texto[strcspn(texto, "\n")] = '\0';
}