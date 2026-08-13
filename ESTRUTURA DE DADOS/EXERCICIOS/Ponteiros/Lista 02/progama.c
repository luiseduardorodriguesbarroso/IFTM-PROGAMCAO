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

void mudarpara12 (int *pont){
    *pont = 12;
}
void mudardobro (int *pont){
    *pont = *pont * 2;
}
int main() {
    int cavalo = 99;
    mudarpara12(&cavalo);//troquei para 12
    mudardobro(&cavalo); // dobrei o valor de cavalo
    printf("%d ",cavalo);
    
    return 0;
}