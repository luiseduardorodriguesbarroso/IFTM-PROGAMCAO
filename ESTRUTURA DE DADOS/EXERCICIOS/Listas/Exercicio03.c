/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    3º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2026
    Prof. Rafael Orbolato
    Data: 11/05/2026
*/
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
#include <windows.h>

typedef struct elemento 
{
    int valor;
    struct elemento *proximo;
}elem;
 
elem* criarelemento (int valor)
{
    elem* elementocriado = malloc(sizeof(elem));
    elementocriado->valor = valor;
    return elementocriado;
}

int main()
{

    elem* comeco;
   
    //FINALIZAR PROGRAMA
    printf("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}