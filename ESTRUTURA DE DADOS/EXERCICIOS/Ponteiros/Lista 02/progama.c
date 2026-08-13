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

void mudarpara12 (int *pont);
void mudardobro (int *pont);
void mostrarelementosarray (int *array,int tamanho);


void mudarpara12 (int *pont){
    *pont = 12;
}
void mudardobro (int *pont){
    *pont = *pont * 2;
}
void mostrarelementosarray (int *array,int tamanho){
    if (array != NULL)
    {
        for (int i = 0; i < tamanho; i++)
        {
            printf("%5d",array[i]);
        }
    } else 
        printf("Array vazio!");
}
int main() {
    int cavalo = 99;
    int array [7] = {1,2,3,4,5,6,7};
    int *ponteiro = array;
    ponteiro [0] = 14; //trocanta o valor do primeiro elemento para 14
    
    mudarpara12(&cavalo);//troquei para 12
    mudardobro(&cavalo); // dobrei o valor de cavalo
    mostrarelementosarray(array,7); //não coloca o & pq o propio array já e um endereço então não precisa do &
    
    //printf("%d ",cavalo);
    //printf("%d ",*ponteiro);
    
    return 0;
}