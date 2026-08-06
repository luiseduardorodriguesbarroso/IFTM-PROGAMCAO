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

typedef struct{
    char nome[20];
    char endereço[250];
    float preçomedio;
    char tipoComida[250];
    
} restalrante;

restalrante cadastrarrestalrante ();
void lerString(char texto[], int tamanho);

int main() {
    restalrante  r = cadastrarrestalrante();

    

    return 0;
}

restalrante cadastrarrestalrante (){
    restalrante piriquito;    

    printf("\nInforme o nome do restalrante: ");
    lerString(piriquito.nome, 20);
    printf("\nInforme endereço: ");
    lerString(piriquito.endereço, 250);
    printf("\nInforme o preço medio de cada prato: ");
    scanf("%d",&piriquito.preçomedio);
    printf("\nInforme tipo de comida: ");
    lerString(piriquito.tipoComida, 250);


    return piriquito;
}

void lerString(char texto[], int tamanho) {
    fgets(texto, tamanho, stdin);
    texto[strcspn(texto, "\n")] = '\0';
}