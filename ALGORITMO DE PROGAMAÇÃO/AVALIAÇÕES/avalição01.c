/*===================================
NOME: LUÍS EDUARDO RODRIGUES BARROSO
CURSO:  ENGENHARIA DA COMPUTAÇÃO
CPF:    ***.***.***-**
DATA:   22/04/2025
===================================*/
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>
//========================================
int main()
{
    int opc = 0;

    while (opc != 4)
    {
        system("cls");
        printf("=====================================\n");
        printf("           MENU PRINCIPAL            \n");
        printf("=====================================\n");
        printf(" 1 - NUMEROS PRIMOS\n");
        printf(" 2 - LUCRO DE MERCADORIA\n");
        printf(" 3 - CRESCIMENTO POPULACIONAL\n");
        printf(" 4 - FINALIZAR ALGORITMO\n");
        printf("=====================================\n");
        printf("INFORME UMA DAS OPCOES (1,2,3 OU 4): ");
        fflush(stdin);
        scanf("%d", &opc);

        if(opc == 4) 
        {
            system("cls");
            printf("Finalizando o algoritmo...\n");
            Sleep(1000);
        }
        else if (opc == 1) 
        {
            int numero = 0, i, eh_primo = 1;

            system("cls");
            printf("=====================================\n");
            printf("         VERIFICADOR DE PRIMOS       \n");
            printf("=====================================\n");

            while (numero < 1)
            {
                printf("INFORME UM NUMERO POSITIVO: ");
                fflush(stdin);
                scanf("%d", &numero);

                if (numero < 1)
                {
                    printf("NUMERO INVALIDO, DIGITE NOVAMENTE\n");
                }
                else
                {
                    eh_primo = 1; // Assume que é primo

                    if (numero == 1)
                    {
                        eh_primo = 0; // 1 não é primo
                    }
                    else
                    {
                        for (i = 2; i <= numero / 2; i++)
                        {
                            if (numero % i == 0)
                            {
                                eh_primo = 0; // Achou um divisor, não é primo
                            }
                        }
                    }

                    if (eh_primo)
                    {
                        printf("\n-------------------------------------\n");
                        printf("RESULTADO: %d E PRIMO!\n", numero);
                        printf("-------------------------------------\n");
                    } 
                    else
                    {
                        printf("\n-------------------------------------\n");
                        printf("RESULTADO: %d NAO E PRIMO!\n", numero);
                        printf("-------------------------------------\n");
                    }
                }
            }
            printf("\nPressione qualquer tecla para voltar ao menu...");
            getch();
        }
        else if (opc == 2) 
        {
            float custo = -1, venda, lucro, total_compras = 0, total_vendas = 0, total_lucro = 0, perc_lucro;
            int total_mercadorias = 0;
            int lucro_ate_10 = 0, lucro_entre_10_20 = 0, lucro_acima_20 = 0;

            system("cls");
            printf("=====================================\n");
            printf("         LUCRO DE MERCADORIA         \n");
            printf("=====================================\n");
            printf("Informe os dados das mercadorias.\nPara finalizar, digite custo igual a 0.\n");

            while (custo != 0)
            {
                printf("\nINFORME O VALOR DE CUSTO (0 para sair): ");
                fflush(stdin);
                scanf("%f", &custo);

                if (custo == 0)
                    continue; // Não processa, apenas sai do laço

                printf("INFORME O VALOR DE VENDA: ");
                fflush(stdin);
                scanf("%f", &venda);

                if (custo < 0 || venda < 0)
                {
                    printf("VALORES INVALIDOS, DIGITE NOVAMENTE\n");
                    continue;
                }

                lucro = venda - custo;
                perc_lucro = (lucro / custo) * 100;

                total_mercadorias++;
                total_compras += custo;
                total_vendas += venda;
                total_lucro += lucro;

                if (perc_lucro <= 10)
                    lucro_ate_10++;
                else if (perc_lucro > 10 && perc_lucro <= 20)
                    lucro_entre_10_20++;
                else if (perc_lucro > 20)
                    lucro_acima_20++;
            }

            printf("\n=====================================\n");
            if (total_mercadorias == 0)
            {
                printf("Nenhuma mercadoria foi informada.\n");
            }
            else
            {
                printf("TOTAL DE MERCADORIAS: %d\n", total_mercadorias);
                printf("LUCRO DE ATE 10%%: %d\n", lucro_ate_10);
                printf("LUCRO MAIOR QUE 10%% E MENOR OU IGUAL A 20%%: %d\n", lucro_entre_10_20);
                printf("LUCRO ACIMA DE 20%%: %d\n", lucro_acima_20);
                printf("VALOR TOTAL DE COMPRAS: R$ %.2f\n", total_compras);
                printf("VALOR TOTAL DE VENDAS:  R$ %.2f\n", total_vendas);
                printf("VALOR TOTAL DE LUCRO:   R$ %.2f\n", total_lucro);
            }
            printf("=====================================\n");
            printf("\nPressione qualquer tecla para voltar ao menu...");
            getch();
        } 
        else if (opc == 3) 
        {
            float pop_a = 90000000, pop_b = 200000000;
            float taxa_a = 3.0, taxa_b = 1.5;
            int anos = 0;

            system("cls");
            printf("=====================================\n");
            printf("      CRESCIMENTO POPULACIONAL       \n");
            printf("=====================================\n");
            printf("Populacao inicial do pais A: %.0f\n", pop_a);
            printf("Taxa de crescimento anual do pais A: %.1f%%\n", taxa_a);
            printf("Populacao inicial do pais B: %.0f\n", pop_b);
            printf("Taxa de crescimento anual do pais B: %.1f%%\n", taxa_b);

            while (pop_a < pop_b)
            {
                pop_a += pop_a * (taxa_a / 100);
                pop_b += pop_b * (taxa_b / 100);
                anos++;
            }

            printf("\nSerao necessarios %d anos para que a populacao do pais A ultrapasse ou iguale a populacao do pais B.\n", anos);
            printf("Populacao final do pais A: %.0f\n", pop_a);
            printf("Populacao final do pais B: %.0f\n", pop_b);
            printf("=====================================\n");
            printf("\nPressione qualquer tecla para voltar ao menu...");
            getch();
        } 
        else 
        {
            printf("\nOPCAO INVALIDA, DIGITE NOVAMENTE\n");
            Sleep(1000);
        }
    }    
    //FIM DO ALGORITMO
    system("cls");
    printf("\n\nAcabou...Tchau...Obrigado...\n\n");
    return 0;
}