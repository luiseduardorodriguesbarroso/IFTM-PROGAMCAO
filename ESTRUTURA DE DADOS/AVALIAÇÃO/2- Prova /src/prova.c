#include "prova.h"

// Questão 1 (15%)
// Crie uma função que recebe como parâmetro uma lista duplamente ligada e 
// retorna 1 caso a lista seja um palíndromo (a sequência de valores lida do 
// inicio ao fim é exatamente igual à lida do fim ao inicio) e 0 caso contrário.
//
// Casos especiais:
// - Uma lista vazia NÃO é um palíndromo (retorne 0).
// - Uma lista com 1 único elemento É um palíndromo (retorne 1).
//
// Restrições:
// - Proibido criar outra lista, vetor, alocar nós ou alterar a lista original.
// - Proibido chamar obterValorPosicaoLDLI ou qualquer outra função pronta.
// - Percorra a lista manipulando apenas ponteiros de nó.
int ehPalindromoLDLI(ListaDLI *pontLista)
{   
    if(pontLista->tamanho == NULL ){
        printf("NÃO é um palíndromo, Lista esta vazia NULL\n");
        return 0;
    } 
    if (pontLista->tamanho ==  1){
        if ( pontLista->inicio->valor == pontLista->fim->valor) {
            printf("lista com 1 único elemento É um palíndromo\n");
            return 1;
        } else {
            return 0;
        }
    }

    if (pontLista->tamanho > 1){

    NoDLI *aux1 = pontLista->fim;
    NoDLI *aux2 = pontLista->inicio;
    int contador  = 0;
    int deucerto = 0;

        while(contador != pontLista->tamanho ){
            if (aux2->valor == aux1->valor){
                aux1 = aux1->anterior;
                aux2 = aux2->proximo; 
            }
            else {
                printf("A lista não e um palíndromo\n");
                deucerto = 1;
                return 0;
            }
            contador++;
        }

        if (deucerto == 0){
            printf("A lista e sim um palíndromo\n");
            return 1;
        }
    }
    

    // Implemente sua solução aqui
    return 0;
}

// ============================================================================
// QUESTÃO 2 (20%)
// Crie uma função que recebe um valor e uma lista simplesmente ligada.
// A função deve buscar a PRIMEIRA ocorrência desse valor na lista, desligar 
// esse nó de sua posição atual e religá-lo como o novo início da lista, 
// retornando 1.
//
// Casos especiais:
// - Se o valor já estiver no primeiro nó (início), não altere a lista e retorne 1.
// - Se a lista estiver vazia ou o valor não existir na lista, retorne 0.
//
// Restrições:
// - Proibido usar qualquer função pronta da ListaSLI.
// - Proibido criar novos nós (malloc/criarNoSLI), liberar nós (free) ou 
//   apenas trocar os valores (int) dentro dos nós. Manipule os ponteiros!
// ============================================================================
int moverParaInicioLSLI(int valor, ListaSLI *pontLista)
{
    if(pontLista->tamanho == NULL ){
        printf(" Lista esta vazia NULL\n");
        return 0;
    } 
    
    else if(pontLista->inicio->valor == valor){
        printf("o valor já está  no primeiro nó (início), não alterei a lista e retornei 1");
        return 1;
    }

    
    else if (pontLista->tamanho > 1){
        
        NoSLI *aux = pontLista->inicio;
        NoSLI *aux2 = NULL;
        
        while(aux != NULL && aux->valor != valor){
            aux2 = aux;
            aux = aux2->proximo;
        }
        if (aux == NULL){
            return 0;
        }
        aux2->proximo = aux->proximo;
        aux->proximo = pontLista->inicio;
        pontLista->inicio = aux;
        printf("Achei a primeira ocorrencia\n");
        return 1;
    }
}


// ============================================================================
// QUESTÃO 3 (30%)
// Crie uma função que recebe uma posição (0 a tamanho - 1) e uma lista 
// simplesmente ligada. A função deve cortar a lista original naquela posição: 
// todos os nós a partir de 'posicao' até o fim devem ser desligados da lista 
// original e passar a formar uma nova ListaSLI retornada pela função, 
// reaproveitando os próprios nós existentes.
//
// Exemplo:
// L1 = 10 -> 20 -> 30 -> 40 -> 50 -> NULL (tamanho = 5)
// Chamando L2 = dividirListaLSLI(2, L1):
// - L1 passa a ser: 10 -> 20 -> NULL (tamanho = 2)
// - L2 retornada é: 30 -> 40 -> 50 -> NULL (tamanho = 3)
//
// Casos especiais:
// - Casos inválidos (lista vazia, posicao < 0 ou posicao >= tamanho): 
//   não altere a lista original e retorne NULL.
// - Se posicao == 0: L1 deve ficar completamente vazia (inicio = NULL e 
//   tamanho = 0) e L2 leva todos os nós.
//
// Restrições:
// - Você DEVE usar criarListaSLI() apenas para criar a estrutura da nova lista.
// - É estritamente proibido usar outras funções prontas, criar novos nós 
//   (malloc/criarNoSLI), apagar nós (free) ou copiar valores (int).
// ============================================================================
ListaSLI* dividirListaLSLI(int posicao, ListaSLI *pontLista)
{
   if(pontLista == NULL || pontLista->inicio == NULL){
    printf("Lista vazia\n");
    return 0;
   }
   if (posicao > 0 || posicao >= pontLista->tamanho){
    printf("Casos inválidos (lista vazia, posicao < 0 ou posicao >= tamanho)\n");
    return NULL;
   }

   ListaSLI *clone = criarListaSLI();

   if (clone == NULL){
    printf("lista nova, esta vazia\n");
    return NULL;
   }
    NoSLI *aux = pontLista->inicio;
    NoSLI *ultimoClone = NULL;

    for (int i = 0; i<posicao;i++){
        ultimoClone = aux;
        aux = aux->proximo;
    }

    clone->inicio = aux;
    clone->tamanho = pontLista->tamanho - posicao;
    
    if (ultimoClone == NULL){
        pontLista->inicio = NULL;
    }   else {
        ultimoClone->proximo = NULL;
    }
    pontLista->tamanho = posicao;
    return clone;

    /*
    while (aux != NULL) {
        NoSLI *novo = criarNoSLI(aux->valor, NULL);

        if (clone->inicio == NULL) {
            clone->inicio = novo; // Primeiro elemento do clone
        } else {
            ultimoClone->proximo = novo; // Conecta ao final da nova lista
        }

        ultimoClone = novo; // Atualiza o ponteiro do último nó inserido
        aux = aux->proximo;  // Avança na lista original
    }
    clone->tamanho = pontLista->tamanho; 

    return clone;  */
    // Implemente sua solução aqui

}

// ============================================================================
// QUESTÃO 4 (35%)
// Crie uma função que recebe um valor e uma lista duplamente ligada.
// A função deve buscar e remover TODAS as ocorrências desse valor na lista, 
// liberando a memória dos nós removidos (free) e retornando a quantidade 
// total de nós que foram removidos.
//
// Casos especiais:
// - Se a lista estiver vazia ou o valor não for encontrado, retorne 0.
//
// Restrições:
// - Proibido usar as funções prontas da lista (como removerInicioLDLI, 
//   removerFimLDLI ou limparLDLI).
// - Proibido trocar valores (int) entre os nós. Desengate o nó, ajuste os 
//   ponteiros anterior/proximo/inicio/fim, atualize o tamanho e dê free no nó.
// ============================================================================
int removerTodasOcorrenciasLDLI(int valor, ListaDLI *pontLista){
    if (pontLista == NULL || pontLista->inicio == NULL) {
        return 0; // Lista vazia
    }

    int count = 0;
    NoDLI *current = pontLista->inicio;

    while (current != NULL) {
        if (current->valor == valor) {
            NoDLI *toRemove = current;

            // Ajusta os ponteiros dos nós vizinhos
            if (toRemove->anterior != NULL) {
                toRemove->anterior->proximo = toRemove->proximo;
            } else {
                // Se for o primeiro nó, atualiza o início da lista
                pontLista->inicio = toRemove->proximo;
            }

            if (toRemove->proximo != NULL) {
                toRemove->proximo->anterior = toRemove->anterior;
            } else {
                // Se for o último nó, atualiza o fim da lista
                pontLista->fim = toRemove->anterior;
            }

            current = toRemove->proximo; // Avança para o próximo nó
            free(toRemove); // Libera a memória do nó removido
            count++;
            pontLista->tamanho--; // Atualiza o tamanho da lista
        } else {
            current = current->proximo; // Avança para o próximo nó
        }
    }

    return count; // Retorna a quantidade de nós removidos
}
