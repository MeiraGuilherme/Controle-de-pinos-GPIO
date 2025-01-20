#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

// Definições de pinos
#define UART_ID uart0
#define BAUD_RATE 9600
#define UART_TX_PIN 0
#define UART_RX_PIN 1
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

// Função para inicializar os GPIOs
void init_gpio() {
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_put(LED_GREEN, 0);

    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_put(LED_BLUE, 0);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_put(LED_RED, 0);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
    gpio_put(BUZZER, 0);
}

// Função para inicializar a UART
void init_uart() {
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_set_hw_flow(UART_ID, false, false);
    uart_set_format(UART_ID, 8, 1, UART_PARITY_NONE);
}

// Função para executar comandos recebidos
void execute_command(char *command) {
    if (strcmp(command, "GREEN") == 0) {
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 0);
    } else if (strcmp(command, "BLUE") == 0) {
        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 0);
    } else if (strcmp(command, "RED") == 0) {
        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 1);
    } else if (strcmp(command, "WHITE") == 0) {
        gpio_put(LED_GREEN, 1);
        gpio_put(LED_BLUE, 1);
        gpio_put(LED_RED, 1);
    } else if (strcmp(command, "OFF") == 0) {
        gpio_put(LED_GREEN, 0);
        gpio_put(LED_BLUE, 0);
        gpio_put(LED_RED, 0);
    } else if (strcmp(command, "BUZZER") == 0) {
        gpio_put(BUZZER, 1);
        sleep_ms(2000);
        gpio_put(BUZZER, 0);
    } else if (strcmp(command, "REBOOT") == 0) {
        watchdog_reboot(0, 0, 0);
    } else {
        printf("Comando desconhecido: %s\n", command);
    }
}

int main() {
    stdio_init_all();
    init_gpio();
    init_uart();

    char command[32];
    int index = 0;

    printf("Sistema inicializado. Aguardando comandos...\n");

    while (true) {
        if (uart_is_readable(UART_ID)) {
            char c = uart_getc(UART_ID);
            if (c == '\n' || c == '\r') {
                command[index] = '\0';
                execute_command(command);
                index = 0;
            } else {
                if (index < 31) {
                    command[index++] = c;
                }
            }
        }
    }

    return 0;
}
