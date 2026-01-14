/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: 28/09/2025
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
#include <windows.h>
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();


//===============================================================
//============== LOCAL PARA CRIAR OS MÓDulos DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================
int main()
{
    limpartl(); // Limpa a tela para melhorar a amostragem do codigo

    //VARIAVEIS 
    int v1 [10],v2[5];// Meus 2 vetores para receber valores 
    int i; // Vai ser minha forma de movimentar dendro dos vetores v1 e v2...
    int R1[10],R2[10]; //R1 e R2 irão ser usados como nossos resultantes...

    //RECEBENDO OS VALORES DOS VETORES 
    for(i=0;i<10;i++)
    {
        printf("\nInforme o valor do vetor V1 na posicao [%d]...: ",i);
        fflush(stdin);
        scanf("%d",&v1[i]);

    }
    for(i=0;i<5;i++)
    {
        printf("\nInforme o valor do vetor V2 na posicao [%d]...: ",i);
        fflush(stdin);
        scanf("%d",&v2[i]);

    }    
    //Calculando os valores dos resultantes de R1...
    int soma = 0;//Res vai ser = a soma de tdos os valores do vetor V2 
    for(i=0;i<5;i++)
    {
        soma = soma + v2[i];
    }
    for (i=0;i<10;i++)
    {
        if(v1[i] % 2 == 0)
        {
            soma = v1[i] + soma;
            printf("\n%d",soma);
        }
        else 
        {
            soma = 0;
            printf("\n%d",soma);
        }
    }

    
}