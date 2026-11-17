#include "prova.h"
#include <stdio.h>
#include <stdlib.h>

// ============================================================================
// QUESTÃO 1 (30%)
// Crie uma função que recebe uma Fila e inverte a ordem de todos os seus 
// elementos utilizando OBRIGATORIAMENTE uma Pilha como estrutura auxiliar.
//
// Casos especiais:
// - Se a fila estiver vazia ou for nula, a função não deve fazer nada.
//
// Restrições:
// - Proibido acessar os ponteiros internos da estrutura (como inicio, fim, prox).
// - Utilize apenas as funções primitivas do TAD (Tipo Abstrato de Dados): 
//   enfileirar, desenfileirar, filaVazia, push, pop, pilhaVazia, criarPilha 
//   e destruirPilha.
// ============================================================================
void inverterFila(Fila *pontFila)
{
    if (pontFila == NULL || filaVazia(pontFila)) {
        printf("Fila vazia ou nula, nada a inverter\n");
        return;
    }

    Pilha *pAux = criarPilha();
    
    // Passo 1: Desenfileira tudo e joga na pilha
    while (!filaVazia(pontFila)) {
        int valor = desenfileirar(pontFila);
        push(pAux, valor);
    }

    // Passo 2: Desempilha e devolve para a fila (a ordem será invertida pelo LIFO)
    while (!pilhaVazia(pAux)) {
        int valor = pop(pAux);
        enfileirar(pontFila, valor);
    }

    destruirPilha(pAux);
    printf("Fila invertida com sucesso!\n");
}


// ============================================================================
// QUESTÃO 2 (30%)
// Crie uma função que recebe um valor e uma Fila. A função deve buscar e 
// remover TODAS as ocorrências desse valor na fila original, mantendo a ordem 
// dos demais elementos. A função deve retornar a quantidade total de remoções.
//
// Casos especiais:
// - Se a fila estiver vazia ou o valor não for encontrado, retorne 0.
//
// Restrições:
// - Você deve usar uma Fila auxiliar para resolver o problema.
// - É proibido acessar os ponteiros internos dos nós (nada de aux->prox).
// - Utilize apenas as funções primitivas de enfileirar e desenfileirar.
// ============================================================================
int removerOcorrenciasFila(int valor, Fila *pontFila)
{
    if (pontFila == NULL || filaVazia(pontFila)) {
        printf("Fila vazia, nenhum elemento removido\n");
        return 0;
    }

    Fila *fAux = criarFila();
    int qtdRemovidos = 0;

    // Esvazia a fila original filtrando o valor indesejado
    while (!filaVazia(pontFila)) {
        int atual = desenfileirar(pontFila);
        
        if (atual == valor) {
            qtdRemovidos++;
        } else {
            enfileirar(fAux, atual); // Guarda apenas os que não serão removidos
        }
    }

    // Devolve os elementos válidos para a fila original
    while (!filaVazia(fAux)) {
        enfileirar(pontFila, desenfileirar(fAux));
    }

    destruirFila(fAux); // Evita vazamento de memória

    if (qtdRemovidos > 0) {
        printf("Foram removidas %d ocorrencia(s) do valor %d\n", qtdRemovidos, valor);
    } else {
        printf("O valor %d não foi encontrado na fila\n", valor);
    }
    
    return qtdRemovidos;
}


// ============================================================================
// QUESTÃO 3 (40%)
// Crie uma função que recebe uma string (vetor de char) e determina se ela é 
// um palíndromo (retorna 1) ou não (retorna 0), utilizando OBRIGATORIAMENTE 
// uma Pilha e uma Fila simultaneamente.
//
// Casos especiais:
// - Uma string vazia (NULL ou '\0' na primeira posição) NÃO é um palíndromo (retorne 0).
// - Uma string contendo 1 único caractere É um palíndromo (retorne 1).
//
// Restrições:
// - Insira os caracteres da string tanto na Pilha quanto na Fila.
// - Faça a validação desenfileirando e desempilhando ao mesmo tempo.
// - Obrigatoriamente limpe (esvazie) e destrua as estruturas auxiliares antes 
//   do return, mesmo se achar o resultado na metade da checagem.
// ============================================================================
int ehPalindromoPilhaFila(char *palavra)
{
    if (palavra == NULL || palavra[0] == '\0') {
        printf("String vazia ou nula, NÃO é palíndromo\n");
        return 0;
    }

    if (palavra[1] == '\0') {
        printf("String com 1 único elemento É um palíndromo\n");
        return 1;
    }

    // Assume-se que o arquivo prova.h possua variações do TAD para char
    Pilha *pAux = criarPilhaChars(); 
    Fila *fAux = criarFilaChars();
    
    // Preenche as estruturas com a string
    int i = 0;
    while (palavra[i] != '\0') {
        pushChar(pAux, palavra[i]);
        enfileirarChar(fAux, palavra[i]);
        i++;
    }

    int deucerto = 1; // Variável de controle: 1 = palíndromo, 0 = não é

    // LIFO (Pilha) vs FIFO (Fila)
    while (!pilhaVazia(pAux) && !filaVazia(fAux)) {
        char doTopo = popChar(pAux);
        char daFrente = desenfileirarChar(fAux);

        if (doTopo != daFrente) {
            deucerto = 0; 
            printf("A string NÃO é um palíndromo\n");
            break; // Otimiza a busca parando na primeira falha
        }
    }

    // Limpeza de segurança caso o while tenha quebrado no 'break'
    while (!pilhaVazia(pAux)) {
        popChar(pAux);
    }
    while (!filaVazia(fAux)) {
        desenfileirarChar(fAux);
    }

    destruirPilhaChars(pAux);
    destruirFilaChars(fAux);

    if (deucerto == 1) {
        printf("A string é sim um palíndromo\n");
        return 1;
    }

    return 0;
}

#include "prova.h"
#include <stdio.h>
#include <stdlib.h>

// ============================================================================
// QUESTÃO 4 (20%)
// Crie uma função que recebe uma Fila original contendo números inteiros. 
// A função deve retirar todos os valores PARES da fila original e transferi-los 
// para uma NOVA fila, que será retornada pela função. Os valores ÍMPARES devem 
// permanecer na fila original, mantendo a ordem exata em que estavam.
//
// Exemplo:
// Fila Original (F1): [Frente] 10, 15, 20, 7, 33, 42 [Fim]
// Chamando F2 = extrairParesFila(F1):
// - F1 passa a ser: [Frente] 15, 7, 33 [Fim]
// - F2 retornada é: [Frente] 10, 20, 42 [Fim]
//
// Casos especiais:
// - Se a fila original estiver vazia, retorne NULL.
// - Se não houver nenhum número par, retorne uma fila vazia e não altere a original.
//
// Restrições:
// - Utilize criarFila() apenas para criar a nova fila de pares e uma fila auxiliar.
// - É estritamente proibido acessar os ponteiros internos (como inicio, fim).
// - Utilize apenas enfileirar, desenfileirar e filaVazia.
// ============================================================================
Fila* extrairParesFila(Fila *pontFila)
{
    if (pontFila == NULL || filaVazia(pontFila)) {
        printf("Fila original vazia ou nula. Retornando NULL\n");
        return NULL;
    }

    Fila *filaPares = criarFila();
    Fila *filaAux = criarFila(); // Para guardar temporariamente os ímpares

    // Passo 1: Esvazia a fila original, separando pares e ímpares
    while (!filaVazia(pontFila)) {
        int valor = desenfileirar(pontFila);
        
        if (valor % 2 == 0) {
            enfileirar(filaPares, valor); // Vai para a fila de retorno
        } else {
            enfileirar(filaAux, valor);   // Fica na fila auxiliar (ímpares)
        }
    }

    // Passo 2: Devolve os ímpares para a fila original, mantendo a ordem
    while (!filaVazia(filaAux)) {
        enfileirar(pontFila, desenfileirar(filaAux));
    }

    destruirFila(filaAux); // Evita vazamento de memória da fila de apoio

    printf("Pares extraidos com sucesso!\n");
    return filaPares;
}


// ============================================================================
// QUESTÃO 5 (30%)
// Crie uma função que recebe uma expressão matemática em formato de string e 
// utiliza uma Pilha para verificar se os parênteses '()', colchetes '[]' e 
// chaves '{}' estão abertos e fechados na ordem correta (balanceados).
// Retorne 1 se a expressão estiver correta e 0 se estiver incorreta.
//
// Exemplo:
// "{ [ ( ) ] }" -> Balanceado (retorna 1)
// "{ [ ( ] ) }" -> Desbalanceado (retorna 0)
//
// Casos especiais:
// - Uma string vazia (NULL ou '\0') deve retornar 0.
// - Se sobrarem caracteres de abertura na pilha ao final da string, retorne 0.
//
// Restrições:
// - Utilize apenas OBRIGATORIAMENTE uma Pilha para resolver o problema.
// - Ignore os números e operadores da string, empilhe apenas os caracteres 
//   de abertura ('{', '[', '(') e desempilhe ao encontrar os de fechamento.
// ============================================================================
int verificaBalanceamentoExpressao(char *expressao)
{
    if (expressao == NULL || expressao[0] == '\0') {
        printf("Expressão vazia ou inválida\n");
        return 0;
    }

    Pilha *p = criarPilhaChars();
    int erro = 0; // 0 = sem erro, 1 = com erro
    int i = 0;

    while (expressao[i] != '\0') {
        char c = expressao[i];

        // Se for caractere de abertura, empilha
        if (c == '(' || c == '[' || c == '{') {
            pushChar(p, c);
        } 
        // Se for caractere de fechamento, verifica o topo
        else if (c == ')' || c == ']' || c == '}') {
            // Se a pilha estiver vazia, tem um fechamento sem abertura
            if (pilhaVazia(p)) {
                erro = 1;
                break;
            }

            char topo = popChar(p);

            // Verifica se o fechamento atual corresponde ao tipo de abertura do topo
            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                erro = 1;
                break; // Ordem incorreta (ex: abre '[' mas fecha com ')')
            }
        }
        i++;
    }

    // Se a string acabou e ainda sobrou algo na pilha, faltou fechar
    if (!pilhaVazia(p)) {
        erro = 1;
    }

    // Rotina obrigatória de limpeza de memória para não perder ponto
    while (!pilhaVazia(p)) {
        popChar(p);
    }
    destruirPilhaChars(p);

    if (erro == 1) {
        printf("Expressão DESBALANCEADA (Erros encontrados)\n");
        return 0;
    } else {
        printf("Expressão PERFEITAMENTE BALANCEADA!\n");
        return 1;
    }
}

#include "prova.h"
#include <stdio.h>
#include <stdlib.h>

// ============================================================================
// QUESTÃO 6 (20%)
// Crie uma função que recebe duas Filas (f1 e f2) e retorna uma NOVA Fila 
// contendo os elementos de ambas intercalados (um de f1, um de f2, etc.).
// 
// Exemplo:
// f1 = [10, 20, 30] e f2 = [1, 2, 3, 4, 5]
// Retorno f3 = [10, 1, 20, 2, 30, 3, 4, 5]
//
// Casos especiais:
// - Se uma fila for maior que a outra, os elementos restantes da fila maior 
//   devem ser simplesmente adicionados ao final da nova fila.
// - As filas originais f1 e f2 devem ficar vazias ao final do processo.
//
// Restrições:
// - Proibido acessar ponteiros internos (inicio, fim, prox).
// - Utilize apenas criarFila, enfileirar, desenfileirar e filaVazia.
// ============================================================================
Fila* intercalarFilas(Fila *f1, Fila *f2)
{
    Fila *f3 = criarFila(); // Fila resultante

    if (f1 == NULL && f2 == NULL) {
        printf("Ambas as filas são nulas.\n");
        return f3;
    }

    // Enquanto houver elementos em PELO MENOS uma das filas
    while (!filaVazia(f1) || !filaVazia(f2)) {
        
        // Desenfileira da f1 e coloca na f3, se não estiver vazia
        if (!filaVazia(f1)) {
            int valor1 = desenfileirar(f1);
            enfileirar(f3, valor1);
        }
        
        // Desenfileira da f2 e coloca na f3, se não estiver vazia
        if (!filaVazia(f2)) {
            int valor2 = desenfileirar(f2);
            enfileirar(f3, valor2);
        }
    }

    printf("Filas intercaladas com sucesso!\n");
    return f3;
}


// ============================================================================
// QUESTÃO 7 (25%)
// Crie uma função que recebe uma Pilha contendo números inteiros desordenados 
// e ORDENA esses elementos em ordem CRESCENTE (o menor valor fica no topo).
//
// Casos especiais:
// - Se a pilha estiver vazia ou tiver apenas 1 elemento, não faça nada.
//
// Restrições:
// - É OBRIGATÓRIO o uso de apenas UMA Pilha auxiliar.
// - Proibido o uso de vetores, listas, arrays ou outras variáveis compostas.
// - Proibido acessar os ponteiros internos (topo, prox).
// - Utilize apenas criarPilha, destruirPilha, push, pop e pilhaVazia.
// ============================================================================
void ordenarPilha(Pilha *pOriginal)
{
    if (pOriginal == NULL || pilhaVazia(pOriginal)) {
        return; // Nada a ordenar
    }

    Pilha *pAux = criarPilha();

    while (!pilhaVazia(pOriginal)) {
        // Retira o elemento do topo da pilha original
        int temporario = pop(pOriginal);

        // Enquanto a pilha auxiliar não estiver vazia E o topo da auxiliar 
        // for MAIOR que o elemento temporário...
        // Nota: Como não podemos espiar o topo sem remover (se não houver função topo()), 
        // fazemos um pop(), verificamos e fazemos push() de volta se necessário.
        while (!pilhaVazia(pAux)) {
            int valorAux = pop(pAux);
            
            if (valorAux > temporario) {
                // Se o valor da auxiliar for maior, devolve para a original
                push(pOriginal, valorAux);
            } else {
                // Se não for, devolve para a auxiliar e para a busca
                push(pAux, valorAux);
                break;
            }
        }
        
        // Coloca o valor temporário na posição correta na pilha auxiliar
        push(pAux, temporario);
    }

    // Ao final do processo, pAux estará ordenada de forma decrescente.
    // Retornamos tudo para pOriginal, invertendo a ordem (ficando crescente no topo).
    while (!pilhaVazia(pAux)) {
        push(pOriginal, pop(pAux));
    }

    destruirPilha(pAux);
    printf("Pilha ordenada com sucesso!\n");
}


// ============================================================================
// QUESTÃO 8 (20%)
// Crie uma função que recebe uma Pilha, extrai e retorna APENAS o valor que 
// está no FUNDO da pilha (o primeiro elemento que foi inserido). 
// Os demais elementos devem permanecer na pilha original, EXATAMENTE na 
// mesma ordem em que estavam.
//
// Exemplo:
// Pilha: [Topo] 10, 20, 30, 40 [Fundo] -> Fundo é o 40.
// Após a execução, a pilha deve ser: [Topo] 10, 20, 30 [Fundo] e retorna 40.
//
// Casos especiais:
// - Se a pilha estiver vazia, retorne -1 (assumindo que só usamos reais positivos, 
//   ou imprima uma mensagem e retorne uma constante de erro).
//
// Restrições:
// - Utilize obrigatoriamente uma Pilha auxiliar.
// - Proibido acessar os ponteiros internos do nó.
// ============================================================================
int removerFundoPilha(Pilha *pOriginal)
{
    if (pOriginal == NULL || pilhaVazia(pOriginal)) {
        printf("Erro: A pilha está vazia!\n");
        return -1; // Código de erro 
    }

    Pilha *pAux = criarPilha();
    
    // Passo 1: Desempilha TUDO da original para a auxiliar.
    // O que estava no topo vai pro fundo, e o que estava no fundo vai pro topo de pAux.
    while (!pilhaVazia(pOriginal)) {
        push(pAux, pop(pOriginal));
    }

    // Passo 2: O elemento que queremos agora está no topo da pAux
    int valorDoFundo = pop(pAux);

    // Passo 3: Devolvemos o restante para a pilha original, restaurando a ordem
    while (!pilhaVazia(pAux)) {
        push(pOriginal, pop(pAux));
    }

    // Passo 4: Limpeza
    destruirPilha(pAux);
    
    printf("Valor do fundo removido: %d\n", valorDoFundo);
    return valorDoFundo;
}

#include "prova.h"
#include <stdio.h>
#include <stdlib.h>

// ============================================================================
// QUESTÃO 9 (20%)
// Crie uma função que recebe duas Filas (f1 e f2) construídas com listas 
// simplesmente ligadas. A função deve CONCATENAR f2 ao final de f1.
// 
// Casos especiais:
// - Se f2 estiver vazia, não faça nada.
// - Se f1 estiver vazia, f1 deve assumir os nós de f2.
//
// Restrições:
// - É ESTRITAMENTE PROIBIDO usar criarNo, malloc, free, enfileirar ou desenfileirar.
// - É ESTRITAMENTE PROIBIDO usar laços de repetição (while/for). A operação 
//   deve ser O(1).
// - Você deve manipular EXCLUSIVAMENTE os ponteiros internos (inicio, fim, prox).
// - Ao final, f2 deve ficar completamente vazia (inicio = NULL e fim = NULL).
// ============================================================================
void concatenarFilasO1(Fila *f1, Fila *f2)
{
    // Se a fila 2 não existe ou está vazia, não há o que concatenar
    if (f2 == NULL || f2->inicio == NULL) {
        return; 
    }

    if (f1 == NULL) {
        return; // Falha de segurança, ponteiro da fila 1 é inválido
    }

    // Caso a fila 1 esteja vazia, ela simplesmente aponta para o início e fim da fila 2
    if (f1->inicio == NULL) {
        f1->inicio = f2->inicio;
        f1->fim = f2->fim;
    } 
    // Caso principal: liga o último nó de f1 ao primeiro nó de f2
    else {
        f1->fim->prox = f2->inicio; // O antigo fim de f1 aponta para o começo de f2
        f1->fim = f2->fim;          // O fim de f1 passa a ser o fim de f2
    }

    // Esvazia a estrutura da fila 2 (sem dar free nos nós, pois agora pertencem a f1)
    f2->inicio = NULL;
    f2->fim = NULL;
    
    // Se a sua struct tiver a variável tamanho, atualize-a assim:
    // f1->tamanho += f2->tamanho;
    // f2->tamanho = 0;
}

// ============================================================================
// QUESTÃO 10 (25%)
// Crie uma função que recebe duas Pilhas (p1 e p2) e verifica se elas são 
// EXATAMENTE IGUAIS (possuem o mesmo tamanho e os mesmos valores na mesma ordem).
// A função deve retornar 1 se forem iguais e 0 se forem diferentes.
//
// Regra de Ouro:
// - Ao final da função, p1 e p2 DEVEM estar no estado EXATAMENTE ORIGINAL, 
//   independentemente se são iguais ou diferentes.
//
// Restrições:
// - Proibido acessar os ponteiros internos (topo, prox).
// - Utilize apenas as primitivas (push, pop, pilhaVazia, criarPilha, destruirPilha).
// - Utilize pilhas auxiliares para realizar a verificação e a reconstrução.
// ============================================================================
int saoPilhasIguais(Pilha *p1, Pilha *p2)
{
    if (p1 == NULL || p2 == NULL) return 0;

    Pilha *aux1 = criarPilha();
    Pilha *aux2 = criarPilha();
    int saoIguais = 1; // Assume verdadeiro até achar uma diferença

    // Compara elemento por elemento desempilhando
    while (!pilhaVazia(p1) && !pilhaVazia(p2)) {
        int v1 = pop(p1);
        int v2 = pop(p2);

        push(aux1, v1);
        push(aux2, v2);

        if (v1 != v2) {
            saoIguais = 0;
            break; // Otimização: paramos na primeira diferença
        }
    }

    // Se o laço terminou, mas uma pilha ainda tem elementos e a outra não, 
    // elas têm tamanhos diferentes.
    if (!pilhaVazia(p1) || !pilhaVazia(p2)) {
        saoIguais = 0;
    }

    // OBRIGATÓRIO: Restauração das pilhas originais. 
    // Como os elementos foram para as auxiliares invertidos, 
    // ao dar pop() da auxiliar e push() na original, a ordem correta é restaurada.
    while (!pilhaVazia(aux1)) {
        push(p1, pop(aux1));
    }
    while (!pilhaVazia(aux2)) {
        push(p2, pop(aux2));
    }

    destruirPilha(aux1);
    destruirPilha(aux2);

    return saoIguais;
}