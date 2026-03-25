    /*===============================================================
        CURSO: ENGENHARIA DE COMPUTAÇÃO
        Nome: Luís Eduardo Rodrigues Barroso
        3º PERÍODO - DISCIPLINA DE LINGUAGEM DE PROGRAMAÇÃO 
        1 SEMESTRE 2026
        Prof. Rafael Orbolato
        Data: 25/03/2026
    */
    //===============================================================
    #include <stdio.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    #include <math.h>
    #include <time.h>
    #include <unistd.h>
    #define tam 15 //Minha variavel global que vai fazer com que eu altere o tamanho do meu vetor de forma mais simples 
    //===============================================================
    //==============         VARIAVEIS GLOBAIS         ==============
    //===============================================================
    

    //===============================================================
    //==================== PROTOTIPOS ===============================
    //===============================================================


    //===============================================================
    //============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
    //===============================================================
    void mostrar (int *vt, int tamanho)
    {
        for (int i = 0;i< tamanho;i++)
        {
            printf("Elemento %d: %5d\n",i, *(vt + i));
        }
    }
    //===============================================================
    void limpa_tl()
    {
        #ifdef  _WIN32
        system("cls");
        #else
        system("clear");
        #endif 
    }
    //===============================================================

    //===============================================================

    //===============================================================

    //===============================================================
    //==============  CODIGO PRINCIPAL ==============================
    //===============================================================
    int main()
    {
        limpa_tl();
        //CRIANDO VARIAVEIS 

        int nuu[tam] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

        mostrar(nuu,tam);



        //FINALIZAR PROGRAMA
        printf("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
        return 0;
    }