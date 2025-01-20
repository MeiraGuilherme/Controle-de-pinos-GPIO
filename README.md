# Controle-de-pinos-GPIO

Este projeto foi desenvolvido para controlar LEDs RGB e um buzzer conectados ao microcontrolador **RP2040** (Raspberry Pi Pico W) por meio de comandos enviados via **UART** utilizando a ferramenta educacional **BitDogLab**.

## 📋 Requisitos

- Microcontrolador Raspberry Pi Pico W
- Ferramenta educacional **BitDogLab** (versão 6.3)
- Cabo micro-USB para USB-A
- Computador com:
  - **VS Code** configurado com o **Pico SDK**
  - Software de terminal serial, como **PuTTY**

---

## ⚙️ Configuração do Ambiente

1. **Instale o Pico SDK**:
   - Siga o guia oficial para configurar o Pico SDK no seu sistema operacional.

2. **Configure o Projeto**
3. **Compile o Projeto**
4. **Carregue o Código na Pico W**:
   - Coloque a Pico W em modo de bootloader (pressione o botão **BOOTSEL** enquanto conecta ao computador).
   - Copie o arquivo `.uf2` gerado na pasta `build` para a unidade USB que aparecer.

## 🚀 Como Usar

1. **Conecte o Microcontrolador**:
   - Certifique-se de que a Pico W está conectada ao computador via USB.

2. **Abra o Software de Terminal Serial**:
   - Configure o **PuTTY** ou outro software de terminal com:
     - **Porta serial**: Identifique a porta correta no seu sistema.
     - **Baud rate**: 9600.

3. Enviando os Comandos:
   - Digite os comandos a seguir no terminal para controlar os periféricos:
     - `GREEN`: Liga o LED verde (GPIO 11).
     - `BLUE`: Liga o LED azul (GPIO 12).
     - `RED`: Liga o LED vermelho (GPIO 13).
     - `WHITE`: Liga os três LEDs (luz branca).
     - `OFF`: Desliga todos os LEDs.
     - `BUZZER`: Ativa o buzzer (GPIO 21) por 2 segundos.
     - `REBOOT`: Reinicia o microcontrolador.


## 🖋️ Licença

Este projeto está licenciado sob a licença MIT. Consulte o arquivo `LICENSE` para mais informações.
