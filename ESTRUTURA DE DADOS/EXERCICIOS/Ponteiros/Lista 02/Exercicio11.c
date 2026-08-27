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

// 11) Deseja-se criar um programa em C para manter os dados dos clientes de uma loja.

// a) Crie uma estrutura para representar um cliente, chamada cliente, contendo o nome do cliente (cadeia de caracteres de tamanho 60), o CPF do cliente (cadeia de caracteres de tamanho 16), o telefone do cliente (cadeia de caracteres de tamanho 16) e a idade do cliente.

typedef struct  {
    char nome[60];
    char cpf[15];
    char phone[16]; 
    char idade[5];   
}cliente;

// b1) Crie uma função que obtém os dados de uma estrutura cliente pelo teclado e a retorna.

char receber_dados(cliente r);

char receber_dados(cliente r){

    printf("\nInforme seu nome: ");
    fgets(r.nome,50,stdin);

    printf("\nCPF: ");
    fgets(r.cpf,15,stdin);

    printf("\nTelefone: ");
    fgets(r.phone,16,stdin);

    printf("\nIdade: ");
    fgets(r.idade,5,stdin);

}

// b2) Crie uma função que obtém os dados de uma estrutura cliente pelo teclado e a retorna por referência via um parâmetro do tipo ponteiro.

void receber_dados_viapont(cliente *r); //Uso void pq eu não precisso retornar nada pois eu estou alterando no endereçõ da struct

void receber_dados_viapont(cliente *r){ 
    
    printf("\nInforme seu nome: ");
    fgets(r->nome,50,stdin);

    printf("\nCPF: ");
    fgets(r->cpf,15,stdin);

    printf("\nTelefone: ");
    fgets(r->phone,16,stdin);

    printf("\nIdade: ");
    fgets(r->idade,5,stdin);
}


// c) Crie uma função que receba uma estrutura cliente como parâmetro via ponteiro e imprima seus dados na tela.

void Mostrar_dados_viapont (cliente *r);

void Mostrar_dados_viapont (cliente *r){
    
    printf("\n---------- Cliente cadastrado com sucesso ----------\n");
    printf("\nNome:%s",r->nome);
    printf("CPF:%s",r->cpf);
    printf("Telefone:%s",r->phone);
    printf("Idade:%s\n",r->idade);
}

// d) Crie uma função que receba um vetor de estruturas cliente via ponteiro e a quantidade de clientes válidos no vetor como parâmetros e os imprime na tela. Use aritmética de ponteiros sem alterar o ponteiro e com o operador seta.

void Mostrar_validadar_pont(cliente *r,int validos);

void Mostrar_validadar_pont(cliente *r,int validos){
    
    if (validos > 0) {
        printf("\n---------- Cliente cadastrado com sucesso ----------\n");
        for (int i = 0; i < validos; i++){
            printf("\nNome:%s",(r+i)->nome);
            printf("CPF:%s",(r+i)->cpf);
            printf("Telefone:%s",(r+i)->phone);
            printf("Idade:%s\n",(r+i)->idade);
        }
    }  else {
        printf("Erro, numero de cadastros informados invalidos!\n");
    } 
}


// e) Crie uma função que receba um vetor de estruturas cliente via ponteiro, a quantidade de clientes válidos no vetor e um CPF de cliente como parâmetros. A função deve retornar a posição no vetor que tem um cliente com esse CPF ou -1 caso ele não exista. Use aritmética de ponteiros sem alterar o ponteiro e sem o operador seta.

void procurar_cpf_novet(cliente *r,int validos,char proc_cpf[15]);

// f) Crie uma função que receba um vetor de estruturas cliente via ponteiro, a quantidade de clientes válidos no vetor, um valor mínimo de idade e um valor máximo de idade como parâmetros. A função deve imprimir os dados de todos os clientes que tiverem idade dentro da faixa recebida como parâmetro. Use aritmética de ponteiros alterando o ponteiro e com o operador seta.

/*g) Crie um programa principal que:

- Crie um vetor de clientes chamado vetClientes para conter 100 clientes.
- Obtenha via teclado o número de clientes que serão lidos no vetor vetClientes
- Obtenha os dados desse número de clientes, guardando-os no vetor vetClientes, usando a função da letra b2)
- Imprima na tela todos os clientes do vetor vetClientes, usando a função da letra d)
- Obtenha via teclado um CPF
- Mostre na tela o cliente com esse CPF ou avise o usuário caso ele não exista, usando a função da letra e)
- Obtenha via teclado uma faixa mínimo/máximo de idades e mostre os clientes do vetor com idade nessa faixa, usando a função da letra f).
*/

int main() {
    cliente x;
    //receber_dados(x);
    receber_dados_viapont(&x);
    //Mostrar_dados_viapont(&x);
    Mostrar_validadar_pont(&x,1);
    return 0;
}