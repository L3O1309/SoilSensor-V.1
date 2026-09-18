#include "arduino_secrets.h"

//  Bibliotecas da IoT Cloud
#include "thingProperties.h"

//  Biblioteca do DHT11
#include "DHT.h"

// Definição dos sensores
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Definição dos pinos analógicos
const int pinoLDR = A0;
const int pinoUmidadeSolo = A1;
const int pinoPh = A3;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(9600);
  delay(1500);

  // Inicializa DHT11
  dht.begin();

  // Inicializa propriedades e conecta na Arduino IoT Cloud
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  //  Debug opcional
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  Serial.println("Sistema Iniciado com sucesso!");
}

void loop() {
  // Mantêm conexão e atualiza as variáveis na nuvem
  ArduinoCloud.update();

  //  Leitura da Insolação (Luminosidade) em porcentagem
  int leituraLDR = analogRead(pinoLDR);
  int insolacaoTemp = map(leituraLDR, 1023, 0, 0, 100);
  insolacaoTemp = constrain(insolacaoTemp, 0, 100);
  insolacao = insolacaoTemp;

  // Leitura da Umidade do Solo em porcentagem
  int leituraSolo = analogRead(pinoUmidadeSolo);
  int umidadeSoloTemp = map(leituraSolo, 1023, 300, 0, 100);
  umidadeSoloTemp = constrain(umidadeSoloTemp, 0, 100);
  umidade_solo = umidadeSoloTemp;

  // Simulação do pH do solo (simulação realizada para a feira de ciências da escola, pois o sensor de pH havia queimado. Todos estavam ciente disso, não houve enganação)
  ph = random(55, 75) / 10.0; 

  // Leitura da Temperatura (°C)
  float tempC = dht.readTemperature();
  if (!isnan(tempC)) {
    temperatura = tempC;
  } else {
    Serial.println(" Erro na leitura do DHT11.");
  }

  // Impressão dos dados no Monitor Serial
  Serial.println("========  Dados dos Sensores  ========");
  Serial.print(" Insolacao: ");
  Serial.print(insolacao);
  Serial.println("%");

  Serial.print("Umidade do Solo: ");
  Serial.print(umidade_solo);
  Serial.println("%");

  Serial.print(" pH: ");
  Serial.println(ph, 2);

  Serial.print(" Temperatura: ");
  Serial.print(temperatura);
  Serial.println("°C");

  Serial.println("==========================================");
  Serial.println();

  delay(5000); //  Delay de 2 segundos entre as leituras
}
