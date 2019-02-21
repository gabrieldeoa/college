/*
Escreva um módulo para converter uma temperatura da escala Celsius para a escala Fahrenheit.
A fórmula de conversão é F = 1.8 * C + 32, onde F é a temperatura em Fahrenheit e C é a temperatura em Celcius.
Seu módulo deve retornar o valor da temperatura em Fahrenheit. Em seguida, chame este módulo a partir de um módulo main para testar seu programa.
*/

#include <stdio.h>
#include <stdlib.h>

float celsiusParaFahrenheit(float celsius) {
    return (1.8*celsius)+32;
}

main() {
    float celsius, resultado;

    printf("Forneça a temperatura em Celsius: ");
    scanf("%f", &celsius);

    resultado = celsiusParaFahrenheit(celsius);

    printf("%.2f em Celsius é %.2f em Fahrenheit.", celsius, resultado);
}
