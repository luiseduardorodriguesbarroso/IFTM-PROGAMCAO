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

void mostrar_pessoa(pessoa x[],int tamanho);

int main() {
    
    printf("|===== Pessoas Cadastradas =====|\n");

    //Metodo de cadastro 01
    pessoa cadastro[100];
    cadastro[0].info_pessoal.idade = 19;
    cadastro[0].altura = 1.63;
    strcpy(cadastro[0].info_pessoal.nome,"Marina lemes");
    strcpy(cadastro[0].info_pessoal.cpf,"123.456.789-10");

    //Metoso de cadastro 02
    cadastro[1] = (pessoa) {{"Eduardo",19,"123.739.586-50"},1.80};//coloquei outra {} para preencher info_pessoal que esta dentro de pessoa e cadastro[n] = (pessoa) e para informar que cadastro na posição n = struct pessoa
    cadastro[2] = (pessoa) {{"josé",21,"736.458.856-79"},1.87};
    cadastro[3] = (pessoa) {{"Paracatu",20,"158.735.123-93"},1.83};
    cadastro[4] = (pessoa) {{"Hugo Santos",21,"156.936.782-62"},1.85};
    cadastro[5] = (pessoa) {{"Yuri",20,"321.538.735-52"},1.87};
    mostrar_pessoa(cadastro,5);
    //Metodo 02 muito mais pratico
    return 0;
}

void mostrar_pessoa(pessoa x[],int tamanho){
    printf("\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf(" Nome: %s\n",x[i].info_pessoal.nome);
        printf(" Idade: %d\n",x[i].info_pessoal.idade);
        printf(" CPF: %s\n",x[i].info_pessoal.cpf);
        printf(" Altura: %.2f\n\n",x[i].altura);  

        /* Ou eu posso usar -> printf(" Nome: %s\n Idade: %d\n CPF: %s\n Altura: %.2f\n\n",
       x[i].info_pessoal.nome,
       x[i].info_pessoal.idade,
       x[i].info_pessoal.cpf,
       x[i].altura);*/  
    }
}

