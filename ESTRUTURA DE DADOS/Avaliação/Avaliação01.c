/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    2º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2026
    Prof. Rafael Orbolato
    Data: 08/04/2026

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
//==============              STRUCTS              ==============
//===============================================================
typedef struct {
    float latitude;
    float longitude;
} Posicao;
//===============================================================
typedef struct {
    int id_veiculo;
    Posicao atual;
    float capacidade_maxima;
    float carga_atual;
} Veiculo;
//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==================== PROTOTIPOS ===============================
//===============================================================
void limpa_tl();
void limpa_tl();
void inicializa_veiculo(Veiculo *v, int id, float cap_max);
int carrega_veiculo(Veiculo *v, float quantidade_carga, float *carga_rejeitada);
Veiculo* encontra_veiculo_disponivel(Veiculo frota[], int tamanho_frota, float peso_necessario);
float processa_lote_pacotes(Veiculo *v, float pacotes[], int num_pacotes, int *pacotes_sucesso);



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
void inicializa_veiculo(Veiculo *v, int id, float cap_max)
{
    v->id_veiculo = id;
    v->carga_atual = 0.0;
    v->capacidade_maxima = cap_max;
    v->atual.latitude = 0.0;
    v->atual.longitude = 0.0;
}
//===============================================================
int carrega_veiculo(Veiculo *v, float quantidade_carga, float *carga_rejeitada)
{
    float rejeitada=0;
    float cap_max = v->capacidade_maxima;
    float *pontx;
    pontx = &quantidade_carga;
    carga_rejeitada = 0;
    if(quantidade_carga > v->capacidade_maxima)
    {
        rejeitada = quantidade_carga - cap_max;
        
    } else 
    {
        rejeitada = cap_max - quantidade_carga;
        
    }

    return rejeitada;
}
//===============================================================
  
//===============================================================
/*float processa_lote_pacotes(Veiculo *v, float pacotes[], int num_pacotes, int *pacotes_sucesso)
{
    
    return 0;
}*/
//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //limpa_tl(); //Limpa a tela para uma melhor amostragem 
    int *vt;
    int id = 17359476;
    float rejet_carga = 0.0;
   // int ft[3];
  
    
    inicializa_veiculo(vt,id,40);
    carrega_veiculo(vt,15,5);
    //encontra_veiculo_disponivel(frota[50],50,70);

    //FINALIZAR PROGRAMA
    printf("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}

/*
#include "questoes.h"

Instruções Gerais:

-Implemente apenas as funções solicitadas.
-Não altere as assinaturas das funções.
-Não é necessário (nem permitido) o uso de malloc, calloc, realloc ou free
-Não utilize funções de entrada e saída (printf, scanf) dentro das funções solicitadas.
 A correção avaliará o estado final das variáveis na memória.
-Apenas o conteúdo do arquivo questoes.c será avaliado. Use o programa.c (main) para testar 
 suas funções

Considerando as seguintes estruturas:

#include <stdio.h>

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

//ID = a um valor fixo que eu vou escolher...
// carga atual vai ser 0.0;
// Latitude e longitude = 0.0;
    

Questão 1: Ponteiros para Estruturas e Aninhamento (Valor: 20%)
Crie uma função que inicializa os dados de um veículo. A função recebe um ponteiro para um
veículo, seu ID e sua capacidade máxima de carga.
A função deve configurar o ID e a capacidade, definir a carga_atual como 0.0, e inicializar 
as coordenadas da Posicao (latitude e longitude) ambas com o valor 0.0

void inicializa_veiculo(Veiculo *v, int id, float cap_max);


Questão 2: Ponteiros para Variáveis Simples (Valor: 25%)
Crie uma função para carregar um veículo com uma determinada quantidade de carga. A função 
recebe um ponteiro para o veículo, a quantidade de carga a ser inserida, e um ponteiro para
 uma variável simples (carga_rejeitada).
A função deve verificar se a nova carga ultrapassa a capacidade_maxima do veículo.
Se couber totalmente, adicione à carga_atual, defina o conteúdo apontado por carga_rejeitada 
como 0.0 e retorne 1.
Se ultrapassar a capacidade, encha o veículo até o seu limite máximo. A quantidade de carga 
que não coube deve ser armazenada no endereço apontado por carga_rejeitada. Neste caso, a 
função deve retornar 0.

int carrega_veiculo(Veiculo *v, float quantidade_carga, float *carga_rejeitada);


Questão 3: Vetores de Estruturas e Retorno de Ponteiros (Valor: 25%)
Crie uma função que busca em uma frota (um vetor de veículos) o primeiro veículo disponível
 que consiga transportar uma carga específica.
A função recebe o vetor de estruturas frota, o tamanho numérico dessa frota, e o peso_necessario.
A função deve iterar pelo vetor e encontrar o primeiro veículo cujo espaço livre 
(capacidade_maxima - carga_atual) seja maior ou igual ao peso_necessario.
Ao encontrar, a função deve retornar um ponteiro para este veículo específico dentro do vetor.
Se nenhum veículo na frota tiver espaço suficiente, a função deve retornar NULL.

Veiculo* encontra_veiculo_disponivel(Veiculo frota[], int tamanho_frota, float peso_necessario);


Questão 4: Vetores de Variáveis Simples e Modificação em Lote (Valor: 30%)
Crie uma função que tenta carregar uma série de pacotes (um vetor de float com os pesos) em 
um único veículo.
A função recebe um ponteiro para o veículo, o vetor de pacotes, o número total de pacotes e 
um ponteiro para um inteiro (pacotes_sucesso).
A função deve tentar colocar pacote por pacote no veículo (somando à carga_atual), começando 
do índice 0 do vetor.
Se um pacote específico fizer a carga_atual ultrapassar a capacidade_maxima, este pacote 
(e todos os pacotes seguintes no vetor) não devem ser carregados. O laço deve ser interrompido.
O endereço apontado por pacotes_sucesso deve ser atualizado com a quantidade exata de pacotes
 que foram colocados no veículo com sucesso.
A função deve retornar a soma do peso (em float) de todos os pacotes que foram efetivamente 
carregados neste processo.

float processa_lote_pacotes(Veiculo *v, float pacotes[], int num_pacotes, int *pacotes_sucesso);



*/
