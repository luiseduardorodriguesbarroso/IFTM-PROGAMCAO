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

void mostrararray (int *pont,int tamanho);


void mostrararray (int *pont,int tamanho){
   if (pont != NULL){
        for (int i = 0; i < tamanho; i++)
        {
            printf("%5d",pont[i]);
        }
   } else 
        printf("Deu merda, seu bosta!"); 
}

int main() {
    /*int abacaxi [5] = {1,2,3,4,5};
    int *ponteiro = abacaxi;
    printf("%d\n",*ponteiro);*/

    int melao = 179;
    int *fruteira = &melao;
    int *cozinha = fruteira;
    printf("%d\n",melao);
    printf("%d\n",*fruteira);
    printf("%d\n",*cozinha);
    *cozinha = 171;
    printf("%d\n",*cozinha);
    printf("%d\n",melao);
    printf("%d\n",*fruteira);
    //mostrararray(abacaxi,5);
    return 0;
}