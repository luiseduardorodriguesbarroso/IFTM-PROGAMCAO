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

//Crie uma função em C que recebe como parâmetros um vetor de inteiros e seu tamanho. A função deve mostrar os elementos do vetor na tela.
void mostrarparametros (int inteiros[], int numeros);

int main() {
    
    int numero [] = {1,2,3,4,5,6,7,8,9,10};
    mostrarparametros(&numero[0],10);
    return 0;
}

void mostrarparametros (int inteiros[], int numeros){
    for (int i = 0; i < numeros; i++)
    {
        printf("%5d",inteiros[i]);
    }
    
}