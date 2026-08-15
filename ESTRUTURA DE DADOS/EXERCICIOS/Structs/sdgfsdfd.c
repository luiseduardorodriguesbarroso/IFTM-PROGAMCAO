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
    char nome[80];
    int idade;
    char cpf[15];
}info_pessoal;
typedef struct{
    info_pessoal info_pessoal;
    float altura;
}pessoa;

void mostrar_pessoa(pessoa x,int tamanho);

int main() {
    
    pessoa marininha;
    marininha.info_pessoal.idade = 19;
    marininha.altura = 1.63;
    strcpy(marininha.info_pessoal.nome,"Marina lemes");
    strcpy(marininha.info_pessoal.cpf,"123.456.789-10");
    mostrar_pessoa(marininha,1);

    return 0;
}

void mostrar_pessoa(pessoa x,int tamanho){

    printf("|===== Pessoas Cadastradas =====|\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf(" Nome: %s\n",x.info_pessoal.nome);
        printf(" CPF: %s\n",x.info_pessoal.cpf);
        printf(" Idade: %d\n",x.info_pessoal.idade);
        printf(" Altura: %.2f\n",x.altura);    
    }
}

