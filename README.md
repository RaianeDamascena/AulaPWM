## README - Controle de Servo Motor com Raspberry Pi Pico

## Descrição

Este programa demonstra como controlar um servo motor utilizando PWM no Raspberry Pi Pico. Ele permite posicionar o servo em ângulos fixos (0º, 90º e 180º) e realizar movimentações cíclicas suaves entre esses limites.Com o emprego do módulo PWM (do inglês, Pulse Width Modulation),presente no microcontrolador RP2040, projetei um sistema com a ferramenta Pico SDK para simular o controle do ângulo de um servomotor. Esta simulação contemplará o motor micro servo padrão, presente no simulador de eletrônica online Wokwi.

## Requisitos

Microcontrolador Raspberry Pi Pico W.
Servomotor – motor micro servo padrão – Wokwi.

## Funcionamento

1 . Inicialmente, o servo se posiciona em 180º por 5 segundos.

2 . Depois se move para 90º por 5 segundos.

3 . Em seguida, posiciona-se em 0º por 5 segundos.

4 . O programa entra em um loop infinito movimentando o servo suavemente entre os ângulos de 0º e 180º.

## Link do video de funcionamento 

https://drive.google.com/file/d/1nZPJpgnKDfbnEV-Ot5Tub7UgVuG7b-x7/view?usp=sharing

## Desenvolvedor

Raiane Damascena

email: rai.paixao2012@gmail.com
