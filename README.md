# SoilSensor-V.1
Um projeto criado para o concurso agrinho que envolve robótica com arduino, IoT e programação na linguagem C++.
O projeto consiste em um arduino Uno R4 Wi-Fi, um módulo com sensor ldr, módulo com sensor DHT, sensor de umidade capacitivo e módulo com sensor de pH.
Foram criadas 4 variáveis na aba things do Arduino Cloud, onde atribuimos essas váriaveis ao sketch do projeto. Segue abaixo a configuração das variáveis:
Declaration: insolacao; Variable Type: percentage; Variable Permision: Read Only; Variable Update Policy: On Change;
Declaration: pH; Variable Type: Floating Point Number; Variable Permision: Read Only; Variable Update Policy: On Change;
Declaration: temperatura; Variable Type: Temperature Sensor (°C); Variable Permision: Read Only; Variable Update Policy: On Change;
Declaration: umidade_solo; Variable Type: percentage; Variable Permision: Read Only; Variable Update Policy: On Change;
O protótipo visa a sustentabilidade e tecnologia aplicada no campo. A escolha do Arduino Uno com Wi-Fi foi para possibilitar a integração da IoT em nosso projeto, assim facilitando a leitura das medidas, que podem ser vistas pelo dashboard no aplicativo móvel, o projeto foi testado e se mostra funcional.
Para esconder o circuito do projeto foi realizado a impressão 3d de 3 peças encaixáveis, as quais foram modeladas por mim, as peças tiveram suas medidas calculadas para suportar o circuito e esconder os fios.
