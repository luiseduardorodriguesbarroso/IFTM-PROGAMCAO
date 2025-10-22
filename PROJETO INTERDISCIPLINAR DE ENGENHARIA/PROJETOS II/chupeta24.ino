/*
 * PROJETO INTERDISCIPLINAR DE ENGENHARIA - PROJETOS 2
 * * Lógica: APENAS SEGUIDOR DE LINHA PRETA
 * * VERSÃO COM BOTÃO DE PAUSE/RESUME
 * * ADAPTADO PARA PONTE H L9110S
 * * CORRIGIDO: Lógica de curva invertida (para virar na direção correta)
 */

// #include <Ultrasonic.h> // Não precisamos mais desta biblioteca

// --- DEFINIÇÕES DE HARDWARE ---
// Ultrasonic ultrasonic(8, 7); // Ultrassom desativado
const int sensorEsq = 12;    // Sensor frontal esquerdo
const int sensorDir = 11;    // Sensor frontal direito
const int botao = 2;         // Botão de Start/Pause

// --- DEFINIÇÕES DOS MOTORES (para L9110S) ---
const int motorEsq_PWM = 5; // Conectar no A-IA (Velocidade)
const int motorEsq_DIR = 6; // Conectar no A-IB (Direção)
const int motorDir_PWM = 9; // Conectar no B-IA (Velocidade)
const int motorDir_DIR = 10; // Conectar no B-IB (Direção)

// --- PARÂMETROS DE COMPORTAMENTO ---
const int velocidadeMedia = 120;
const int velocidadeGiroCurva = 80; // (Mantido 80 para permitir a curva)
const int tempoInicial = 500;

// --- Parâmetros de desvio (desativados) ---
// const int velocidadeDesvio = 160;
// const int distanciaObstaculo = 15;
// const int tempoGiro90 = 800;
// const int tempoLado = 1000;
// const int tempoFrente = 1200;

// --- VARIÁVEIS GLOBAIS DE ESTADO ---
// bool estaDesviando = false; // Desativado
bool roboPausado = false;
int ultimoEstadoBotao = HIGH;
long ultimoTempoBotao = 0;
long debounceDelay = 50;

// ============ SETUP ============
void setup() {
  pinMode(sensorEsq, INPUT);
  pinMode(sensorDir, INPUT);
  pinMode(botao, INPUT_PULLUP);
  
  pinMode(motorEsq_PWM, OUTPUT);
  pinMode(motorEsq_DIR, OUTPUT);
  pinMode(motorDir_PWM, OUTPUT);
  pinMode(motorDir_DIR, OUTPUT);

  Serial.begin(9600);
  parar();

  Serial.println("Robô pronto (L9110S). Aguardando botão para INICIAR...");

  while (digitalRead(botao) == HIGH) { 
    parar();
    delay(10);
  }

  Serial.println("Botão pressionado! Iniciando em 1 segundo...");
  delay(tempoInicial);
  Serial.println("Robô ATIVO. Pressione o botão novamente para PAUSAR.");

  ultimoEstadoBotao = digitalRead(botao);
  ultimoTempoBotao = millis();
}

// ============ LOOP PRINCIPAL ============
void loop() {

  // --- 1. LÓGICA DE PAUSAR/RETOMAR ---
  int estadoBotao = digitalRead(botao); 
  if (estadoBotao == LOW && ultimoEstadoBotao == HIGH && (millis() - ultimoTempoBotao) > debounceDelay) { 
    roboPausado = !roboPausado;
    ultimoTempoBotao = millis(); 
    if (roboPausado) {
      parar(); 
      Serial.println("Robô PAUSADO. Pressione para retomar.");
    } else {
      Serial.println("Robô RETOMANDO...");
    }
  }
  ultimoEstadoBotao = estadoBotao; 

  // --- 2. VERIFICA ESTADOS GLOBAIS ---
  // if (estaDesviando) return; // Desativado
  if (roboPausado) {
    parar();
    return;
  }

  // --- 3. LÓGICA DE OPERAÇÃO ---

  // --- VERIFICAÇÃO DE OBSTÁCULO (Desativada) ---
  /*
  int cm = ultrasonic.read(CM);
  if (cm > 0 && cm <= distanciaObstaculo) {
    estaDesviando = true;
    desviarObstaculo();
    procurarLinha();
    estaDesviando = false;
    return;
  }
  */

  // --- LÓGICA DE SEGUIR LINHA (LOW = LINHA PRETA) ---
  bool esqNaLinha = (digitalRead(sensorEsq) == LOW);
  bool dirNaLinha = (digitalRead(sensorDir) == LOW);

  if (esqNaLinha && dirNaLinha) {
    // Caso 1: Centralizado (Ambos na linha PRETA/LOW)
    frente(velocidadeMedia, velocidadeMedia);
  } 
  else if (!esqNaLinha && dirNaLinha) {
    // Caso 2: Saiu para a esquerda (Esq vê BRANCO/HIGH, Dir vê PRETO/LOW)
    // PRECISA VIRAR PARA ESQUERDA
    curvaEsquerda(); // <<< CORRIGIDO
  } 
  else if (esqNaLinha && !dirNaLinha) {
    // Caso 3: Saiu para a direita (Esq vê PRETO/LOW, Dir vê BRANCO/HIGH)
    // PRECISA VIRAR PARA DIREITA
    curvaDireita(); // <<< CORRIGIDO
  } 
  else {
    // Caso 4: Perdeu a linha (Ambos veem BRANCO/HIGH)
    parar();
  }
}

// ============ FUNÇÕES DE MOVIMENTO (L9110S) ============

void motorEsquerdo(int velocidade, bool direcao) {
  analogWrite(motorEsq_PWM, velocidade);
  digitalWrite(motorEsq_DIR, direcao);
}

void motorDireito(int velocidade, bool direcao) {
  analogWrite(motorDir_PWM, velocidade);
  digitalWrite(motorDir_DIR, direcao);
}

#define FRENTE LOW  
#define RE HIGH     

void frente(int velEsq, int velDir) {
  motorEsquerdo(velEsq, FRENTE);
  motorDireito(velDir, FRENTE);
}

void parar() {
  motorEsquerdo(0, FRENTE);
  motorDireito(0, FRENTE);
}

// --- Funções de desvio (desativadas) ---
/*
void frentePorTempo(int velocidade, int duracao) {
  frente(velocidade, velocidade);
  delay(duracao);
}

void girarEsquerdaEixo(int duracao) {
  Serial.println("Girando Esquerda (Eixo)");
  motorEsquerdo(velocidadeDesvio, RE);
  motorDireito(velocidadeDesvio, FRENTE);
  delay(duracao);
}

void girarDireitaEixo(int duracao) {
  Serial.println("Girando Direita (Eixo)");
  motorEsquerdo(velocidadeDesvio, FRENTE);
  motorDireito(velocidadeDesvio, RE);
  delay(duracao);
}
*/

// --- Funções de curva (usadas pelo seguidor de linha) ---
void curvaEsquerda() {
  motorEsquerdo(velocidadeGiroCurva, FRENTE);
  motorDireito(velocidadeMedia, FRENTE);
}

void curvaDireita() {
  motorEsquerdo(velocidadeMedia, FRENTE);
  motorDireito(velocidadeGiroCurva, FRENTE);
}


// ============ FUNÇÕES DE LÓGICA (Desativadas) ============
/*
void desviarObstaculo() {
  Serial.println("Obstáculo detectado! Iniciando desvio...");
  parar();
  delay(200);
  girarEsquerdaEixo(tempoGiro90);
  parar();
  delay(200);
  frentePorTempo(velocidadeDesvio, tempoLado);
  parar();
  delay(200);
  girarDireitaEixo(tempoGiro90);
  parar();
  delay(200);
  frentePorTempo(velocidadeDesvio, tempoFrente);
  parar();
  delay(200);
  girarDireitaEixo(tempoGiro90);
  parar();
  delay(200);
  Serial.println("Manobra de desvio concluída.");
}

void procurarLinha() {
  Serial.println("Procurando a linha...");
  frente(velocidadeMedia, velocidadeMedia);
  
  // Continua andando para frente enquanto AMBOS os sensores estiverem
  // fora da linha (vendo BRANCO/HIGH)
  while (digitalRead(sensorEsq) == HIGH && digitalRead(sensorDir) == HIGH) {
    delay(10); 
  }
  
  // Se saiu do loop, é porque um dos sensores encontrou a linha (LOW)
  Serial.println("Linha encontrada! Andando mais um pouco...");
  frentePorTempo(velocidadeMedia, 200); // Anda por mais 200ms
  
  parar();
  delay(100);
  Serial.println("Retomando percurso.");
}
*/