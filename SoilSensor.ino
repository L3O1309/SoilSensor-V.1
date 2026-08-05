#include "arduino_secrets.h"

// â Bibliotecas da IoT Cloud
#include "thingProperties.h"

// â Biblioteca do DHT11
#include "DHT.h"

// ð·ï¸ DefiniÃ§Ã£o dos sensores
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// ð·ï¸ DefiniÃ§Ã£o dos pinos analÃ³gicos
const int pinoLDR = A0;
const int pinoUmidadeSolo = A1;
const int pinoPh = A3;

void setup() {
  // â Inicializa a comunicaÃ§Ã£o serial
  Serial.begin(9600);
  delay(1500);

  // â Inicializa DHT11
  dht.begin();

  // â Inicializa propriedades e conecta na Arduino IoT Cloud
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  // â Debug opcional
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  Serial.println("â Sistema Iniciado com sucesso!");
}

void loop() {
  // â MantÃ©m conexÃ£o e atualiza as variÃ¡veis na nuvem
  ArduinoCloud.update();

  // ð âï¸ Leitura da InsolaÃ§Ã£o (Luminosidade) em porcentagem
  int leituraLDR = analogRead(pinoLDR);
  int insolacaoTemp = map(leituraLDR, 1023, 0, 0, 100);
  insolacaoTemp = constrain(insolacaoTemp, 0, 100);
  insolacao = insolacaoTemp;

  // ð± Leitura da Umidade do Solo em porcentagem
  int leituraSolo = analogRead(pinoUmidadeSolo);
  int umidadeSoloTemp = map(leituraSolo, 1023, 300, 0, 100);
  umidadeSoloTemp = constrain(umidadeSoloTemp, 0, 100);
  umidade_solo = umidadeSoloTemp;

  // ð§ª SimulaÃ§Ã£o do pH do solo
  ph = random(55, 75) / 10.0; // Simula pH entre 5.5 e 7.5

  // ð¡ï¸ Leitura da Temperatura (Â°C)
  float tempC = dht.readTemperature();
  if (!isnan(tempC)) {
    temperatura = tempC;
  } else {
    Serial.println("â ï¸ Erro na leitura do DHT11.");
  }

  // ð¥ï¸ ImpressÃ£o dos dados no Monitor Serial
  Serial.println("======== ð¿ Dados dos Sensores ð¿ ========");
  Serial.print("âï¸ Insolacao: ");
  Serial.print(insolacao);
  Serial.println(" %");

  Serial.print("ð± Umidade do Solo: ");
  Serial.print(umidade_solo);
  Serial.println(" %");

  Serial.print("ð§ª pH: ");
  Serial.println(ph, 2);

  Serial.print("ð¡ï¸ Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" Â°C");

  Serial.println("==========================================");
  Serial.println();

  delay(5000); // ð Delay de 2 segundos entre as leituras
}
