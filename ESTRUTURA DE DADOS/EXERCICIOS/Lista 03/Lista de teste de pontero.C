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
#include <assert.h>\
//local de declaração de funções 
void testedeponteiro();
void mostrararray (int *pontero,int tamanho);

int main ()
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    mostrararray(array,10);//Passo o meu array como se fosse o meu ponteiro
    return 0;
}
//local de criação das funções
void mostrararray (int *pontero,int tamanho)
{
    if (pontero != NULL) //Verifica se eu estou passando parametro com valor para minha função
    {
        for (int i=0;i<tamanho;i++)
        {
            printf("%5d",pontero[i]); //Esta mostrando na tela todos os elementos do meu array
        }
    } else 
    {
        printf("\nArray informado e nulo!");
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