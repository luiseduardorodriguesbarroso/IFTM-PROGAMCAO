/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    3º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2026
    Prof. Rafael Orbolato
    Data: 07/06/2026
*/
//===============================================================
//===============================================================
//======== LOCAL PARA DECLARAR AS INCLUDES E VARS GLOBAIS =======
//===============================================================
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
//===============================================================
//==============         VARIAVEIS GLOBAIS         ==============
//===============================================================



//===============================================================
//==============               STRUCTS               ==============
//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==================== PROTOTIPOS ===============================
//===============================================================
void limpa_tl();
void gerador_aleatorio (int *vt,int tamanho, int maximo, int minimo);
void mostrar_valoresvt (int *nene, int tamanho);
void cal_media (int *vt,int tamanho);
void mostrar_maior_menor(int *vt, int tamanho);
int buscar_valor(int *vt, int tamanho, int valor_buscado);
int ordem_crescente(int *vt, int tamanho);

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpa_tl()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}
//===============================================================
void gerador_aleatorio (int *vt,int tamanho, int maximo, int minimo)
{
    srand(time(NULL));
    for(int i = 10; i < tamanho; i++)
    {
        *(vt + i) = minimo + (rand() % (maximo - minimo + 1));
    }
}
//===============================================================
void mostrar_valoresvt (int *nene, int tamanho)
{
    printf("\n");
    for (int  i = 0; i < tamanho; i++)
    {
        printf("%5d",*(nene+i));
    }
}
//===============================================================
void cal_media (int *vt,int tamanho)
{
    float media = 0;
    for(int i = 0; i < tamanho; i++)
    {
        media = *(vt + i) + media;
    }
    media = media / tamanho;
    printf("\n\nA media dos valores do meu vetor eh: %.2f",media);
}
//===============================================================
void mostrar_maior_menor(int *vt, int tamanho) 
{
    int maior = *vt; 
    int menor = *vt; 
    for (int i = 1; i < tamanho; i++) //o laço começa do 1 para pegar a posição 0 como referencia 
    {
        if (*(vt + i) > maior) 
        {
            maior = *(vt + i); 
        }
        if (*(vt + i) < menor) 
        {
            menor = *(vt + i); 
        }
    }
    printf("\nO maior valor encontrado foi: %d", maior);
    printf("\nO menor valor encontrado foi: %d", menor);
}
//===============================================================
int buscar_valor(int *vt, int tamanho, int valor_buscado) 
{
    for (int i = 0; i < tamanho; i++) 
    {
        if (*(vt + i) == valor_buscado) 
        {
            return i; 
        }
    }
    return -1;
}
//===============================================================
int ordem_crescente(int *vt, int tamanho) 
{
    for (int i = 0; i < tamanho - 1; i++) 
    {
        //se o número atual for MAIOR que o próximo, a fila bagunçou!
        if (*(vt + i) > *(vt + i + 1))
        {
            return 0; //falso (não está em ordem crescente)
        }
    }
    return 1; //esta em ordem crescente
}
//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    limpa_tl(); //Limpa a tela para uma melhor amostragem 
    int vt[20] = {1,3,7,9,11,15,27,0,73,85};
    
    gerador_aleatorio(vt,20,100,1);// Preenche a segunda metade com números aleatórios
    
    printf("Valores do Vetor:"); // Mostra todos os valores na tela
    mostrar_valoresvt(vt,20);
    
    cal_media(vt,20); // Calcula e imprime a média
    
    mostrar_maior_menor(vt,20);// Encontra e imprime o maior e o menor

    // ==========================================
    // NOVA PARTE: Solicita e busca um valor
    // ==========================================
    int numero_procurado;
    int posicao;
    
    printf("\n\nDigite um numero inteiro para buscar no vetor: ");
    scanf("%d", &numero_procurado);
    
    posicao = buscar_valor(vt, 20, numero_procurado);
    
    if (posicao != -1) {
        printf("-> O valor %d foi encontrado no indice %d!\n", numero_procurado, posicao);
    } else {
        printf("-> O valor %d NAO existe no vetor.\n", numero_procurado);
    }
    // ==========================================
    // NOVA PARTE: Verifica e imprime a ordem
    // ==========================================
    if (ordem_crescente(vt, 20) == 1) {
        printf("\n-> Resultado da analise: O vetor ESTA em ordem crescente.\n");
    } else {
        printf("\n-> Resultado da analise: O vetor NAO esta em ordem crescente.\n");
    }
    //FINALIZAR PROGRAMA
    printf("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}