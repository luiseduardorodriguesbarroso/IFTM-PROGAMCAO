/*===============================================================
    CURSO: ENGENHARIA DE COMPUTAÇÃO
    NOME: LUÍS EDUARDO RODRIGUES BARROSO
    1º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: 06/08/2025
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
#define tam 50

//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void limpartl ();
void recebervl_vt (int vt [tam]);
void vl_vt_impar_par (int vt[tam]);
void mostrarvt (int vt[tam]);
void pouse ();

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void limpartl ()
{
    system("cls");
}
//===============================================================
void recebervl_vt (int vt [tam])
{
    int i = 0;
    for (i=0;i<tam;i++)
    {
        printf("Informe o valor do vetor na pocicao [%d]...: ",i);
        fflush(stdin);
        scanf("%d",&vt[i]);
    }
}
//===============================================================
void vl_vt_impar_par (int vt[tam])
{
    void pouse ();
    int i =0;
    printf("\nVALORES PAR DO VETOR\n");
    for (i=0;i<tam;i++)
    {
        if (vt[i] % 2 == 0)
        {
            printf("%5d",vt[i]);
        }
    }
    void pouse ();
    printf("\nVALORES IMPAR DO VETOR\n");
    for (i=0;i<tam;i++)
    {
        if (vt[i] % 2 == 1)
        {
            printf("%5d",vt[i]);
        }
    }
}
//===============================================================
void mostrarvt (int vt[tam])
{
    void pouse ();
    int i = 0;
    printf("\nCONTEUDO DO VETOR\n");
    for (i=0;i<tam;i++)
    {
        printf("%5d",vt[i]);
    }
}
//===============================================================
void pouse ()
{
    Sleep(200);
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int vt[tam];
    
    //INICIALIZAR VARIAVEIS
    limpartl();
    recebervl_vt(vt);
    limpartl();
    pouse();
    mostrarvt(vt);
    vl_vt_impar_par(vt);
    
    
    //FINALIZAR PROGRAMA
    printf("\n\nFinalizando progama...\n");
    Sleep(500);
    printf ("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
    return 0;
}
