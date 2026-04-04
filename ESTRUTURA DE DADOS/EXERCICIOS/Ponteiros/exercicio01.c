/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    3º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2026
    Prof. Rafael Orbolato
    Data: 20/03/2026
*/
//===============================================================
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

//===============================================================
//==============         VARIAVEIS GLOBAIS         ==============
//===============================================================


//===============================================================
//==================== PROTOTIPOS ===============================
//===============================================================
void limpa_tl();
float converter_temperatura(float *temp, int *op);

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
// Função do Exercício 1: Recebe temperatura e operação via ponteiro
//===============================================================
float converter_temperatura(float *temp, int *op)
{
    // Usamos o * para ler o valor que está lá na variável do main
    if (*op == 0) 
    {
        // 0: Celsius para Fahrenheit
        return (*temp * 1.8) + 32.0; 
    } 
    else if (*op == 1) 
    {
        // 1: Fahrenheit para Celsius
        return (*temp - 32.0) * (5.0 / 9.0);
    }
    if (*op < 0 || *op > 1) 
    {
        printf("\n Opcao Invalida! Retornando 0.0\n");
        return 0.0; // Retorna 0.0 para opções inválidas
    }
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    limpa_tl();

    //Criando variaveis 
    int opc = -1;
    float temperatura, resultado;

    //Menu de controle 
    while(opc != 2)
    {
        printf("\n ------------------------ MENU ------------------------ ");
        printf("\n 0- Converter temperatura de Celsius para Fahrenheit");
        printf("\n 1- Converter temperatura de Fahrenheit para Celsius");
        printf("\n 2- Sair do programa");
        printf("\n Informe qual das opcoes vc deseja utilizar...: ");
        scanf("%d", &opc);

        if (opc == 0 || opc == 1)
        {
            printf("\n Informe a temperatura a ser convertida...: ");
            scanf("%f", &temperatura);

            resultado = converter_temperatura(&temperatura, &opc); // Mandando os endereços para a minha fubnção 

            if (opc == 0) 
            {
                printf("\n >> Resultado: %.2f Celsius = %.2f Fahrenheit <<\n", temperatura, resultado);
            } else 
            {
                printf("\n >> Resultado: %.2f Fahrenheit = %.2f Celsius <<\n", temperatura, resultado);
            }
        } 
        else if (opc > 2 || opc < 0)
        {
            limpa_tl();
            printf("\n Opcao Invalida! Tente novamente.\n");
        }
    }    
    //FINALIZAR PROGRAMA
    printf("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}