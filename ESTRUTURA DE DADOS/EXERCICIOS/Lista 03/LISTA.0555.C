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

int main ()
{
    system("cls");
    float nuulll;
    printf("\n Informe o valor que vc deseja calcular a raiz quadrada...: ");
    scanf("%f", &nuulll);
    nuulll = sqrt(nuulll);
    printf("\n A raiz quadrada eh: %.2f",nuulll);
}