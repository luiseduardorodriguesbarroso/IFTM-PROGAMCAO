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
Veiculo* encontra_veiculo_disponivel(Veiculo frota[],int tamanho_frota,float peso_necessario);
float processa_lote_pacotes(Veiculo *v,float pacotes[],int num_pacotes,int *pacotes_sucesso);


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

/*QUESTÃO 3: Vetores de Estruturas e Retorno de Ponteiros
   Valor: 25%

   Crie uma função que busca em uma frota
   o primeiro veículo disponível capaz de transportar
   uma carga específica.

   A função recebe:
   - vetor frota;
   - tamanho da frota;
   - peso necessário.

   Deve retornar:
   - ponteiro para o primeiro veículo com espaço suficiente;
   - NULL caso nenhum veículo consiga transportar.

   Espaço livre:
    - capacidade_maxima - carga_atual
*/

Veiculo* encontra_veiculo_disponivel(Veiculo frota[],int tamanho_frota,float peso_necessario){
    
    if (frota == NULL || tamanho_frota <= 0 || peso_necessario < 0){
        printf("Avisso: Informaçoes Invalidas, verifique a sua frota!");
        return NULL;
    }
    for (int i = 0; i < tamanho_frota; i++)
    {
        float espaço_livre = frota[i].capacidade_maxima - frota[i].carga_atual;
        if (espaço_livre >= peso_necessario){ //verificando se o espaço livre e maior que o peso necessário
            return &frota[i]; //retornando o endereçõ do veiculo e para a busca
        }
    }
    return NULL;
}

/*QUESTÃO 4: Vetores de Variáveis Simples e
   Modificação em Lote
   Valor: 30%

   Crie uma função que tenta carregar vários pacotes
   em um único veículo.

   A função recebe:
   - ponteiro para o veículo;
   - vetor de pacotes;
   - quantidade de pacotes;
   - ponteiro para pacotes_sucesso.

   Funcionamento:
   - carregar pacote por pacote;
   - começar do índice 0;
   - interromper ao ultrapassar a capacidade máxima;
   - o pacote que exceder NÃO deve ser carregado;
   - os próximos pacotes também não.

   Atualizar:
   - pacotes_sucesso com a quantidade carregada.

   Retornar:
   - soma dos pesos carregados com sucesso.*/

float processa_lote_pacotes(Veiculo *v,float pacotes[],int num_pacotes,int *pacotes_sucesso){
    if (v == NULL || pacotes == NULL || num_pacotes <= 0 ||pacotes_sucesso == NULL){
        if(pacotes != NULL){
            *pacotes_sucesso = 0;
        }
        return 0;
    }
    float peso_total_caregado = 0;
    *pacotes_sucesso = 0;

    for (int i = 0; i < num_pacotes; i++) //caregando pacote por pacote
    {
        float simulação_carga = v->carga_atual + pacotes[i];

        if (simulação_carga <= v->capacidade_maxima){ //verificando se ultrapassou a capacidade max
            v->carga_atual = simulação_carga;
            peso_total_caregado += pacotes[i];
            (*pacotes_sucesso)++;
        }   else {
            break;
        }
    }
    return peso_total_caregado; //Soma de todos os pesos caregados
}

int main() {
    Veiculo *v;
    
    return 0;
}