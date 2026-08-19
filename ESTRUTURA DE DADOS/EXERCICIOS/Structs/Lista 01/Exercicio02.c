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

/*2) Crie uma estrutura, com o nome Dieta, para armazenar o nome de uma comida, o peso de uma porção e o número de calorias.
- Crie uma função que obtém os dados de uma estrutura dieta pelo teclado e a retorna.
- Crie uma função que recebe uma estrutura dieta como parâmetro e escreve seus dados na tela.
- Crie uma função que recebe um vetor de estruturas dieta e a quantidade de dietas válidas no vetor como parâmetros e as imprime na tela.
- Crie uma função que recebe um vetor de estruturas dieta, a quantidade de dietas válidas no vetor e valores mínimo e máximo de calorias como parâmetro. A função deve imprimir as dietas com valor de calorias nesse intervalo.
- Crie uma função que recebe um vetor de estruturas dieta, a quantidade de dietas válidas no vetor e um nome de comida como parâmetro. A função deve retornar a posição no vetor que tem uma dieta com essa comida ou -1 caso ela não exista.
- Crie um programa principal que crie uma matriz de 50 estruturas dieta; pergunte a quantidade de dietas a serem lidas; leia os dados dessas dietas no vetor; mostre os dados das dietas lidas; pergunte uma faixa de valores de calorias; mostre as dietas com número de calorias nessa faixa; pergunte um nome de comida; mostre a dieta que tem esse nome caso ela exista no vetor ou informe o usuário caso ela não exista.
*/
typedef struct {
    char name_comida [80];
    float peso;
    float calorias;
}Dieta;


void limpa_tl();
void cadastrar_dieta (Dieta x[]);






int main() {
    
    Dieta a[10];

    cadastrar_dieta(a);
    
    return 0;
}





void cadastrar_dieta (Dieta x[]){
    int tamanho; limpa_tl();
    printf("Infome quantos pratos deseja cadastrar: ");
    scanf("%d",&tamanho);
    limpa_tl();

    for (int i = 0; i < tamanho; i++){
        getchar();
        printf("\nNome do prato [%d]: ",i);
        fgets(x[i].name_comida,80,stdin);
        x[i].name_comida[strcspn(x[i].name_comida, "\n")] = '\0'; //vai remover o \n no final do meu fgets

        printf("\nInforme o peso aproximado do prato %s: ",x[i].name_comida);
        scanf("%f",&x[i].peso);

        printf("\nInforme a sua quantidade de calorias: ");
        scanf("%f",&x[i].calorias);
        limpa_tl();
    }
}

void limpa_tl()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}