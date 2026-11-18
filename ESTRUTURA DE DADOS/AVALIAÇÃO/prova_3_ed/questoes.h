#ifndef QUESTOES_H
#define QUESTOES_H 1

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "pilha.h"

void enfileirar_com_limite(int valor, Fila *f, int limite_maximo);

int remover_container_especifico(int id_alvo, Pilha *p_principal);

void acessar_nova_pagina(int id_pagina, Pilha *p_voltar, Pilha *p_avancar);
int clicar_voltar(Pilha *p_voltar, Pilha *p_avancar);
int clicar_avancar(Pilha *p_voltar, Pilha *p_avancar);

#endif