/*===================================
NOME: lUÍS EDUARDO RODRIGUES BARROSO
CURSO:  ENGENHARIA DA COMPUTA  O
CPF:    ***.***.***-**
DATA:   01/07/2025
*/
//===================================

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
#define TAM1 10
#define TAM2 10

//VOU ADICIONAR MINHAS FUN  ES PARA QUE N O OCORRA ALGUM ERRO NA HORA DE CHAMAR MINHAS FUNÇÕES...
//===============================================================================================
void quadrado(char m[][TAM2], int lin, int col);//mostra a figura op = 1
void triangulodpa(char m[][TAM2], int lin, int col);//mostra a figura op = 2
void triangulodpc(char m[][TAM2], int lin, int col);//mostra a figura op = 3
void triangulodsa(char m[][TAM2], int lin, int col);//mostra a figura op = 4
void triangulodsc(char m[][TAM2], int lin, int col);//mostra a figura op = 5
int existe(int m[][TAM2], int linAtual, int colAtual, int valor);
void preencherMatrizInteiros(int m[][TAM2], int lin, int col);
void mostrarMatrizInteiros(int m[][TAM2], int lin, int col);    //MOSTRA MATRIZ PARA MEU CLIENTE...
void pesquisarnum(int m[][TAM2], int lin, int col); //PESQUISA O NUMERO QUE MEU CLIENTE INFORMOU NA MATRIZ...
void menu_pesquisa();
void menuFig(char m[][TAM2], int lin, int col); //MOSTRA O MENU PARA MEU CLIENTE...
void pouse();
void limpa_tl();
//===============================================================================================

// ==================== FUN  ES DA OP = 1 =========================

void quadrado(char m[][TAM2], int lin, int col)
{
    printf("\n--- QUADRADO DE ASTERISCOS ---\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}

void triangulodpa(char m[][TAM2], int lin, int col)
{
    printf("\n--- TRIANGULO PRINCIPAL E ABAIXO ---\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}

void triangulodpc(char m[][TAM2], int lin, int col)
{
    printf("\n--- TRIANGULO PRINCIPAL E ACIMA ---\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j >= i) printf("%c ", m[i][j]);
            else printf("  ");
        }
        printf("\n");
    }
}

void triangulodsa(char m[][TAM2], int lin, int col)
{
    printf("\n--- TRIANGULO SECUNDARIA E ABAIXO ---\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j >= col - i - 1) printf("%c ", m[i][j]);
            else printf("  ");
        }
        printf("\n");
    }
}

void triangulodsc(char m[][TAM2], int lin, int col)
{
    printf("\n--- TRIANGULO SECUNDARIA E ACIMA ---\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j <= col - i - 1) printf("%c ", m[i][j]);
            else printf("  ");
        }
        printf("\n");
    }
}

// ==================== FUN  ES DA OP = 2  =========================

int existe(int m[][TAM2], int linAtual, int colAtual, int valor)
{
    for (int i = 0; i <= linAtual; i++)
    {
        int limite_j = (i == linAtual) ? colAtual : TAM2;
        for (int j = 0; j < limite_j; j++)
        {
            if (m[i][j] == valor)
            {
                return 1;
            }
        }
    }
    return 0;
}

void preencherMatrizInteiros(int m[][TAM2], int lin, int col)
{
    int num;
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            do
            {
                num = rand() % 100 + 1; //rand vai gerar somente numeros entre 1 e 100...
            } while (existe(m, i, j, num));
            m[i][j] = num;
        }
    }
}

void mostrarMatrizInteiros(int m[][TAM2], int lin, int col)
{
    printf("\nMATRIZ GERADA:\n");
    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%3d ", m[i][j]);    //mostra Matriz gerada randomicamente...
        }
        printf("\n");
    }
}

void pesquisarnum(int m[][TAM2], int lin, int col)
{
    int numero, achou = 0;

    printf("Digite o numero a pesquisar: ");    //receberar o numero que meu cliente deseja pesquisar...
    fflush(stdin);
    scanf("%d", &numero);

    for (int i = 0; i < lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (m[i][j] == numero)
            {
                printf("Numero encontrado na posicao [%d][%d]\n", i, j);    //mostra para meu cliente onde esta o numero que ele informou [i][j]...
                achou = 1;
            }
        }
    }
    if (!achou)
    {
        printf("Numero nao encontrado na matriz.\n");   //numero que meu cliente pesquisou n o existe dentro da matriz...
    }
}

void menu_pesquisa()
{
    int matriz[TAM1][TAM2] = {0};
    int lin, col;
    char resposta = 's';

    do
    {
        printf("Informe o tamanho para a matriz quadrada (2 a 9): "); //recebera o tamanho da minha matriz quadrada...
        fflush(stdin);
        scanf("%d", &lin);
    } while (lin < 2 || lin > 9);

    col = lin;

    preencherMatrizInteiros(matriz, lin, col);
    mostrarMatrizInteiros(matriz, lin, col);

    while (resposta == 's' || resposta == 'S')
    {
        pesquisarnum(matriz, lin, col);
        printf("Deseja pesquisar outro numero? (s/n): ");   //validar se meu cliente deseja pesquissar algum valor na matriz...
        fflush(stdin);
        scanf(" %c", &resposta);

        while (resposta != 's' && resposta != 'S' && resposta != 'n' && resposta != 'N')
        {
            printf("Resposta invalida...Digite apenas 's' ou 'n': ");   //alerta meu cliente para que digite sim ou n o ...
            fflush(stdin);
            scanf(" %c", &resposta);
        }
    }
}

void menuFig(char m[][TAM2], int lin, int col)
{
    int op = 0;
    while (op != 6)
    {
        printf("\n==============================\n");
        printf("   MENU FIGURAS DE ASTERISCOS\n");
        printf("==============================\n");
        printf("1) Quadrado de asteriscos\n");
        printf("2) Triangulo diagonal principal e abaixo\n");
        printf("3) Triangulo diagonal principal e acima\n");
        printf("4) Triangulo diagonal secundaria e abaixo\n");
        printf("5) Triangulo diagonal secundaria e acima\n");
        printf("6) Voltar ao menu principal\n");
        printf("Escolha uma opcao (1 a 6): ");
        fflush(stdin); //limpa o LIXO de memoria do meu codigo antes dele ler a op que meu cliente digitou...
        scanf("%d", &op);

        limpa_tl();  //LIMPA A TELA SOMENTE NO WHINDOWS

        if (op == 1)
        {
            quadrado(m, lin, col);
        }
        else if (op == 2)
        {
            triangulodpa(m, lin, col);
        }
        else if (op == 3)
        {
            triangulodpc(m, lin, col);
        }
        else if (op == 4)
        {
            triangulodsa(m, lin, col);
        }
        else if (op == 5)
        {
            triangulodsc(m, lin, col);
        }
        else if (op == 6)
        {
            printf("Voltando ao menu principal...\n");  //volta ao meu menu principal
            pouse(); //pausar tela poi 1 segundo..
        }
        else
        {
            printf("Opcao invalida!\n");
        }
    }
}
//============== FUN  ES BONUS ==============
void pouse()
{
    Sleep(1000); //pausa a tela por 1 segundo...
}

void limpa_tl()
{
    system("cls");  //LIMPA TELA SOMENTE NO WHINDOWS...
}

int main()
{
    //VARIAVEIS
    int op = 0; //NAVEGAR PELO MENU PRINCIPAL...
    char matrizchar[TAM1][TAM2]; //MINHA MATRIZ...
    int lin, col; //TA,MAHO DE LINHA E COLUNS...

    srand(time(NULL)); //VA GERAR NUMEROS ALEATORIOS PARA A MATRIZ DO MEU CLIENRTE...

    while (op != 3)
    {
        printf("\n====================================\n");
        printf("           MENU PRINCIPAL           \n");
        printf("====================================\n");
        printf("1) Figuras com asteriscos\n");
        printf("2) Pesquisar numero na matriz\n");
        printf("3) Finalizar Algoritmo\n");
        printf("Escolha uma opcao (1, 2 ou 3): ");
        fflush(stdin);
        scanf("%d", &op);

        limpa_tl();

        if (op == 1)
        {
            do
            {
                printf("Informe o tamanho para a matriz quadrada (2 a 9): ");
                fflush(stdin);
                scanf("%d", &lin);
            } while (lin < 2 || lin > 9);

            col = lin;

            for (int i = 0; i < lin; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    matrizchar[i][j] = '*';
                }
            }

            menuFig(matrizchar, lin, col);

        }
        else if (op == 2)
        {
            menu_pesquisa();
        }
        else if (op == 3)
        {
            printf("Finalizando o algoritmo...\n");
            pouse();
        }
        else
        {
            printf("Opcao invalida! Tente novamente.\n");
            pouse();
        }
        limpa_tl();
    }
    //FIM DO ALGORITMO
    Sleep(250); //Vai pausar a minha tela por 250 milesegundos...
    printf("\n\nAcabou...Tchau...Obrigado...\n\n");
    return 0;
}