O projeto foi desenvolvido em C++ utilizando a IDE Arduino.


## <br> Descrição
Utizarei o ESP32 para monitoramento de sono, combinado com o sensor PIR HC-SR501. O desenvolvimento será feito na IDE do Arduino, empregando programação específica para integrar hardware e software, incluindo a comunicação via MQTT para transmissão de dados em tempo real para o aplicativo MQTT Dashboard.


## <br> Instalação da IDE do Arduino
Baixar a IDE do Arduino:

Acesse o site oficial do Arduino. Navegue até a seção de downloads e escolha a versão da IDE do Arduino.
Instale.


Para configurar a ESP32 na IDE do Arduino Adicionar o URL do Gerenciador de Placas para a ESP32:

Na IDE, vá até "Arquivo" > "Preferências". No campo "URLs Adicionais de Gerenciadores de Placas", insira o seguinte URL para o pacote da ESP32:

https://dl.espressif.com/dl/package_esp32_index.json

Clique em "OK" para salvar.

## <br> Instalar a Placa ESP32:

Navegue até "Ferramentas" > "Placa:" > "Gerenciador de Placas...".
Na janela do Gerenciador de Placas, digite "ESP32" na barra de pesquisa.
Encontre o pacote chamado "esp32 by Espressif Systems" e clique em "Instalar".

## <br> Selecionar a Porta COM:

Vá para "Ferramentas" > "Porta" e selecione a porta COM que aparece com o nome da sua ESP32.

Agora faça o upload do código e preencha as informações de acordo com a sua rede.

## <br> Montagem 
![image](https://github.com/jeamf/MonitorSono-IoT/assets/99516393/a5b2d8a8-3020-4bab-a99d-2535d227ab69)

Voce vai precisar de uma protoboard, um esp32, um sensor PIR HC-SR501 e um cabo usb para alimentação.
(não esqueça de colocar a saida no pino que esta declarado no programa, nesse caso no 13.)

## <br> Configurando o aplicativo MQTT Dashboard.

Para publicar os dados no IoT Cloud usaremos um aplicativo chamado MQTT Dashboard, entre no Google Play do seu celular e baixe.
(Apenas Android).

![image](https://github.com/jeamf/MonitorSono-IoT/assets/99516393/72d7ad51-a825-4b4b-96ab-44bebcc69a9e)

## <br> Criando Servidores

Ao abrir o aplicativo voce encontrara essa pagina em branco.

![image](https://github.com/jeamf/MonitorSono-IoT/assets/99516393/0897ebc7-af35-457e-b5a6-21b80a1e0b68)

Clique no + para adicionar um novo servidor.

Escolha um nome do servidor e o endereço do broker que ira utilizar, nesse caso estou usando HiveMQ broker.hivemq.com, e a porta 1883.

![image](https://github.com/jeamf/MonitorSono-IoT/assets/99516393/568b4316-2a1c-4cb0-bb1d-d815f341ba7d)

Clique no + novamente.

![image](https://github.com/jeamf/MonitorSono-IoT/assets/99516393/a477c07a-fa7c-41d1-a0aa-f662d1334b14)

Selecione o tipo de informação que quer receber, no meu caso é a de Text.

![image](https://github.com/jeamf/MonitorSono-IoT/assets/99516393/1adfb566-5acb-4265-bee6-443b8613afb1)


Defina um nome para o bloco, e coloque o tópico que voce quer publicar (Lembre-se de colocar o mesmo nome que esta no Publish do programa).

Desabilite a publicação e salve.

![image](https://github.com/jeamf/MonitorSono-IoT/assets/99516393/5c3c776e-08f8-4c1a-a298-01c8bc62d82f)


Agora ao terminar o periodo de monitaramento, seus dados serão enviado para o bloco e exibir uma notificação Push no seu celular.

![image](https://github.com/jeamf/MonitorSono-IoT/assets/99516393/2173e827-1c3a-4f2b-9d33-2d1163edabaa)







