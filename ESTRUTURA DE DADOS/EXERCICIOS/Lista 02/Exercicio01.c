/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    3º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2026
    Prof. Rafael Orbolato
    Data: 23/02/2026
*/
//===============================================================
//===============================================================
//======== LOCAL PARA DECLARAR AS INCLUDES E VARS GLOBAIS =======
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
char vt[255]; // Minha variavel global para receber dados via texto...


//===============================================================
//==============              STRUCTS              ==============
//===============================================================
struct Restaurante
{
    char nome[250];
    char endereco[250];
    float preco_medio;
    char tipodecomida[250]; 
};
//===============================================================
//==================== PROTOTIPOS ===============================
//===============================================================
void limpa_tl();
struct Restaurante lerRestaurante();
void  mostrarrestaurantes ();


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
struct Restaurante lerRestaurante ()
{
    struct Restaurante r;

    printf("\n Informe o nome do restaurante...: ");
    fgets(r.nome, 250, stdin);

    printf("\n Informe o endereco...: ");
    fgets(r.endereco, 250, stdin);

    printf("\n Informe o preco medio...: ");
    scanf("%f", &r.preco_medio);
    getchar(); // limpa o ENTER

    printf("\n Informe o tipo de comida...: ");
    fgets(r.tipodecomida, 250, stdin);

    return r;
}
//===============================================================
void  mostrarrestaurantes ()
{
    printf("\n ---------------------------------------------- ");
    printf(" ---------- Restaurantes Cadastrados ---------- \n");
    printf("\n ---------------------------------------------- ");
}
//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    limpa_tl(); //Limpa a tela para uma melhor amostragem 
    
    struct Restaurante r1;
    r1 = lerRestaurante();

    printf("\nCadastro realizado com sucesso!\n");

    mostrarrestaurantes();

    //FINALIZAR PROGRAMA
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}