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

/*Crie uma estrutura para descrever restaurantes. Os membros devem armazenar o nome, o endereço, o preço médio e o tipo de comida.
- Crie uma função que obtém os dados de uma estrutura restaurante pelo teclado e a retorna.
- Crie uma função que recebe uma estrutura restaurante como parâmetro e escreve seus dados na tela.
- Crie uma função que recebe um vetor de estruturas restaurante e a quantidade de restaurantes válidos no vetor como parâmetros e os imprime na tela.
- Crie uma função que recebe um vetor de estruturas restaurantes, a quantidade de restaurantes válidos no vetor e valores mínimo e máximo de preço como parâmetros. A função deve imprimir os restaurantes com valor médio de preço nesse intervalo.
- Crie uma função que recebe um vetor de estruturas restaurantes, a quantidade de restaurantes válidos no vetor e um tipo de comida como parâmetros. A função deve imprimir os restaurantes com tipo de comida desse tipo.
- Crie um programa principal que crie uma matriz de 50 estruturas restaurante; pergunte a quantidade de restaurantes a serem lidos; leia os dados desses restaurantes no vetor; mostre os dados dos restaurantes lidos; pergunte uma faixa de valores de preço; mostre os restaurantes com preço médio nessa faixa; pergunte um tipo de comida; mostre os restaurantes com esse tipo de comida.*/

typedef struct {
    char nome[100];
    char endereco[200];
    float precoMedio;
    char tipoComida[50];
}cadastro;

cadastro receber_dados ();
cadastro mostrar_dados(cadastro a);


int main() {
    cadastro restalrante;
    
    restalrante = receber_dados();
    
    mostrar_dados(restalrante);

    return 0;
}


cadastro receber_dados (){
    cadastro a;

    printf("\nInforme o nome do restalrante:");
    fgets(a.nome,100,stdin);

    printf("\nInforme o endereço do restalrante:");
    fgets(a.endereco,200,stdin);
    
    printf("\nQual o preço medio:");
    scanf("%f",&a.precoMedio);

    getchar();//usei para limpar o \n
    printf("\nInforme o tipo de comida:");
    fgets(a.tipoComida,50,stdin);

    return a;
}

cadastro mostrar_dados(cadastro a){
    system("clear");
    printf("\n========== Restalrantes cadastrados ===========");
    printf("\nNome: %s",a.nome);
    printf("Endereço: %s",a.endereco);
    printf("Preço medio: %.2f",a.precoMedio);
    printf("\nTipo de comida: %s",a.tipoComida);
}