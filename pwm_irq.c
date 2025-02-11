#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definindo constantes para configurações do PWM e posições do servo
#define PWM_PIN     22            // Pino GPIO utilizado para o PWM
#define DIV         25            // Divisor de clock para reduzir a frequência do PWM
#define WRAP        (uint16_t)100000  // Valor máximo do contador PWM para 50 Hz: 125 MHz / (50 Hz * 25) = 100.000

// Definição dos ciclos ativos para cada posição do servo
#define ANG_180     12000         // WRAP * 0,12 = 12000 para aproximadamente 180 graus
#define ANG_90      7350          // WRAP * 0,0735 = 7350 para aproximadamente 90 graus
#define ANG_0       2500          // WRAP * 0,025 = 2500 para aproximadamente 0 graus

// Incremento para movimentação suave entre posições
#define STEP        25            // Quantidade de incremento para cada ajuste de posição (100.000 / 4000)

int main() {
    // Inicializa a comunicação serial para debug
    stdio_init_all();

    // Configura o pino GPIO como saída PWM
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);

    // Obtém o slice PWM associado ao pino
    uint slice = pwm_gpio_to_slice_num(PWM_PIN);

    // Configura o divisor de clock e o valor de wrap
    pwm_set_clkdiv(slice, DIV);       // Define o divisor de clock
    pwm_set_wrap(slice, WRAP);        // Define o valor máximo do contador

    // Habilita o PWM no slice configurado
    pwm_set_enabled(slice, true);

    // Move o servo para a posição de 180º por 5 segundos
    pwm_set_gpio_level(PWM_PIN, ANG_180);
    sleep_ms(5000);

    // Move o servo para a posição de 90º por 5 segundos
    pwm_set_gpio_level(PWM_PIN, ANG_90);
    sleep_ms(5000);

    // Move o servo para a posição de 0º por 5 segundos
    pwm_set_gpio_level(PWM_PIN, ANG_0);
    sleep_ms(5000);

    // Prepara variáveis para movimentação cíclica
    uint level = ANG_0;               // Inicia a partir da posição 0º
    bool positive_direction = true;   // Inicia o movimento em direção positiva

    // Movimentação cíclica entre 0º e 180º
    while (true) {
        if (positive_direction) {
            level += STEP;   // Se o sentido é positivo, incrementa o nível
        } else {
            level -= STEP;   // Caso contrário, decrementa o nível
        }

        // Define o nível PWM no pino para ajustar o servo
        pwm_set_gpio_level(PWM_PIN, level);

        // Verifica os limites para inverter a direção
        if (level <= ANG_0) {
            positive_direction = true;   // Chegou na posição 0º, muda para direção positiva
        }
        if (level >= ANG_180) {
            positive_direction = false;  // Chegou na posição 180º, muda para direção negativa
        }

        // Atraso para suavizar a movimentação do servo
        sleep_ms(10);
    }
}
