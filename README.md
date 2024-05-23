O projeto foi desenvolvido em C++ utilizando a IDE Arduino.


Descrição
Uilizarei o ESP32 para monitoramento de sono, combinado com o sensor ECG AD8232 e um buzzer como atuador para alertas. O desenvolvimento será feito na IDE do Arduino, empregando programação específica para integrar hardware e software, incluindo a comunicação via MQTT para transmissão de dados em tempo real para a plataforma Ubidots.


Instalação da IDE do Arduino
Baixar a IDE do Arduino:

Acesse o site oficial do Arduino. Navegue até a seção de downloads e escolha a versão da IDE do Arduino compatível com seu sistema operacional (Windows, macOS ou Linux). Instalar a IDE:

Windows: Execute o instalador baixado e siga as instruções na tela. Certifique-se de instalar todos os drivers necessários durante o processo de instalação. macOS: Abra o arquivo .zip baixado e arraste o aplicativo Arduino para a pasta "Aplicativos". Linux: Descompacte o arquivo baixado e execute o script de instalação. Verificar a Instalação:

Abra a IDE do Arduino para garantir que foi instalada corretamente. Configurando a ESP32 na IDE do Arduino Adicionar o URL do Gerenciador de Placas para a ESP32:

Na IDE do Arduino, vá até "Arquivo" > "Preferências". No campo "URLs Adicionais de Gerenciadores de Placas", insira o seguinte URL para o pacote da ESP32:

https://dl.espressif.com/dl/package_esp32_index.json

Clique em "OK" para salvar.

