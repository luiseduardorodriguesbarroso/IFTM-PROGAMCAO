#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utilidades.h"

int lerInt()
{
    int numero;
    char valor[255];
    fgets(valor, 255, stdin);
    sscanf(valor, "%d", &numero);
    return numero;
}

float lerFloat()
{
    float numero;
    char valor[255];
    fgets(valor, 255, stdin);
    sscanf(valor, "%f", &numero);
    return numero;
}

void lerString(char texto[], int tamanho)
{
    fgets(texto, tamanho, stdin);
    texto[strlen(texto) - 1] = '\0';
}

void paraMaiuscula(char str[])
{
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
}

void paraMinuscula(char str[])
{
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
}