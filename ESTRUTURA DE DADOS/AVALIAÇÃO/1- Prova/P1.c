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

typedef struct {
    float latitude;
    float longitude;
} Posicao;

typedef struct {
    int id_veiculo;
    Posicao atual;
    float capacidade_maxima;
    float carga_atual;
} Veiculo;

//---------------------------------------------------------
void inicializa_veiculo(Veiculo *v, int id, float cap_max);
int carrega_veiculo(Veiculo *v,float quantidade_carga,float *carga_rejeitada);


//---------------------------------------------------------
/*QUESTÃO 1: Ponteiros para Estruturas e Aninhamento
   Valor: 20%

   Crie uma função que inicializa os dados de um veículo.
   A função recebe um ponteiro para um veículo,
   seu ID e sua capacidade máxima de carga.

   A função deve:
   - configurar o ID e a capacidade;
   - definir carga_atual como 0.0;
   - inicializar latitude e longitude com 0.0.*/

void inicializa_veiculo(Veiculo *v, int id, float cap_max){
    v->id_veiculo = id;
    v->capacidade_maxima = cap_max;
    v->carga_atual = 0.0;
    v->atual.latitude = 0.0;
    v->atual.longitude = 0.0;
}

/* QUESTÃO 2: Ponteiros para Variáveis Simples
Valor: 25%

Crie uma função para carregar um veículo com uma
determinada quantidade de carga.

A função recebe:
- um ponteiro para o veículo;
- a quantidade de carga;
- um ponteiro para carga_rejeitada.

Regras:
- Se a carga couber totalmente:
    * adicionar em carga_atual;
    * definir carga_rejeitada como 0.0;
    * retornar 1.

- Se ultrapassar a capacidade:
    * completar até o limite máximo;
    * armazenar o excedente em carga_rejeitada;
    * retornar 0.*/

int carrega_veiculo(Veiculo *v,float quantidade_carga,float *carga_rejeitada){
   
    if (v == NULL || carga_rejeitada == NULL || quantidade_carga < 0){
        return 0;
    }

    float carga_total_prevista = v->carga_atual + quantidade_carga;

    if (quantidade_carga <= v->capacidade_maxima){
        v->carga_atual = carga_total_prevista;
        *carga_rejeitada = 0;
        return 1;
    } else {
        v->carga_atual = carga_total_prevista;
        *carga_rejeitada = carga_total_prevista - v->capacidade_maxima;
        return 0;
    }
}

int main() {
    Veiculo *v;
    float *carga_rejeitada = 0;

    inicializa_veiculo(v,15151515,150);
    carrega_veiculo(v,150,carga_rejeitada);
    
    return 0;
}