/*===============================================================

    CURSO: ENGENHARIA DE COMPUTAÇÃO
    Nome: Luís Eduardo Rodrigues Barroso
    3º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2026
    Prof. Rafael Orbolato
    Data: 11/03/2026
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
struct armazenar
{
    char nome_dieta[250], nome_comida[250];
    float peso, calorias;
};

//===============================================================
//==================== PROTOTIPOS ===============================
//===============================================================
void limpa_tl();
struct armazenar receberdados ();

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
struct armazenar receberdados ()
{
    struct armazenar x;
    
    printf("\n Informe o Nome da sua dieta...: ");
    fgets(x.nome_dieta, 250, stdin);

    printf("\n Informe o nome da Comida...: ");
    fgets(x.nome_comida, 250, stdin);

    printf("\n Informe o Peso de uma porcao em kg...: ");
    scanf("%f", &x.peso);

    printf("\n Informe a quantidade de calorias da porcao...: ");
    scanf("%f", &x.calorias);
    
}
//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    limpa_tl(); //Limpa a tela para uma melhor amostragem 
    receberdados(); // Estou chamando a minha função  para receber os dados e depois processalos...
    
    
    //FINALIZAR PROGRAMA
    printf("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}