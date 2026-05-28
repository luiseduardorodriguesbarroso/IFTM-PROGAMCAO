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