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
    float nuu[10];
    for (int i =0;i<10;i++)
    {
        printf("\n Infrome a nota do aluno %d: ",i);
        scanf("%f",&nuu[i]);
    }
    for (int i =0;i<10;i++)
    {
        printf("\n Nota do aluno %d %10.2f",i,nuu[i]);
    }
}