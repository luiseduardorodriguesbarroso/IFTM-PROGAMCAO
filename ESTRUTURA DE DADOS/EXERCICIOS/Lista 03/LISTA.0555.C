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
void testearray ();


int main ()
{
    testearray();
    

    return 0;
}
void testearray ()
{
    int array[5] = {1,2,3,4,5};
    int *pontero = array; //*pontero = ao primeiro elemento do meu array ou seja = array[0]   
    for (int i=0;i<5;i++)
    {
        printf("%5d",pontero[i]);
    }
}
   void mostrar (int *vt, int tamanho)
    {
        for (int i = 0;i< tamanho;i++)
        {
            printf("Elemento %d: %5d\n",i, *(vt + i));
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