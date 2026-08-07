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

/*Crie uma função que receba como parâmetro uma matriz 3x3 de inteiros.  A função deve mostrar essa matriz na tela no formato:
	A	B	C
	D	E	F
	G	H	I
 */
void mostrarmatrizabcd(int matriz[3][3], int min, int max);

int main() {
    int mt[3][3];
	srand(time(NULL));
	mostrarmatrizabcd(mt,2,20);
    return 0;
}

void mostrarmatrizabcd(int matriz[3][3], int min, int max){
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			 matriz[i][j] = rand() % (max - min + 1) + min;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%5d",matriz[i][j]);
		}
		printf("\n");
	}
	
}