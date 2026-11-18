#include "questoes.h"

// ESSE ARQUIVO EH QUE SERA AVALIADO. 

// RESOLVA AS FUNCOES AQUI

//Questão 1
void enfileirar_com_limite(int valor, Fila *f, int limite_maximo){
    if(f->tamanho == limite_maximo){
        remover(f);
        inserir(valor, f);
    }

    if(f->tamanho < limite_maximo){
        inserir(valor, f);
    }
}

//Questão 2
int remover_container_especifico(int id_alvo, Pilha *p_principal){
    if(p_principal->tamanho == 0){
        return 0;
    }

    Pilha *aux = criarPilha();
    int encontrou = 0;

    while(p_principal->tamanho != 0){
        if(id_alvo == p_principal->topo->valor){
            desempilhar(p_principal);
            encontrou = 1;
        }else{
            empilhar(desempilhar(p_principal), aux);
        }
    }

    while(aux->tamanho != 0){
        empilhar(desempilhar(aux), p_principal);
    }

    free(aux);

    return encontrou;
}

//Questão 3
// A) Ação de digitar uma URL ou clicar em um novo link:
void acessar_nova_pagina(int id_pagina, Pilha *p_voltar, Pilha *p_avancar){
    empilhar(id_pagina, p_voltar);
    limparPilha(p_avancar);
}

// B) Ação de clicar no botão "Voltar":
int clicar_voltar(Pilha *p_voltar, Pilha *p_avancar){
    if(p_voltar->tamanho == 0){
        return 0;
    }else{
        empilhar(desempilhar(p_voltar), p_avancar);
        return 1;
    }
}

// C) Ação de clicar no botão "Avançar":
int clicar_avancar(Pilha *p_voltar, Pilha *p_avancar){
    if(p_avancar->tamanho == 0){
        return 0;
    }else{
        empilhar(desempilhar(p_avancar), p_voltar);
        return 1;
    }
}