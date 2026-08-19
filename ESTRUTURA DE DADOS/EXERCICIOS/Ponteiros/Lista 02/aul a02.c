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

typedef struct 
{
    int idade;
    char nome[80];
    char cpf[15];
}pessoa;
void somar10 (int *pont);
int main() {
    
    pessoa x;
    x.idade =10;
    somar10(&x.idade);
    printf("%5d\n",x.idade);
    

    return 0;
}

void somar10 (int *pont){
    *pont = *pont + 10;
}