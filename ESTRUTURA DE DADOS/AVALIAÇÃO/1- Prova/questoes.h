/* ============================================================
   INSTRUÇÕES GERAIS

   - Implemente apenas as funções solicitadas.
   - Não altere as assinaturas das funções.
   - Não é necessário (nem permitido) o uso de malloc,
     calloc, realloc ou free.
   - Não utilize funções de entrada e saída
     (printf, scanf) dentro das funções solicitadas.
     A correção avaliará o estado final das variáveis
     na memória.
   - Apenas o conteúdo do arquivo questoes.c será avaliado.
     Use o programa.c (main) para testar suas funções.

   ============================================================

   Considerando as seguintes estruturas:

   #include <stdio.h>

   typedef struct {
       float latitude;
       float longitude;
   } Posicao;

   typedef struct {
       int id_veiculo;
       Posicao atual;
       float capacidade_maxima;
       float carga_atual;
   } Veiculo;

   ============================================================
   QUESTÃO 1: Ponteiros para Estruturas e Aninhamento
   Valor: 20%

   Crie uma função que inicializa os dados de um veículo.
   A função recebe um ponteiro para um veículo,
   seu ID e sua capacidade máxima de carga.

   A função deve:
   - configurar o ID e a capacidade;
   - definir carga_atual como 0.0;
   - inicializar latitude e longitude com 0.0.

   Assinatura da função:

   void inicializa_veiculo(Veiculo *v, int id, float cap_max);

   ============================================================
   QUESTÃO 2: Ponteiros para Variáveis Simples
   Valor: 25%

   Crie uma função para carregar um veículo com uma
   determinada quantidade de carga.

   A função recebe:
   - um ponteiro para o veículo;
   - a quantidade de carga;
   - um ponteiro para carga_rejeitada.

   Regras:
   - Se a carga couber totalmente:
       * adicionar em carga_atual;
       * definir carga_rejeitada como 0.0;
       * retornar 1.

   - Se ultrapassar a capacidade:
       * completar até o limite máximo;
       * armazenar o excedente em carga_rejeitada;
       * retornar 0.

   Assinatura da função:

   int carrega_veiculo(
       Veiculo *v,
       float quantidade_carga,
       float *carga_rejeitada
   );

   ============================================================
   QUESTÃO 3: Vetores de Estruturas e Retorno de Ponteiros
   Valor: 25%

   Crie uma função que busca em uma frota
   o primeiro veículo disponível capaz de transportar
   uma carga específica.

   A função recebe:
   - vetor frota;
   - tamanho da frota;
   - peso necessário.

   Deve retornar:
   - ponteiro para o primeiro veículo com espaço suficiente;
   - NULL caso nenhum veículo consiga transportar.

   Espaço livre:
       capacidade_maxima - carga_atual

   Assinatura da função:

   Veiculo* encontra_veiculo_disponivel(
       Veiculo frota[],
       int tamanho_frota,
       float peso_necessario
   );

   ============================================================
   QUESTÃO 4: Vetores de Variáveis Simples e
   Modificação em Lote
   Valor: 30%

   Crie uma função que tenta carregar vários pacotes
   em um único veículo.

   A função recebe:
   - ponteiro para o veículo;
   - vetor de pacotes;
   - quantidade de pacotes;
   - ponteiro para pacotes_sucesso.

   Funcionamento:
   - carregar pacote por pacote;
   - começar do índice 0;
   - interromper ao ultrapassar a capacidade máxima;
   - o pacote que exceder NÃO deve ser carregado;
   - os próximos pacotes também não.

   Atualizar:
   - pacotes_sucesso com a quantidade carregada.

   Retornar:
   - soma dos pesos carregados com sucesso.

   Assinatura da função:

   float processa_lote_pacotes(
       Veiculo *v,
       float pacotes[],
       int num_pacotes,
       int *pacotes_sucesso
   );

   ============================================================ */