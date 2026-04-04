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

void testedeponteiro();
void mostrararray (int *pontero,int tamanho);

int main ()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int *pontero = array; //*pontero = ao primeiro elemento do meu array ou seja = array[0]
    mostrararray(pontero,10);
    return 0;
}
void mostrararray (int *pontero,int tamanho)
{
    for (int i=0;i<tamanho;i++)
    {
        printf("%5d",pontero[i]); //Esta mostrando na tela todos os elementos do meu array
    }
} 
void testedeponteiro ()
{
    int cavalo = 99,policarpio = 12;
    int *pont;
    pont = &cavalo;
    printf("\n %d %p",cavalo,pont);
    *pont = 55;
    printf("\n %d %p",cavalo,pont);
    *pont = policarpio;
    printf("\n %d %p",cavalo,pont);

}