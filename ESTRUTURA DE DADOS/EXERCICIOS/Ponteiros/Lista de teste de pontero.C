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
    typedef  struct cadastro
    {
        char nome[250];
        int idade;
        char CPF[20];
    }cadastro;

    typedef struct aluno
    {
        cadastro dados_pessoais;
        int nt1,nt2,nt3,nt4;
        
    }aluno;

    //local de declaração de funções 
    void testedeponteiro();
    void mostrararray (int *pontero,int tamanho);
    void mostrar_cadastro (char nome[250],int idade, char CPF[20], int nt1, int nt2,int nt3,int nt4);

    int main ()
    {
        int array[10] = {1,2,3,4,5,6,7,8,9,10};
        //mostrararray(array,10);//Passo o meu array como se fosse o meu ponteiro
        
        
        aluno Kaique; //Criei a variavel kaique para guarda os dados de cadastros ele
        strcpy(Kaique.dados_pessoais.nome,"Kaique Morais Batista");
        strcpy(Kaique.dados_pessoais.CPF,"152.000.154-99");
        Kaique.dados_pessoais.idade = 19;
        Kaique.nt1 = 3;
        Kaique.nt2 = 17;
        Kaique.nt3 = 11;
        Kaique.nt4 = 27;

        mostrar_cadastro(Kaique.dados_pessoais.nome,Kaique.dados_pessoais.idade,Kaique.dados_pessoais.CPF,Kaique.nt1,Kaique.nt2,Kaique.nt3,Kaique.nt4);
    }
    //local de criação das funções
    void mostrararray (int *pontero,int tamanho)
    {
        if (pontero != NULL) //Verifica se eu estou passando parametro com valor para minha função
        {
            for (int i=0;i<tamanho;i++)
            {
                printf("%5d",pontero[i]); //Esta mostrando na tela todos os elementos do meu array
            }
        } else 
        {
            printf("\nArray informado e nulo!");
        }
    } 
    void testedeponteiro ()
    {
        int cavalo = 99,policarpio = 12;
        int *pont;
        pont = &cavalo;
        printf("\n %d %p",cavalo,pont);
        *pont = 55;
        printf("\n %d %p",cavalo,pont);
        *pont = policarpio;
        printf("\n %d %p",cavalo,pont);

    }
    void mostrar_cadastro (char nome[250],int idade, char CPF[20], int nt1, int nt2,int nt3,int nt4)
    {
        printf("\n--------------- DADOS DO ALUNO ---------------");
        printf("\nNome: %s\nIdade: %d\nCPF: %s\nNota 01: %d\nNota 02: %d\nNota 03: %d\nNota 04: %d  ",nome,idade,CPF,nt1,nt2,nt3,nt4);
    }