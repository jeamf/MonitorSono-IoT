#include <WiFi.h>
#include <PubSubClient.h>

// Configurações da rede Wi-Fi
const char* ssid = "SEU WIFI";
const char* password = "sua senha";

// Configurações do broker MQTT
const char* mqttServer = "broker.hivemq.com"; 
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

// Definições do sensor PIR
const int pirPin = 13;

// Variáveis para registrar o movimento durante o sono


// Duração do intervalo de tempo para medir o sono (em minutos)
const unsigned long intervaloTempo = 10; // 1 minuto

// Intervalo de tempo para verificar se a pessoa dormiu (em segundos)
const unsigned long intervaloVerificacao = 30; // 1 minuto

unsigned long startTime = 0;
unsigned long totalSleepTime = 0;
unsigned long totalMovementTime = 0;
unsigned long totalAwakeTime = 0;
unsigned long lastMovementTime = 0;
bool isSleeping = true;
int numAwakenings = 0;

void setup() {
  Serial.begin(115200);
  pinMode(pirPin, INPUT_PULLUP);

  // Conectar ao Wi-Fi
  setup_wifi();
  
  // Configurar o cliente MQTT
  client.setServer(mqttServer, mqttPort);
  reconnect();

  // Iniciar o tempo
  startTime = millis();
  lastMovementTime = millis() / 1000; // Inicializa o tempo desde o último movimento
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando ao ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao broker MQTT...");
    if (client.connect("mqtt-explorer-54e8b090")) { 
      Serial.println("Conectado");
      
    } else {
      Serial.print("Falha, rc=");
      Serial.print(client.state());
      Serial.println(" Tentando novamente em 5 segundos");
      delay(5000);
    }
  }
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long currentTime = (millis() - startTime) / 1000 / 60; // Convertendo para minutos

  if (currentTime < intervaloTempo) {
    // Lê os dados do sensor PIR
    int val = digitalRead(pirPin);

    // Verifica se há movimento detectado
    if (val == HIGH) {
      if (isSleeping) {
        isSleeping = false;
        Serial.println("Você acordou!");
        numAwakenings++;
      }
      totalMovementTime += (millis() / 1000 - lastMovementTime); // Atualiza o tempo total de movimento
      lastMovementTime = millis() / 1000; // Atualiza o tempo desde o último movimento
    } else {
      if (!isSleeping) {
        if ((millis() / 1000 - lastMovementTime) > intervaloVerificacao) { // Verifica se não houve movimento no intervalo de verificação
          isSleeping = true;
          Serial.println("Você dormiu!");
        }
      }
    }

    // Atualizar tempos totais
    if (isSleeping) {
      totalSleepTime++;
    } else {
      totalAwakeTime++;
    }

    delay(1000); // Aguarda 1 segundo antes de verificar novamente
  } else {
    // Calcula e envia as estatísticas do sono
    sendSleepStats();

    // Aguarda para sempre após o intervalo de tempo especificado
    while (true) {
      delay(1000);
    }
  }
}

void sendSleepStats() {
  // Calcula as estatísticas do sono
  float efficiency = (float)totalSleepTime / (totalSleepTime + totalAwakeTime) * 100;


  String topic = "INTERNETCOISAS";
  String payload = "\n"
                   "  Tempo de Sono: " + String(totalSleepTime) + " segundos,\n"
                   "  Tempo Acordado: " + String(totalAwakeTime) +" segundos,\n"
                   "  Tempo de Movimento: " + String(totalMovementTime) + " segundos,\n" +
                   "  Vezes que acordou: " + String(numAwakenings) +" vezes,\n"
                   "  Qualidade do Sono: " + String(efficiency) + "%\n" +
                   "";


  if (client.publish(topic.c_str(), payload.c_str())) {
    Serial.println("Dados do sono enviados via MQTT:");
    Serial.println(payload);
  } else {
    Serial.println("Falha ao enviar dados do sono via MQTT");
  }
}
