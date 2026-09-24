#include <stdio.h>
#include <stdbool.h>

// Definições de constantes de operação 
#define LIMITE_PICO_CORRENTE 5.0f
#define INCREMENTO_TENSAO 0.01f
#define TEMPO_AMOSTRAGEM 100

// Protótipos das funções
void aplicar_tensao_potenciostato(float tensao);
float ler_corrente_tempo_real(void);
void aguardar_ms(int tempo);
void registrar_log_sistema(const char *mensagem, float valor);
void inverter_varredura(float voltagem_pico);
void iniciar_varredura_potenciodinamica(void);

// Variáveis globais de estado
float tensao_atual = 0.0f;
float corrente_anterior = 0.0f;
bool flag_erro_integridade = false;
float registro_potencial_ruptura = 0.0f;

void iniciar_varredura_potenciodinamica(void)
{
    while (!flag_erro_integridade)
    {
        aplicar_tensao_potenciostato(tensao_atual);

        float corrente_atual = ler_corrente_tempo_real();
        float delta_corrente = corrente_atual - corrente_anterior;

        printf("Tensao: %.2f V | Corrente: %.2f A | Delta: %.2f A\n",
               tensao_atual,
               corrente_atual,
               delta_corrente);

        if (delta_corrente > LIMITE_PICO_CORRENTE)
        {
            registro_potencial_ruptura = tensao_atual;
            flag_erro_integridade = true;

            registrar_log_sistema(
                "ERRO CRITICO: Pico de corrente. Pite detectado.",
                registro_potencial_ruptura
            );

            inverter_varredura(tensao_atual);
            break;
        }

        corrente_anterior = corrente_atual;
        tensao_atual += INCREMENTO_TENSAO;

        aguardar_ms(TEMPO_AMOSTRAGEM);
    }
}

void inverter_varredura(float voltagem_pico)
{
    float tensao_reversa = voltagem_pico;

    printf("\nIniciando inversao de varredura...\n");

    while (tensao_reversa > 0.0f)
    {
        tensao_reversa -= INCREMENTO_TENSAO;

        // Evita ficar ligeiramente abaixo de zero
        if (tensao_reversa < 0.0f)
        {
            tensao_reversa = 0.0f;
        }

        aplicar_tensao_potenciostato(tensao_reversa);

        printf("Varredura reversa: %.2f V\n", tensao_reversa);

        aguardar_ms(TEMPO_AMOSTRAGEM);
    }

    printf("Varredura reversa finalizada.\n");
}

// Mock para simular o potenciostato
void aplicar_tensao_potenciostato(float tensao)
{
    printf("Aplicando tensao: %.2f V\n", tensao);
}

// Mock para simular a leitura de corrente
float ler_corrente_tempo_real(void)
{
    if (tensao_atual > 1.5f)
    {
        // Simula um pico de corrente
        return corrente_anterior + 10.0f;
    }

    // Comportamento normal
    return corrente_anterior + 0.1f;
}

// Mock do atraso
void aguardar_ms(int tempo)
{
    (void)tempo;
    // Em hardware real, implementar o atraso aqui.
}

// Registro de log
void registrar_log_sistema(const char *mensagem, float valor)
{
    printf("\nLOG: %s\n", mensagem);
    printf("Potencial de ruptura: %.2f V\n\n", valor);
}

int main(void)
{
    printf("Iniciando varredura potenciodinamica...\n\n");

    iniciar_varredura_potenciodinamica();

    printf("Teste finalizado.\n");

    return 0;
}